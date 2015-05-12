#include "SFML/Graphics.hpp"

#include "GameState.hpp"
#include "GameStateEditor.hpp"
#include "GameStateGame.h"
#include "GameStateAbout.h"



GameStateEditor::GameStateEditor(Game *game){

    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);
    font.loadFromFile("Media/font.ttf");
    textString.setFont(font);
    textString.setCharacterSize(50);
    textString.setColor(sf::Color::Black);
    selection = 1;
}

void GameStateEditor::draw(const float dt) {
    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    setTextForString("new game",sf::Vector2f(100,100), 1);
    setTextForString("high scores",sf::Vector2f(100,200), 2);
    setTextForString("about",sf::Vector2f(100,300), 3);
    setTextForString("exit",sf::Vector2f(100,400), 4);

    return;
}

void GameStateEditor::update(const float dt) {
    return;
}

void GameStateEditor::handleInput() {
    sf::Event event;

    while(this->game->window.pollEvent(event)) {
        switch(event.type)
        {
        case sf::Event::Closed:
        {
            this->game->window.close();
            break;
        }
        case sf::Event::Resized:
        {
            gameView.setSize(event.size.width, event.size.height);
            guiView.setSize(event.size.width, event.size.height);
            this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
            this->game->background.setScale(
                  float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                  float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
            break;
         }
         default: break;

        }

        if((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) && event.type==sf::Event::KeyPressed) {
            if(selection>1)selection--;
            else selection=4;
        }
        if((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) && event.type==sf::Event::KeyPressed) {
            if(selection<4)selection++;
            else selection=1;
        }
        if(event.key.code == sf::Keyboard::Return && event.type==sf::Event::KeyPressed) {
            switch(selection) {
            case 1:
                this->game->pushState(new GameStateGame(this->game));
                break;
            case 2:
                //load
                break;
            case 3:
                // about func
                this->game->pushState(new GameStateAbout(this->game));
                break;
            case 4:
                //exit
                this->game->window.close();
                break;
            default:
                break;
            }
        }
        draw(7.77);
    }
}

void GameStateEditor::setTextForString(std::string text, sf::Vector2f pos, int stringNumber){
    textString.setColor(sf::Color::White);
    textString.setString(text);
    textString.setPosition(pos);
    if(selection==stringNumber)textString.setColor(sf::Color::Blue);
    this->game->window.draw(textString);
}


