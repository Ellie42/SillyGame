//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_SCENESTATE_H
#define SILLYGAME2_SCENESTATE_H


#include <object/GameObject.h>

class SceneState
{
private:
    std::vector<std::shared_ptr<GameObject>> m_objects;
public:
    void addObject(std::shared_ptr<GameObject>);
    std::vector<std::shared_ptr<GameObject>>* getObjects();
};


#endif //SILLYGAME2_SCENESTATE_H
