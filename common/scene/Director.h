//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_DIRECTOR_H
#define SILLYGAME2_DIRECTOR_H


#include <object/GameObject.h>
#include <vector>
#include <scene/SceneState.h>
#include <object/camera/Camera.h>
#include "Scene.h"

class Director
{
private:
    bool m_loading = false;

    std::shared_ptr<Scene> m_currentScene;
    std::unique_ptr<SceneState> m_currentSceneState;
    std::shared_ptr<Camera> m_currentCamera;
public:
    void loadScene(std::shared_ptr<Scene>);

    void addObject(std::shared_ptr<GameObject>);

    void setCamera(std::shared_ptr<Camera> t_camera);

    std::shared_ptr<Camera> getCamera();

    bool isLoading();

    static Director* instance();

    std::vector<std::shared_ptr<GameObject>>* getObjectsInScene();

    void onUpdate();
};


#endif //SILLYGAME2_DIRECTOR_H
