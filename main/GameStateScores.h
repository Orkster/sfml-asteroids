#ifndef GAMESTATESCORES_H
#define GAMESTATESCORES_H

#include "GameState.hpp"
#include <string>
#include <fstream>
#include <vector>

const int NAME_SIZE = 50;

struct Gamer {
        char name[NAME_SIZE];
        int points;

        bool operator()(const Gamer& a, const Gamer& b) const
            {
                return a.points >    b.points;
            }
};

class GameStateScores : public GameState
{
private:

    sf::View view;
    sf::Text textString;
    sf::Font font;

    void toMenu();
    void setTextForString(std::string, sf::Vector2f);
    void setHighScore();

    void drawScores();

public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();    

    bool read(std::vector <Gamer> &);
    void write(const Gamer &);

    GameStateScores(Game* game);
    GameStateScores(Game* game, std::string, int);



    std::vector <Gamer> mass;
    Gamer rec;
    char buf[NAME_SIZE];
    int i = 0;
};

#endif // GAMESTATESCORES_H
