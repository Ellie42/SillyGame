//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_GAMESTATE_H
#define SILLYGAME2_GAMESTATE_H

#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>

using namespace boost::multiprecision;
using namespace std::chrono;
using hrc_time_point = high_resolution_clock::time_point;

struct GameState
{
    cpp_int tick = 0;
    cpp_int frame = 0;
    double time = 0.0;
    hrc_time_point lastFrameTime;
    hrc_time_point currentFrameTime;
    double fixedDelta = 1000 / 30;
    double lastFrameDiff;
};


#endif //SILLYGAME2_GAMESTATE_H
