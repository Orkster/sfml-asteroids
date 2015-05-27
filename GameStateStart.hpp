#ifndef GAMESTATESTART_H
#define GAMESTATESTART_H

#include "SFML/Graphics.hpp"

#include "GameState.hpp"

class GameStateStart : public GameState
{
private:

    sf::View view;
    sf::Text textString;
    sf::Font font;

    void loadgame();
    void setTextForString(std::string, sf::Vector2f);

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateStart(Game* game);
};

#endif // GAMESTATESTART_H
