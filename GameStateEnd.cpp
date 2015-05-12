#include "GameStateEnd.h"

#include "SFML/Graphics.hpp"

#include "GameStateStart.hpp"
#include "GameState.hpp"

GameStateEnd::GameStateEnd(Game *game, int score) {

    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
    font.loadFromFile("Media/font.ttf");

    textString.setFont(font);
    textString.setCharacterSize(20);
    textString.setColor(sf::Color::Black);

    text.setFont(font);
    text.setPosition(sf::Vector2f(200, 400));
    text.setCharacterSize(30);
    text.setColor(sf::Color::White);

    endScore = score;
}

void GameStateEnd::draw(const float dt) {

    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);
    this->game->window.draw(text);

    if(endScore < 5000)
        endgame1();
    else if (endScore > 5000 && endScore < 10000)
        endgame2();
    else if (endScore > 10000)
        endgame3();


    setTextForString("score " + std::to_string(endScore), sf::Vector2f(500,410));
    setTextForString("space to return to menu", sf::Vector2f(240,500));

    return;
}

void GameStateEnd::update(const float dt) {

}

void GameStateEnd::handleInput() {
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
                else if(event.key.code == sf::Keyboard::Space) this->menu();
                else if(event.key.code == sf::Keyboard::BackSpace) userInput.clear();
                break;
            }

        case sf::Event::TextEntered:
        {
            // Handle ASCII characters only
                if (event.text.unicode < 128 && userInput.getSize() <=4)
                {
                    //str += static_cast<char>(event.text.unicode);
                    userInput.insert(userInput.getSize(), event.text.unicode);
                    text.setString(userInput);
                }
        }
            default: break;
        }
    }

    return;
}

void GameStateEnd::menu(){
    this->game->pushState(new GameStateEditor(this->game));

    return;
}

void GameStateEnd::endgame1(){
    setTextForString("you have failed your mission.",sf::Vector2f(270,100));
    setTextForString("in the last moments of your life you see asteroids",sf::Vector2f(120,130));
    setTextForString("falling on your homeplanet",sf::Vector2f(270,160));
    setTextForString("Your family, friends, everybody you knew and loved",sf::Vector2f(110,190));
    setTextForString("are dead",sf::Vector2f(370,210));
    setTextForString("State your name, fallen warrior",sf::Vector2f(220,240));
    setTextForString("and hope for salvation",sf::Vector2f(270,270));
}

void GameStateEnd::endgame2(){
    setTextForString("Your fight is over",sf::Vector2f(270,100));
    setTextForString("your heroism wasnt enough",sf::Vector2f(220,130));
    setTextForString("planet is devasteted, civilization is no more",sf::Vector2f(140,160));
    setTextForString("survivors will envy those, who died",sf::Vector2f(200,190));
    setTextForString("state your name, fallen hero",sf::Vector2f(220,220));
    setTextForString("and hope for oblivion",sf::Vector2f(250,250));
}

void GameStateEnd::endgame3(){
    setTextForString("you have failed your mission.",sf::Vector2f(270,100));
    setTextForString("in the last moments of your life you see asteroids",sf::Vector2f(120,130));
    setTextForString("falling on your homeplanet",sf::Vector2f(270,160));
    setTextForString("Your family, friends, everybody you knew and loved",sf::Vector2f(110,190));
    setTextForString("are dead",sf::Vector2f(370,210));
    setTextForString("State your name, fallen warrior",sf::Vector2f(220,240));
    setTextForString("and hope for salvation",sf::Vector2f(270,270));
}
void GameStateEnd::setTextForString(std::string text, sf::Vector2f pos){
    textString.setColor(sf::Color::White);
    textString.setString(text);
    textString.setPosition(pos);
    this->game->window.draw(textString);

}
