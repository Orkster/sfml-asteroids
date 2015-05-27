#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <stack>

#include <SFML/Graphics.hpp>


#include "TextureManager.hpp"

class GameState;

class Game {
    public:
        Game();
        ~Game();

        sf::RenderWindow window;
        std::stack<GameState*> states;
        TextureManager texmgr;
        sf::Sprite background;

        void pushState(GameState* state);
        void popState();
        void changeState(GameState* state);
        GameState* peekState();

        int run();
        bool gamePause;
        void quit();
        sf::Event event;

    private:

        bool running;
        void loadTextures();
};

#endif
