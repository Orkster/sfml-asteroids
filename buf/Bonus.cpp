#include "Bonus.h"

const float Bonus::radius = 100.f;

Bonus::Bonus(){

}

Bonus::Bonus(sf::Vector2f position, int myType){
    is_alive = true;


    setPosition(position);
    shape.setRadius(radius);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setOrigin(radius, radius);

    switch (myType){
        case 1:
        shape.setPointCount(4);
        shape.setFillColor(sf::Color::Green);
        break;

        case 2:
        shape.setPointCount(6);
        shape.setFillColor(sf::Color::Red);

        break;

        case 3:
        shape.setPointCount(10);
        shape.setFillColor(sf::Color::Yellow);
        break;
    }

}

Bonus::~Bonus() {
}

bool Bonus::isAlive() {
    return is_alive;
}

void Bonus::update(float frametime) {
    if (!is_alive) return;

    move(sf::Vector2f(0.f, 0.f));

    sf::Vector2f position = getPosition();

    if (position.x < -radius)
        position.x = APP_WIDTH;
    else if (position.x > APP_WIDTH)
        position.x = 0.f;

    if (position.y < -radius)
        position.y = APP_HEIGHT;
    else if (position.y > APP_HEIGHT)
        position.y = 0.f;
    setPosition(position);
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(shape, states);
}


bool Bonus::checkPoint(sf::Vector2f point) {
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x;
    float py = point.y;

    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius * radius;

    return (sqrDistance <= sqrRadius);
}

void Bonus::speed(){
    ship.speedBonus();
}

void Bonus::laser(){
    bullet.laser();
}

void Bonus::life(){
    ship.increaseLives();
}

