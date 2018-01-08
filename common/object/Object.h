//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_OBJECT_H
#define SILLYGAME2_OBJECT_H


#include <object/position/Transform.h>
#include <object/render/Layer.h>

class Object
{
protected:
    short unsigned int m_layer = LAYER_DEFAULT;
    Transform m_transform;
public:
    Transform* getTransform();
    void setLayer(short unsigned int t_layerId);
    short unsigned int getLayer();
};


#endif //SILLYGAME2_OBJECT_H
