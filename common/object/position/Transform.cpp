//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <glm/gtc/matrix_transform.hpp>
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

void Transform::setRotation(glm::quat t_rotation)
{
    m_rotation = t_rotation;
}

Direction Transform::getDirections()
{
    auto matrix = getTransformMatrix();

    m_directions.right = Vector3<>(matrix[0][0], matrix[1][0], matrix[2][0]);
    m_directions.up = Vector3<>(matrix[0][1], matrix[1][1], matrix[2][1]);
    m_directions.forward = Vector3<>(matrix[0][2], matrix[1][2], matrix[2][2]);

    return m_directions;
}

glm::mat4 Transform::getTransformMatrix()
{
    auto model = glm::mat4(1.0f);

    model = glm::translate(model, (glm::tvec3<float>) m_position);

    model = model * glm::mat4_cast(m_rotation);

    return model;
}

void Transform::rotate(float t_angle, Vector3<> t_axis)
{
    m_rotation = glm::rotate(m_rotation, t_angle, static_cast<glm::vec3>(t_axis));
}
