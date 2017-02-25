#include "SpaceShip.h"

#include <iostream>

SpaceShip::SpaceShip (std::string const& imgName, float x, float y) {
    this->collider.left = x;
    this->collider.top = y;
    this->setSpriteFromFile(imgName);
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::setSpriteFromFile(std::string const& imgName) {
    this->sp.setTexture( Loader::get().getTexture( IMAGE_PATH("") + imgName ) );

    ImageSettings sett = Settings::get().getImageSettings(imgName);

    this->collider.width = sett.width;
    this->collider.height = sett.height;

    this->framesCount = sett.frame;
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
    this->collider.left += amount;
}

void SpaceShip::moveY(float amount) {
    this->collider.top += amount;
}

void SpaceShip::invertX() {
    this->move_right = !(this->move_right);
}

void SpaceShip::setPosition (float x, float y) {
    this->collider.left = x;
    this->collider.top = y;
}

sf::FloatRect SpaceShip::getCollider () {
    return this->collider;
}

void SpaceShip::draw (sf::RenderWindow* window) {
    sf::IntRect rect(sf::Vector2i(this->collider.width * this->currentFrame, 0), // pos
                     sf::Vector2i(this->collider.width, this->collider.height)); // size
    sp.setTextureRect(rect);
    this->sp.setPosition(this->collider.left, this->collider.top);
    window->draw(this->sp);
}

float SpaceShip::getX() {
    return this->collider.left;
}

float SpaceShip::getY() {
    return this->collider.top;
}