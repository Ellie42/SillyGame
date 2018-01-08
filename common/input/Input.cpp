//
// Created by Sophie Gauthier on 04/01/2018.
//

#include <Game.h>
#include "Input.h"
#include <GLFW/glfw3.h>

bool Input::isKeyDown(int glfwKeyCode)
{
    auto current = m_keyStates[glfwKeyCode].current;
    return current == GLFW_PRESS || current == GLFW_REPEAT;
}

bool Input::isKeyPressed(int glfwKeyCode)
{
    return m_keyStates[glfwKeyCode].current == GLFW_PRESS && m_keyStates[glfwKeyCode].previous == GLFW_RELEASE;
}

Input::Input()
{
    glfwSetKeyCallback(Game::instance()->getWindow()->getWindow(), Input::glfwKeyCallback);
}

void Input::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    auto* keyStates = Input::instance()->getKeyStates();
    auto* keyState = &keyStates->operator[](key);

    keyState->previous = keyState->current;
    keyState->current = action;
}

std::map<int, KeyState>* Input::getKeyStates()
{
    return &m_keyStates;
}

void Input::update()
{
    for (auto entry : m_keyStates)
    {
        if (entry.second.current == GLFW_PRESS && entry.second.previous == GLFW_RELEASE)
        {
            m_keyStates[entry.first].previous = GLFW_PRESS;
        }
    }
}
