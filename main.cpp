#include <iostream>
#include <Game.h>
#include <thread>

int main()
{
    Game* game = Game::instance();

    game->init();

    auto accumulator = 0.0;
    auto* state = game->getState();

    while (game->isRunning())
    {
        game->updateFrameState();

        accumulator += state->lastFrameDiff;

        while (accumulator >= state->fixedDelta && game->isRunning())
        {
            game->fixedTick();
            accumulator -= state->fixedDelta;
        }

        game->tick();
        game->render();

        std::cout << 1000 / state->lastFrameDiff << "\r";
    }

    return 0;
}