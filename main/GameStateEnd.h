#ifndef GAMESTATEEND_H
#define GAMESTATEEND_H

#include "SFML/Graphics.hpp"

#include "GameState.hpp"
#include "GameStateEditor.hpp"


class GameStateEnd : public GameState
{
private:

    sf::View view;
    sf::Text textString;
    sf::Font font;

    void menu();
    void highscores();
    void setTextForString(std::string, sf::Vector2f);

    int endScore;
    sf::String userInput;
    sf::Text text;

    void endgame1();
    void endgame2();
    void endgame3();

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEnd(Game* game, int);
};




#endif // GAMESTATEEND_H
