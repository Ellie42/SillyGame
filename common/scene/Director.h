//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_DIRECTOR_H
#define SILLYGAME2_DIRECTOR_H


#include <object/GameObject.h>
#include <vector>
#include <state/SceneState.h>
#include "Scene.h"

class Director
{
private:
    bool m_loading = false;

    std::unique_ptr<Scene> m_currentScene;
    std::unique_ptr<SceneState> m_currentSceneState;

public:
    void loadScene(std::unique_ptr<Scene>);
    void addObject(std::shared_ptr<GameObject>);

    bool isLoading();

    static Director* instance();

    std::vector<std::shared_ptr<GameObject>>* getObjectsInScene();

    void onUpdate();
};


#endif //SILLYGAME2_DIRECTOR_H