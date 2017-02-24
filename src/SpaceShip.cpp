#include "SpaceShip.h"

#include <iostream>

SpaceShip::SpaceShip (std::string const& path, unsigned int framesCount, unsigned int size, float x, float y) :
    x(x), y(y) {
        
    this->setSpriteFromFile(path, framesCount, size);
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::setSpriteFromFile(std::string const& path, unsigned int framesCount, unsigned int size) {
    this->sp.setTexture(Loader::get().getTexture(path));

    this->size.x = size;
    this->size.y = size;

    if (framesCount == 0) {
        std::cout << "SpaceShip must hace atleast one frame" << std::endl;
        exit(1);
    }

    this->framesCount = framesCount;
    this->currentFrame = 0;
}

void SpaceShip::nextFrame () {
    this->currentFrame = (++this->currentFrame) % this->framesCount;
}

void SpaceShip::update(float speed) {
    if (this->move_right)
        this->moveX(speed);
    else
        this->moveX(-speed);
}

void SpaceShip::moveX(float amount) {
    this->x += amount;
}

void SpaceShip::moveY(float amount) {
    this->y += amount;
}

void SpaceShip::invertX() {
    this->move_right = !(this->move_right);
}

void SpaceShip::setPosition (float x, float y) {
    this->x = x;
    this->y = y;
}

sf::IntRect SpaceShip::getCollider () {
    sf::IntRect col(this->x, this->y, this->size.x, this->size.y);
    return col;
}

void SpaceShip::draw (sf::RenderWindow* window) {
    sf::Vector2i rectPos(this->size.x * this->currentFrame, 0);
    sf::IntRect rect(rectPos, this->size);
    sp.setTextureRect(rect);
    this->sp.setPosition(this->x, this->y);
    window->draw(this->sp);
}

float SpaceShip::getX() {
    return this->x;
}

float SpaceShip::getY() {
    return this->y;
}