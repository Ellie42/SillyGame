//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_RENDERER_H
#define SILLYGAME2_RENDERER_H


#include <renderer/adapter/RenderAdapter.h>
#include <memory>

class Renderer
{
private:
    std::unique_ptr<RenderAdapter>  m_adapter;

public:
    static Renderer* instance();

    void init();
    void render();
    void useAdapter(std::unique_ptr<RenderAdapter>);
};


#endif //SILLYGAME2_RENDERER_H
