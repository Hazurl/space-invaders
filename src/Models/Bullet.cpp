#include "Bullet.h"

#include <iostream>

Bullet::Bullet (std::string const& imgName, float x, float y, bool move_down) :
    x(x), y(y), move_down(move_down) {
    this->setSpriteFromFile(imgName);
}

Bullet::~Bullet () {

}

void Bullet::update (float speed) {
    if (move_down)
        this->y += speed;
    else
        this->y -= speed;
}

void Bullet::setSpriteFromFile(std::string const& imgName) {
    this->sp.setTexture( Loader::get().getTexture( IMAGE_PATH("") + imgName ) );

    ImageSettings sett = Settings::get().getImageSettings(imgName);

    this->size.x = sett.width;
    this->size.y = sett.height;

    this->framesCount = sett.frame;
    this->currentFrame = 0;
}

sf::IntRect Bullet::getCollider () {
    sf::IntRect col(this->x, this->y, this->size.x, this->size.y);
    return col;
}

void Bullet::draw(sf::RenderWindow* window) {
    sf::Vector2i rectPos(this->size.x * this->currentFrame, 0);
    sf::IntRect rect(rectPos, this->size);

    this->sp.setTextureRect(rect);
    this->sp.setPosition(this->x, this->y);
    if (!move_down) {
        this->sp.setOrigin(this->size.x / 2, this->size.y / 2);
        this->sp.setRotation(180);
    }

    window->draw(this->sp);
}
