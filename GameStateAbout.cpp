#include "SFML/Graphics.hpp"

#include "GameStateAbout.h"
#include "GameStateEditor.hpp"
#include "GameState.hpp"

GameStateAbout::GameStateAbout(Game *game) {

    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
    font.loadFromFile("Media/font.ttf");
    textString.setFont(font);
    textString.setCharacterSize(30);
    textString.setColor(sf::Color::Black);
}

void GameStateAbout::draw(const float dt) {

    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);
    setTextForString("controls",sf::Vector2f(325,50));
    setTextForString("up to accelerate",sf::Vector2f(280,80));
    setTextForString("down to brake",sf::Vector2f(300,110));
    setTextForString("left and right to rotate",sf::Vector2f(220,140));
    setTextForString("made by orest petruniv",sf::Vector2f(220,300));
    setTextForString("powered by sfml",sf::Vector2f(250,350));
    setTextForString("press space to return to menu",sf::Vector2f(150,500));

    return;
}

void GameStateAbout::update(const float dt) {

}

void GameStateAbout::handleInput() {
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
                else if(event.key.code == sf::Keyboard::Space) this->loadgame();
                break;
            }
            default: break;
        }
    }

    return;
}

void GameStateAbout::loadgame(){
    this->game->pushState(new GameStateEditor(this->game));

    return;
}

void GameStateAbout::setTextForString(std::string text, sf::Vector2f pos){
    textString.setColor(sf::Color::White);
    textString.setString(text);
    textString.setPosition(pos);
    this->game->window.draw(textString);

}
