#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "Loader.h"

#include <string>
#include <SFML/Graphics.hpp>

class SpaceShip {
public :
    SpaceShip (std::string const& tx_path, unsigned int size = 32, float x = 0.0, float y = 0.0);
    ~SpaceShip();

    void update(float speed);
    void moveX(float amount);
    void moveY(float amount);
    void invertX();
    void setPosition (float x, float y);

    sf::IntRect getCollider ();

    void setSpriteFromFile(std::string const& path);

    void draw (sf::RenderWindow* window);

private :
    float x = 0;
    float y = 0;
    bool move_right = true;

    sf::Vector2i size;

    sf::Sprite sp;
};

#endif