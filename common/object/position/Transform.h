//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_TRANSFORM_H
#define SILLYGAME2_TRANSFORM_H


#include <object/position/Vector3.h>
#include <glm/gtc/quaternion.hpp>
#include <object/position/Direction.h>


class Transform
{
private:
    int m_mvpHandle = -1;
    Direction m_directions;
public:
    Vector3<> m_position;
    glm::quat m_rotation;

    Vector3<>* getPosition();

    void setPosition(float, float, float);
    int getMvpHandle();
    void setMvpHandle(int t_handle);

    glm::quat* getRotation();

    void setRotation(glm::quat t_rotation);

    glm::mat4 getTransformMatrix();

    Direction getDirections();

    void rotate(float t_angle, Vector3<> t_axis);
};


#endif //SILLYGAME2_TRANSFORM_H
