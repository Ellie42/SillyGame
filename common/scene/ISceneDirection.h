//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_ISCENEDIRECTION_H
#define SILLYGAME2_ISCENEDIRECTION_H

#include "Scene.h"

class ISceneDirection {
    virtual std::shared_ptr<Scene> getScene() = 0;
};

#endif //SILLYGAME2_ISCENEDIRECTION_H
