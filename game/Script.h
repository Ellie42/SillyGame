//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_SCENEDIRECTION_H
#define SILLYGAME2_SCENEDIRECTION_H


#include <scene/IScript.h>
#include "scenes/TestScene.h"

class Script : public IScript
{
public:
    std::shared_ptr<Scene> getScene() override;
};


#endif //SILLYGAME2_SCENEDIRECTION_H
