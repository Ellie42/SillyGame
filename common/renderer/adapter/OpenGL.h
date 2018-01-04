//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_OPENGL_H
#define SILLYGAME2_OPENGL_H


#include "RenderAdapter.h"
#include <object/render/Mesh.h>
#include <object/GameObject.h>
#include <GL/glew.h>
#include <queue>

class OpenGL : public RenderAdapter
{
private:
    glm::mat4 m_perspectiveMatrix;
    glm::mat4 m_cameraMatrix;

    void bindData(RenderData t_type, float* t_data, unsigned long t_count);

    Shader* m_currentShader;

    std::queue<std::shared_ptr<GameObject>> m_batchObjects;
    std::vector<GLfloat> m_batchVerts;

    GLuint m_batchBuffer = 0;

public:
    void init() override;

    void useShader(Shader* t_shader) override;

    void clearShader() override;

    void reset() override;

    void bindBuffer(GLuint t_id);

    void clear() override;

    void unbindBuffer();

    void setModelMatrix(GameObject* t_obj) override;

    void bindVertColourBuffer(std::shared_ptr<Mesh> t_mesh);

    void drawMesh(std::shared_ptr<Mesh> t_mesh) override;

    void batch(std::shared_ptr<GameObject> t_object) override;

    void useMaterial(std::shared_ptr<Material> t_material) override;

    void drawBatch() override;

    void bindUvBuffer(std::shared_ptr<Mesh> t_mesh);
};


#endif //SILLYGAME2_OPENGL_H
