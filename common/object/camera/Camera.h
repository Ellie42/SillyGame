//
// Created by Sophie Gauthier on 04/01/2018.
//

#ifndef SILLYGAME2_CAMERA_H
#define SILLYGAME2_CAMERA_H


#include <object/position/Transform.h>

class Camera
{
protected:
    Transform m_transform;
public:
    virtual void onUpdate()
    {};

    Transform* getTransform();
};


#endif //SILLYGAME2_CAMERA_H
