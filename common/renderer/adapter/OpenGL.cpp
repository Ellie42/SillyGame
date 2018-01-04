//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "OpenGL.h"
#include <renderer/shader/ShaderManager.h>
#include <GL/glew.h>
#include <iostream>
#include <object/GameObject.h>
#include <glm/gtc/matrix_transform.hpp>

void OpenGL::useShader(Shader* t_shader)
{
    //TODO check shadermanager for cached shader id
    if (t_shader->id == 0)
    {
        t_shader->id = ShaderManager::instance()->loadShaderGroup(t_shader->name);
    }

    if (m_currentShader != nullptr && m_currentShader->id == t_shader->id)
    {
        return;
    }

    m_currentShader = t_shader;

    glUseProgram(t_shader->id);
}

void OpenGL::clearShader()
{
    glUseProgram(0);
}

void OpenGL::reset()
{
    clearShader();
    glDisableVertexAttribArray(RenderData::Vertex);
    glDisableVertexAttribArray(RenderData::VertexColour);
    glDisableVertexAttribArray(RenderData::UV);
    glBindTexture(GL_TEXTURE_2D, 0);
    unbindBuffer();
}

void OpenGL::bindData(RenderData t_type, float t_data[], unsigned long t_count)
{
    glBufferData(GL_ARRAY_BUFFER, t_count * sizeof(GLfloat), t_data, GL_STATIC_DRAW);
}

void OpenGL::init()
{
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void OpenGL::bindBuffer(GLuint t_id)
{
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) t_id);
}

void OpenGL::setModelMatrix(GameObject* t_obj)
{
    auto perspective = getPerspectiveMatrix();
    auto camera = getCameraMatrix();
    auto transform = t_obj->getTransform();

    auto model = glm::mat4(1.0f);

    model = glm::translate(model, (glm::tvec3<float>) *transform->getPosition());

    model = model * glm::mat4_cast(*transform->getRotation());

    auto mvp = perspective * camera * model;

    if (transform->getMvpHandle() < 0)
    {
        transform->setMvpHandle(glGetUniformLocation(m_currentShader->id, "MVP"));
    }

    glUniformMatrix4fv(transform->getMvpHandle(), 1, GL_FALSE, &mvp[0][0]);
}

void OpenGL::batch(std::shared_ptr<GameObject> t_obj)
{
    m_batchObjects.push(t_obj);

    for (float vert : *t_obj->getMesh()->getVerts())
    {
        m_batchVerts.insert(m_batchVerts.begin(), vert);
    }
}

void OpenGL::drawBatch()
{
    if (m_batchBuffer == 0)
    {
        glGenBuffers(RenderData::Vertex, &m_batchBuffer);

        bindBuffer((GLuint) m_batchBuffer);
        bindData(RenderData::Vertex, &(m_batchVerts)[0], m_batchVerts.size());
    }

    bindBuffer((GLuint) m_batchBuffer);

    glVertexAttribPointer(RenderData::Vertex, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(RenderData::Vertex);

    int offset = 0;

    while (!m_batchObjects.empty())
    {
        auto object = m_batchObjects.front();
        auto count = object->getMesh()->getVertCount();

        setModelMatrix(object.get());
        glDrawArrays(GL_TRIANGLES, offset, (GLsizei) count);

        offset += count;

        m_batchObjects.pop();
    }

    m_batchVerts.clear();
}

void OpenGL::drawMesh(std::shared_ptr<Mesh> t_mesh)
{
    if (t_mesh->getVertBufferId() == 0)
    {
        GLuint bufferId;
        glGenBuffers(RenderData::Vertex, &bufferId);
        t_mesh->setVertBufferId(bufferId);
    }

    bindBuffer((GLuint) t_mesh->getVertBufferId());
    //TODO only bind data once(unless changed)
    bindData(RenderData::Vertex, &(*t_mesh->getVerts())[0], t_mesh->getVertCount() * 3);
    glVertexAttribPointer(RenderData::Vertex, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(RenderData::Vertex);

    if (!t_mesh->getVertColours().empty())
    {
        bindVertColourBuffer(t_mesh);
    }

    if (!t_mesh->getUvs()->empty())
    {
        bindUvBuffer(t_mesh);
    }

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) t_mesh->getVertCount());
}

void OpenGL::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL::unbindBuffer()
{
    bindBuffer(0);
}

void OpenGL::bindUvBuffer(std::shared_ptr<Mesh> t_mesh)
{
    if (t_mesh->getUvBufferId() == 0)
    {
        GLuint bufferId = 0;
        glGenBuffers(RenderData::UV, &bufferId);
        t_mesh->setUvBufferId(bufferId);
    }

    bindBuffer((GLuint) t_mesh->getUvBufferId());
    //TODO only bind data once(unless changed)
    bindData(RenderData::UV, &(*t_mesh->getUvs())[0], t_mesh->getVertCount() * 2);
    glVertexAttribPointer(RenderData::UV, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(RenderData::UV);
}


void OpenGL::bindVertColourBuffer(std::shared_ptr<Mesh> t_mesh)
{
    if (t_mesh->getColourBufferId() == 0)
    {
        GLuint bufferId = 0;
        glGenBuffers(RenderData::VertexColour, &bufferId);
        t_mesh->setColourBufferId(bufferId);
    }

    bindBuffer((GLuint) t_mesh->getColourBufferId());
    //TODO only bind data once(unless changed)
    bindData(RenderData::VertexColour, &t_mesh->getVertColours()[0], t_mesh->getVertCount() * 3);
    glVertexAttribPointer(RenderData::VertexColour, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(RenderData::VertexColour);
}

void OpenGL::useMaterial(std::shared_ptr<Material> t_material)
{
    auto texture = t_material->getTexture(0);

    if (!texture)
    {
        return;
    }

    if (!texture->isLoaded())
    {
        texture->load();
        std::cout << "Loading texture " << texture->getPath() << std::endl;
    }

    if (texture->getTextureId() == 0)
    {
        GLuint textureId;
        glGenTextures(1, &textureId);
        texture->setTextureId(textureId);

        glBindTexture(GL_TEXTURE_2D, texture->getTextureId());
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->getWidth(), texture->getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE,
                     texture->getData());
        // When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        // Generate mipmaps, by the way.
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glBindTexture(GL_TEXTURE_2D, texture->getTextureId());
}
