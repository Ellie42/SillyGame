//
// Created by Sophie Gauthier on 04/01/2018.
//

#ifndef SILLYGAME2_TOPDOWNCAMERA_H
#define SILLYGAME2_TOPDOWNCAMERA_H


#include <object/camera/Camera.h>

class TopDownCamera : public Camera
{
private:
    float m_cameraSpeed = 5;
public:
    TopDownCamera();
    void onUpdate() override;
};


#endif //SILLYGAME2_TOPDOWNCAMERA_H
