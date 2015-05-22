#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include "SFML/Graphics.hpp"

#include "GameState.hpp"
#include "GameStateScores.h"

class GameStateEditor : public GameState
{
private:

    sf::View gameView;
    sf::View guiView;

    sf::Text textString;
    sf::Font font;
    void setTextForString(std::string, sf::Vector2f, int);
    int selection;

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game* game);
};

#endif // GAMESTATEEDITOR_H
