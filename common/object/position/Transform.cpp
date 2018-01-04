//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "Transform.h"

Vector3<>* Transform::getPosition()
{
    return &m_position;
}

int Transform::getMvpHandle()
{
    return m_mvpHandle;
}

void Transform::setMvpHandle(int t_handle)
{
    m_mvpHandle = t_handle;
}

void Transform::setPosition(float t_x, float t_y, float t_z)
{
    m_position.x = t_x;
    m_position.y = t_y;
    m_position.z = t_z;
}

glm::quat* Transform::getRotation()
{
    return &m_rotation;
}

void Transform::setRotation(glm::quat t_rotation){
    m_rotation = t_rotation;
}
