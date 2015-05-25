#ifndef BONUS_H
#define BONUS_H


#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include  "Bullet.hpp"

class Bonus: public sf::Drawable, public sf::Transformable {
    static const float radius;

    public:
        Bonus();
        Bonus(sf::Vector2f position, int type);//change to enum
        ~Bonus();


        void breakDown();
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        bool checkPoint(sf::Vector2f point);
        bool isAlive();
        void speed();
        void laser();
        void life();

    private:
        sf::CircleShape shape;
        int type;
        bool is_alive;
        Spaceship ship;
        Asteroid asteroid;
        Bullet bullet;

};

#endif // BONUS_H
