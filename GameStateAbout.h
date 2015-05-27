#ifndef GAMESTATEABOUT_H
#define GAMESTATEABOUT_H


#include "SFML/Graphics.hpp"

#include "GameState.hpp"

class GameStateAbout : public GameState
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

    GameStateAbout(Game* game);
};

#endif // GAMESTATEABOUT_H
