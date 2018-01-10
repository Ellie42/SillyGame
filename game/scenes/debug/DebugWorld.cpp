//
// Created by Sophie Gauthier on 08/01/2018.
//

#include <scene/Director.h>
#include <object/ui/Text.h>
#include "DebugWorld.h"
#include "../../objects/Debug/DebugText.h"

void DebugWorld::onLoad()
{
    auto debugText = std::make_shared<DebugText>();

    Director::instance()->addObject(debugText);
}
