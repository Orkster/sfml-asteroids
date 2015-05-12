#include "SFML/Graphics.hpp"

#include "GameStateScores.h".hpp"
#include "GameStateEditor.hpp"
#include "GameState.hpp"
#include "windows.h"

GameStateScores::GameStateScores(Game *game, int score, std::string name) {

    this->game = game;
    this->game->window.setKeyRepeatEnabled(false );
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
    font.loadFromFile("Media/font.ttf");
    textString.setFont(font);
    textString.setCharacterSize(50);
    textString.setColor(sf::Color::Black);

    //Entry.score = score;
    //Entry.name = name;

}

void GameStateScores::draw(const float dt) {

    this->game->window.setView(this->view);
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    return;
}

void GameStateScores::update(const float dt) {
}

void GameStateScores::handleInput() {
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                this->game->background.setScale(
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                else if(event.key.code == sf::Keyboard::Space) this->toMenu();
                break;
            }
            default: break;
        }
    }

    return;
}

void GameStateScores::toMenu(){
    this->game->pushState(new GameStateEditor(this->game));

    return;
}

void GameStateScores::setTextForString(std::string text, sf::Vector2f pos){
    textString.setColor(sf::Color::White);
    textString.setString(text);
    textString.setPosition(pos);
    this->game->window.draw(textString);
}
