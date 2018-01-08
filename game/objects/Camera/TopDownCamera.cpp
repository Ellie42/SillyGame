//
// Created by Sophie Gauthier on 04/01/2018.
//

#include <input/Input.h>
#include <iostream>
#include <time/Time.h>
#include "TopDownCamera.h"

TopDownCamera::TopDownCamera()
{
    m_transform.setPosition(0, 8, -4);
    m_transform.rotate(-3.14f / 4, Vector3<>(1.0f, 0, 0));
}

void TopDownCamera::onUpdate()
{
    auto* input = Input::instance();
    Direction worldDirections;
    Vector3<> velocity;

    if (input->isKeyDown(GLFW_KEY_W))
    {
        velocity += worldDirections.forward;
    }

    if (input->isKeyDown(GLFW_KEY_S))
    {
        velocity += -worldDirections.forward;
    }

    if (input->isKeyDown(GLFW_KEY_A))
    {
        velocity += -worldDirections.right;
    }

    if (input->isKeyDown(GLFW_KEY_D))
    {
        velocity += worldDirections.right;
    }

    m_transform.m_position += velocity * m_cameraSpeed * Time::getDeltaTime();
}
