#include "Game.hpp"
#include "GameStateStart.hpp"
#include "GameStateEnd.h"

int main(int, char const**) {
    srand(time(NULL));

    Game game;
    //game.pushState(new GameStateStart(&game));
    game.pushState(new GameStateEnd(&game, 6000));
    game.run();
    return EXIT_SUCCESS;
}

/*
 * зникнення куль !
 * high scores    !
 * пауза          !
 *
 *
 *
 * різні фони     ?
 */
