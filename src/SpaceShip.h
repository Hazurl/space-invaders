#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include <string>
#include <SFML/Graphics.hpp>

class SpaceShip {
public :
    SpaceShip (float x = 0.0, float y = 0.0);
    SpaceShip (std::string const& tx_path, unsigned int width, unsigned int height, unsigned int first_x = 0.0,
               unsigned int first_y = 0.0, unsigned int second_x = 0.0, unsigned int second_y = 0.0, float x = 0.0, float y = 0.0);
    ~SpaceShip();

    void update(float speed);
    void moveX(float amount);
    void moveY(float amount);
    void invertX();

    void setSpriteFromFile(std::string const& path);

    void draw (sf::RenderWindow* window);

private :
    float x;
    float y;
    bool move_right;

    sf::Vector2i frame_0;
    sf::Vector2i frame_1;

    sf::Vector2i size;

    sf::Texture tx;
    sf::Sprite sp;
};

#endif