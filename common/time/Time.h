//
// Created by Sophie Gauthier on 05/01/2018.
//

#ifndef SILLYGAME2_TIME_H
#define SILLYGAME2_TIME_H


#include <Game.h>

class Time
{
public:
    static double getDeltaTime(){
        return Game::instance()->getState()->delta;
    }
};


#endif //SILLYGAME2_TIME_H
