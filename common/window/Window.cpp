//
// Created by Sophie Gauthier on 27/12/2017.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Game.h>
#include "Window.h"

Window::Window()
{
    glfwSetErrorCallback(&Window::glfwErrorHandler);
}

int Window::show()
{
    if (!glfwInit())
    {
        return 1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    m_windowDimensions = {mode->width, mode->height};

    m_window = glfwCreateWindow(m_windowDimensions.width, m_windowDimensions.height, "SillyGame", nullptr, nullptr);

    if (m_window == nullptr)
    {
        return 1;
    }

    glfwMakeContextCurrent(m_window);
    glewExperimental = static_cast<GLboolean>(true);
    glfwShowWindow(m_window);

    if (glewInit() != GLEW_OK)
    {
        return 1;
    }

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);

    return 0;
}

void Window::glfwErrorHandler(int t_error, const char* t_description)
{
    std::cerr << t_error << " " << t_description << std::endl;
}

void Window::update()
{
    if (glfwWindowShouldClose(m_window))
    {
        Game::instance()->stop();
    }

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

GLFWwindow* Window::getWindow()
{
    return m_window;
}

WindowDimensions* Window::getDimensions()
{
    return &m_windowDimensions;
}
