//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_TESTSCENE_H
#define SILLYGAME2_TESTSCENE_H


#include <scene/Scene.h>

class TestScene : public Scene
{
private:
    float getRandomColour();

public:
    void onLoad() override;

    void onUpdate() override;
};


#endif //SILLYGAME2_TESTSCENE_H
