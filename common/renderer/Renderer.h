//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_RENDERER_H
#define SILLYGAME2_RENDERER_H


#include <renderer/adapter/RenderAdapter.h>
#include <memory>
#include <component/render/MeshRenderer.h>
#include "IRendererVisitor.h"

class Renderer : IRendererVisitor
{
private:
    std::unique_ptr<RenderAdapter>  m_adapter;

public:
    static Renderer* instance();

private:
    void visit(TextRenderer* t_renderer) override;

public:
    void init();
    void render();
    void visit(MeshRenderer* t_renderer) override;
    void useAdapter(std::unique_ptr<RenderAdapter>);

    std::shared_ptr<Object> m_currentObject;
};


#endif //SILLYGAME2_RENDERER_H
