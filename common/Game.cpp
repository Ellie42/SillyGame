//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <renderer/adapter/OpenGL.h>
#include "Game.h"
#include <scene/Director.h>
#include <memory>
#include "../game/scenes/TestScene.h"
#include "../game/SceneDirection.h"
#include <renderer/Renderer.h>
#include <input/Input.h>

Game* Game::instance()
{
    static Game game;

    return &game;
}

void Game::init()
{
    m_sceneDirection = std::make_unique<SceneDirection>();
    m_window.show();
    Director::instance()->loadScene(m_sceneDirection->getScene());
    Renderer::instance()->useAdapter(std::make_unique<OpenGL>());
    Renderer::instance()->init();
}

void Game::tick()
{
    Director::instance()->onUpdate();
}

void Game::render()
{
    Renderer::instance()->render();
    Input::instance()->update();
    m_window.update();
}

bool Game::isRunning()
{
    return m_running;
}

void Game::stop()
{
    m_running = false;
}

void Game::updateFrameState()
{
    static bool initial = true;

    m_state.currentFrameTime = high_resolution_clock::now();

    if (!initial)
    {
        m_state.lastFrameDiff = duration<double, std::milli>(m_state.currentFrameTime - m_state.lastFrameTime).count();
    } else
    {
        m_state.lastFrameDiff = 0;
        initial = false;
    }

    m_state.delta = m_state.lastFrameDiff / 1000;

    m_state.lastFrameTime = m_state.currentFrameTime;
}

const GameState* Game::getState()
{
    return &m_state;
}

void Game::fixedTick()
{
    m_state.time += m_state.fixedDelta;
}

Window* Game::getWindow()
{
    return &m_window;
}
