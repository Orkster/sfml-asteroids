#include "SFML/Graphics.hpp"

#include "GameStateScores.h"
#include "GameStateEditor.hpp"
#include "GameState.hpp"
#include "windows.h"
#include <iostream>
#include <algorithm>
#include <conio.h>

#include <QTextStream>

GameStateScores::GameStateScores(Game *game) {

    this->game = game;
    this->game->window.setKeyRepeatEnabled(false);

    font.loadFromFile("Media/font.ttf");
    textString.setFont(font);
    textString.setCharacterSize(40);
    textString.setColor(sf::Color::White);

    i = 0;

    this->read(mass);

}

GameStateScores::GameStateScores(Game *game, std::string name, int score){

    this->game = game;
    this->game->window.setKeyRepeatEnabled(false);

    font.loadFromFile("Media/font.ttf");
    textString.setFont(font);
    textString.setCharacterSize(50);
    textString.setColor(sf::Color::Black);

    strcpy(rec.name, name.c_str());
    rec.points = score;
    this->write(rec);

    i = 0;

    this->read(mass);
}

void GameStateScores::draw(const float dt) {

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    i = 0;
    int restriction;
    if(mass.size() > 8)
        restriction = 8;
    else
        restriction = mass.size();
    while(i < restriction){     //mass.size
        setTextForString(mass[i].name, sf::Vector2f(110,160 + 50 * i));
        setTextForString(std::to_string(mass[i].points), sf::Vector2f(540,160 + 50 * i));
        std::cout<< std::endl;
        std::cout << mass[i].name;
        std::cout << mass[i].points;
        i++;
    }

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

bool GameStateScores::read(std::vector <Gamer> &vec) {
        Gamer tmp;

        FILE *input = fopen("table.txt", "rt");
        if (input == NULL){
                std::cout << "bad";
                return false;
        }

        while (!feof(input)) {
                fscanf(input, "%s %d", tmp.name, &tmp.points);
                vec.push_back(tmp);
                std:: cout << tmp.name;
                std:: cout << tmp.points;
        }

         std::sort(vec.begin(), vec.end(), Gamer());

        fclose(input);

        return true;
}

void GameStateScores::write(const Gamer &record) {
        FILE *output = fopen("table.txt", "a+");

        fprintf(output, "\n%s %d", record.name, record.points);

        fclose(output);
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


