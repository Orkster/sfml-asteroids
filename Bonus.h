#ifndef BONUS_H
#define BONUS_H


#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"
#include  "Bullet.hpp"


class Bonus: public sf::Drawable, public sf::Transformable {
    static float speed[3];
    static float radius[3];

    public:
        Bonus();
        Bonus(int);
        Bonus(sf::Vector2f position, float angle, int level, int);
        ~Bonus();

        bool isAlive();
        int  getLevel();
        bool checkPoint(sf::Vector2f point);
        void breakDown();
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void speedy(Spaceship &ship);
        void destroy(std::vector<Asteroid>&, Spaceship&, int &number);
        void life(Spaceship &ship);
        int  getType();
        void setUnactive();

    private:
        int level;
        bool is_alive;
        sf::Vector2f direction;
        sf::CircleShape shape;

        Spaceship ship;
        Asteroid asteroid;
        Bullet bullet;
        int type;
};

#endif // BONUS_H
