//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "SceneState.h"

void SceneState::addObject(std::shared_ptr<Object> t_obj)
{
    m_objects.push_back(t_obj);
}

std::vector<std::shared_ptr<Object>>* SceneState::getObjects()
{
    return &m_objects;
}
