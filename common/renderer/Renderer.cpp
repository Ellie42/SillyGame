//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <scene/Director.h>
#include <iostream>
#include <GL/glew.h>
#include "Renderer.h"

Renderer* Renderer::instance()
{
    static Renderer i;

    return &i;
}

void Renderer::init(){
    m_adapter->init();
}

void Renderer::render()
{
    auto* list = Director::instance()->getObjectsInScene();

    m_adapter->clear();

//    static auto* material = new Material;
//    m_adapter->useShader(material->getShader());

    for(auto const &obj : *list){
        auto material = obj->getMaterial();
        auto mesh = obj->getMesh();

        m_adapter->useShader(material->getShader());
        m_adapter->setModelMatrix(obj.get());
        m_adapter->useMaterial(material);
        m_adapter->drawMesh(mesh);

        m_adapter->reset();
    }
}

void Renderer::useAdapter(std::unique_ptr<RenderAdapter> t_adapter)
{
    m_adapter = std::move(t_adapter);
}
