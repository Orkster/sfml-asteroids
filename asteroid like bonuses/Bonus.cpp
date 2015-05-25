#include "Bonus.h"

float Bonus::speed[3] = {0.06f, 0.1f, 0.2f};//x2
float Bonus::radius[3] = {40.0f, 20.0f, 10.0f};

Bonus::Bonus(){

}

Bonus::Bonus(int myType):
   is_alive(true)
    {
   int angle = rand() % 360;
   direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

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

   int x = rand() % APP_WIDTH;
   int y = rand() % APP_HEIGHT;
   sf::Vector2f position(x, y);
   setPosition(position);
   shape.setRadius(radius[0]);
   shape.setOutlineColor(sf::Color::White);
   shape.setOutlineThickness(1);
   shape.setOrigin(radius[0], radius[0]);
}

Bonus::Bonus(sf::Vector2f position, float angle, int level, int myType):
   is_alive(true),
   level(level) {
   direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));

   setPosition(position);
   shape.setRadius(radius[0]);
   shape.setOutlineColor(sf::Color::White);
   shape.setOutlineThickness(1);
   shape.setOrigin(radius[0], radius[0]);

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

   setPosition(position);
   shape.setPointCount(8);
   shape.setRadius(radius[0]);
   shape.setOrigin(radius[0], radius[0]);
}

Bonus::~Bonus() {
}

bool Bonus::isAlive() {
   return is_alive;
}

void Bonus::update(float frametime) {
   if (!is_alive) return;

   sf::Vector2f distance = direction * speed[2] * frametime;
   move(distance);

   sf::Vector2f position = getPosition();

   if (position.x < -radius[0])
       position.x = APP_WIDTH;
   else if (position.x > APP_WIDTH)
       position.x = 0.0f;

   if (position.y < -radius[0])
       position.y = APP_HEIGHT;
   else if (position.y > APP_HEIGHT)
       position.y = 0.0f;
   setPosition(position);
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   states.transform *= getTransform();
   target.draw(shape, states);
}

int Bonus::getLevel() {
   return level;
}

void Bonus::breakDown() {
   level++;

   if (level > 2) {
       is_alive = false;
       return;
   }

   shape.setRadius(radius[0]);
   shape.setOrigin(radius[0], radius[0]);
   float angle = rand() % 360;
   direction = sf::Vector2f(cos(angle * DEG2RAD), sin(angle * DEG2RAD));
}

bool Bonus::checkPoint(sf::Vector2f point) {
   float ax = getPosition().x;
   float ay = getPosition().y;

   float px = point.x;
   float py = point.y;

   float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
   float sqrRadius = radius[0] * radius[0];

   return (sqrDistance <= sqrRadius);
}

void Bonus::speedy(){
    ship.speedBonus();
}

void Bonus::laser(){
    bullet.laser();
}

void Bonus::life(){
    ship.increaseLives();
}
