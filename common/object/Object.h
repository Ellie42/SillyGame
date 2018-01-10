//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_OBJECT_H
#define SILLYGAME2_OBJECT_H


#include <object/position/Transform.h>
#include <component/render/Layer.h>
#include <component/render/IRendererComponent.h>
#include <memory>
#include <vector>

class Object
{
protected:
    short unsigned int m_layer = LAYER_DEFAULT;
    std::shared_ptr<IRendererComponent> m_renderer = nullptr;
    Transform m_transform;
public:
    Transform* getTransform();

    void setLayer(short unsigned int t_layerId);

    short unsigned int getLayer();

    virtual IRendererComponent* getRenderer();

    void setRenderer(std::shared_ptr<IRendererComponent> t_renderer);

    virtual void onUpdate()
    {};

    virtual void onInstance()
    {};
};


#endif //SILLYGAME2_OBJECT_H
