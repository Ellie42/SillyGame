//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <scene/Director.h>
#include <iostream>
#include <GL/glew.h>
#include "Renderer.h"
#include <component/render/ui/TextRenderer.h>

Renderer* Renderer::instance()
{
    static Renderer i;

    return &i;
}

void Renderer::init()
{
    m_adapter->init();
}

void Renderer::render()
{
    auto* list = Director::instance()->getObjectsInScene();

    m_adapter->clear();

    for (auto const& obj : *list)
    {
        auto renderer = obj->getRenderer();

        if (!renderer)
        {
            continue;
        }

        m_currentObject = obj;

        renderer->accept(this);
    }

    m_adapter->reset();
}

void Renderer::useAdapter(std::unique_ptr<RenderAdapter> t_adapter)
{
    m_adapter = std::move(t_adapter);
}

void Renderer::visit(MeshRenderer* t_renderer)
{
        auto material = t_renderer->getMaterial();
        auto mesh = t_renderer->getMesh();

        m_adapter->useShader(material->getShader());
        m_adapter->useMaterial(material);
        m_adapter->setModelMatrix(m_currentObject.get());
        m_adapter->drawMesh(mesh);
}

void Renderer::visit(TextRenderer* t_renderer)
{
    auto texture = t_renderer->getBitmap();
//    std::cout << "render text" << std::endl;
}
