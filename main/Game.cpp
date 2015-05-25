#include "Game.hpp"
#include "Constants.hpp"

#include "Game.hpp"
#include "GameState.hpp"
#include "TextureManager.hpp"

Game::Game():
    running(true), lives(3) {
    this->loadTextures();
    window.create(sf::VideoMode(800, 600), "Asteroid");
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(APP_FPS);
    this->background.setTexture(this->texmgr.getRef("background"));

    gamePause = false;
}

Game::~Game() {
    window.close();
}

void Game::pushState(GameState *state) {
    this->states.push(state);
    return;
}

void Game::popState() {

    delete this->states.top();
    this->states.pop();
    return;
}

void Game::changeState(GameState *state) {

    if(!this->states.empty())
        popState();
    pushState(state);
    return;
}

GameState* Game::peekState() {

    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::loadTextures(){
    texmgr.loadTexture("background", "Media/background1.jpg");
}


int Game::run() {

    //Level level;
    sf::Clock clock;



    /*level.start();
    while (running) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return EXIT_SUCCESS;
            }
            level.onEvent(event);
        }

        window.clear();
        level.update(clock.restart().asMilliseconds());
        level.show(window);
        window.display();
    }
    return EXIT_SUCCESS;*/

    while(this->window.isOpen())
        {
            sf::Time elapsed = clock.restart();
            float dt = elapsed.asMilliseconds();

            if(peekState() == nullptr) continue;
            peekState()->handleInput();

            if(!gamePause)
              peekState()->update(dt);

            //this->window.clear(sf::Color::Black);
            peekState()->draw(dt);
            this->window.display();
        }

    return EXIT_SUCCESS;
}
