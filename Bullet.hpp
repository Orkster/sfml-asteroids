#ifndef _BULLET_HPP
#define _BULLET_HPP_

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Bullet: public sf::Drawable, public sf::Transformable {
    static float lifetime;
    static float speed;

    public:
        Bullet();
        Bullet(sf::Vector2f position, float angle);
        ~Bullet();

        bool isAlive();
        void kill();
        void update(float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void laser();
        void setDefault();


    private:
        bool is_alive;
        float remaining_life;
        sf::Vector2f direction;
};
#endif
