#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "Loader.h"
#include "Define.h"
#include "Settings.h"

#include <string>
#include <SFML/Graphics.hpp>

class SpaceShip {
public :
    SpaceShip (std::string const& imgName, float x = 0.0, float y = 0.0);
    ~SpaceShip();

    void update(float speed);
    void moveX(float amount);
    void moveY(float amount);
    void invertX();
    void setPosition (float x, float y);

    sf::IntRect getCollider ();

    void setSpriteFromFile(std::string const& imgName);
    void nextFrame();

    void draw (sf::RenderWindow* window);

    float getX();
    float getY();

private :
    float x = 0;
    float y = 0;
    bool move_right = true;

    sf::Vector2i size;
    unsigned int framesCount;
    unsigned int currentFrame;

    sf::Sprite sp;
};

#endif