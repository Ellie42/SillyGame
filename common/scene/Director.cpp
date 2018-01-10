//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "Director.h"
#include "Scene.h"

Director* Director::instance()
{
    static Director director;

    return &director;
}

void Director::onUpdate()
{
    m_currentScene->onUpdate();

    m_currentCamera->onUpdate();

    auto* objects = m_currentSceneState->getObjects();

    for (auto const& obj : *objects)
    {
        obj->onUpdate();
    }
}

void Director::loadScene(std::shared_ptr<Scene> t_scene)
{
    m_currentScene = t_scene;
    m_currentSceneState = std::make_unique<SceneState>();

    m_currentScene->onLoad();

    if (!m_currentCamera)
    {
        m_currentCamera = std::make_shared<Camera>();
    }
}

void Director::addObject(std::shared_ptr<Object> t_obj)
{
    m_currentSceneState->addObject(t_obj);
    t_obj->onInstance();
}

bool Director::isLoading()
{
    return m_loading;
}

std::vector<std::shared_ptr<Object>>* Director::getObjectsInScene()
{
    return m_currentSceneState->getObjects();
}

void Director::setCamera(std::shared_ptr<Camera> t_camera)
{
    m_currentCamera = t_camera;
}

std::shared_ptr<Camera> Director::getCamera()
{
    return m_currentCamera;
}
