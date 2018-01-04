//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_WINDOW_H
#define SILLYGAME2_WINDOW_H

#include <GLFW/glfw3.h>

struct WindowDimensions{
    int width;
    int height;
};

class Window
{
public:
    Window();

    int show();

    void update();

    GLFWwindow* getWindow();

    WindowDimensions* getDimensions();

private:
    GLFWwindow* m_window;
    WindowDimensions m_windowDimensions;

    static void glfwErrorHandler(int error, const char *description);
};


#endif //SILLYGAME2_WINDOW_H
