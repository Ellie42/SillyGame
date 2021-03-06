//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_GAME_H
#define SILLYGAME2_GAME_H

#include <window/Window.h>
#include <GameState.h>
#include "../game/Script.h"

class Game
{
private:
    bool m_running = true;
    Window m_window;
    GameState m_state;
    std::unique_ptr<Script> m_sceneDirection;
public:
    void init();

    void tick();

    bool isRunning();

    void stop();

    static Game* instance();

    void render();

    void updateFrameState();

    const GameState* getState();

    void fixedTick();

    Window* getWindow();
};


#endif //SILLYGAME2_GAME_H
