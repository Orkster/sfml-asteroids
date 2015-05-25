#ifndef GAMESTATEGAME_H
#define GAMESTATEGAME_H


#include <SFML/Graphics.hpp>

#include "GameState.hpp"
//#include "Bullet.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include "GameStateEnd.h"
#include "Bonus.h"

class GameStateGame : public GameState
{
    private:

     sf::View view;
     sf::Text textString;
     sf::Text scoreString;
     sf::Font font;

     Spaceship             ship;
     std::vector<Bullet>   bullets;
     std::vector<Asteroid> asteroids;
     std::vector<Bonus>    bonuses;



     bool gameOver;
     int  asteroidCount;
     int  level;
     void createNewWave();
     bool pause = true;

     void endGame();
     void setTextForString(std::string, sf::Vector2f);
     void setBonus();

    public:

     virtual void draw(const float dt);
     virtual void update(const float dt);
     virtual void handleInput();

    GameStateGame(Game* game);
};
#endif // GAMESTATEGAME_H
