//
// Created by Sophie Gauthier on 04/01/2018.
//

#ifndef SILLYGAME2_INPUT_H
#define SILLYGAME2_INPUT_H

#include <GLFW/glfw3.h>
#include <map>

struct KeyState {
    int previous = 0;
    int current = 0;
};

class Input
{
private:
    std::map<int, KeyState> m_keyStates;
public:
    static Input* instance()
    {
        static Input input;
        return &input;
    }

    Input();

    bool isKeyDown(int glfwKeyCode);

    static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    std::map<int, KeyState>* getKeyStates();

    bool isKeyPressed(int glfwKeyCode);

    void update();
};


#endif //SILLYGAME2_INPUT_H
