#ifndef __BULLET_H__
#define __BULLET_H__

#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "../Utilities/Settings.h"

#include <string>
#include <SFML/Graphics.hpp>

class Bullet {
public :
    Bullet (std::string const& path, float x = 0, float y = 0, bool move_down = false);
    ~Bullet ();

    void update (float speed);
    void setSpriteFromFile(std::string const& path);

    sf::IntRect getCollider ();

    void draw(sf::RenderWindow* window);

private :
    float x;
    float y;

    bool move_down;

    sf::Vector2i size;
    unsigned int framesCount;
    unsigned int currentFrame;

    sf::Sprite sp;
};

#endif
