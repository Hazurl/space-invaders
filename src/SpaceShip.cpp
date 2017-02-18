#include "SpaceShip.h"

#include <iostream>

SpaceShip::SpaceShip (std::string const& tx_path, unsigned int size, float x, float y) {
    this->setSpriteFromFile(tx_path);
    this->x = x;
    this->y = y;

    this->size.x = size;
    this->size.y = size;
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::setSpriteFromFile(std::string const& path) {
    this->sp.setTexture(Loader::getTexture(path));
}

void SpaceShip::update(float speed) {
    this->moveX(speed);
}

void SpaceShip::moveX(float amount) {
    this->x += amount;
}

void SpaceShip::moveY(float amount) {
    this->y += amount;
}

void SpaceShip::invertX() {
    this->move_right = ! this->move_right;
}

void SpaceShip::setPosition (float x, float y) {
    this->x = x;
    this->y = y;
}


void SpaceShip::draw (sf::RenderWindow* window) {
    sf::Vector2i rectPos(0, 0);
    sf::IntRect rect(rectPos, this->size);
    sp.setTextureRect(rect);
    this->sp.setPosition(this->x, this->y);
    window->draw(this->sp);
}
