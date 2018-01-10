//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_SCENESTATE_H
#define SILLYGAME2_SCENESTATE_H


#include <object/GameObject.h>

class SceneState
{
private:
    std::vector<std::shared_ptr<Object>> m_objects;
public:
    void addObject(std::shared_ptr<Object>);
    std::vector<std::shared_ptr<Object>>* getObjects();
};


#endif //SILLYGAME2_SCENESTATE_H
