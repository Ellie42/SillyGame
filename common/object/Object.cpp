//
// Created by Sophie Gauthier on 08/01/2018.
//

#include "Object.h"

Transform* Object::getTransform()
{
    return &m_transform;
}

void Object::setLayer(short unsigned int t_layerId)
{
    m_layer = t_layerId;
}

short unsigned int Object::getLayer()
{
    return m_layer;
}
