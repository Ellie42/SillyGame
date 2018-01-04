//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "Triangle.h"
#include <vector>
#include <iostream>
#include <Game.h>

Triangle::Triangle()
{
    auto mesh = std::make_shared<Mesh>();

    static std::vector<float> verts
            {
                    -1.0f, -1.0f, 0.0f,
                    1.0f, -1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
            };

    static std::vector<float> uv{
            0, 0,
            1, 0,
            0.5f, 1
    };

    mesh->setVerts(verts);
    mesh->setUvs(uv);

    setMesh(mesh);

    //TODO get material from material manager to handle cached materials
    static auto material = std::make_shared<Material>();
    static auto texture = std::make_shared<Texture2d>("test-grid.png");

    material->setTexture(0, texture);

    setMaterial(material);

//    m_transform.setRotation(
//            glm::rotate(glm::quat(), 0.6f, glm::tvec3<GLfloat>(0.0f, 1.0f, 0.0f)));
}

void Triangle::onUpdate()
{
    auto time = Game::instance()->getState()->time;

    m_transform.setRotation(
            glm::rotate(glm::quat(), (float) (0.5 * time / 1000), glm::tvec3<GLfloat>(0.0f, 1.0f, 0.0f)));
}
