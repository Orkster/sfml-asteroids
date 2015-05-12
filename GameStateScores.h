#ifndef GAMESTATESCORES_H
#define GAMESTATESCORES_H

#include "GameState.hpp"
#include <string>
#include <fstream>

class GameStateScores : public GameState
{
private:

    sf::View view;
    sf::Text textString;
    sf::Font font;

    void toMenu();
    void setTextForString(std::string, sf::Vector2f);

public:

    struct Entry{
        int score;
        std::string name;
    };

    std::ifstream myFile;

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateScores(Game* game, int, std::string);
};

#endif // GAMESTATESCORES_H
