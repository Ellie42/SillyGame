//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_TRANSFORM_H
#define SILLYGAME2_TRANSFORM_H


#include <type/Vector3.h>
#include <glm/gtc/quaternion.hpp>

class Transform
{
private:
    Vector3<> m_position;
    glm::quat m_rotation;
    int m_mvpHandle = -1;
public:
    Vector3<>* getPosition();

    void setPosition(float, float, float);
    int getMvpHandle();
    void setMvpHandle(int t_handle);

    glm::quat* getRotation();

    void setRotation(glm::quat t_rotation);
};


#endif //SILLYGAME2_TRANSFORM_H
