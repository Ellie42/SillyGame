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

void Director::onUpdate(){
    m_currentScene->onUpdate();

    auto* objects = m_currentSceneState->getObjects();

    for(auto const &obj : *objects){
        obj->onUpdate();
    }
}

void Director::loadScene(std::unique_ptr<Scene> t_scene)
{
    m_currentScene = std::move(t_scene);
    m_currentSceneState = std::make_unique<SceneState>();

    m_currentScene->onLoad();
}

void Director::addObject(std::shared_ptr<GameObject> t_obj)
{
    m_currentSceneState->addObject(t_obj);
}

bool Director::isLoading()
{
    return m_loading;
}

std::vector<std::shared_ptr<GameObject>>* Director::getObjectsInScene()
{
    return m_currentSceneState->getObjects();
}
