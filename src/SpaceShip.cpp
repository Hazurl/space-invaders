#include "SpaceShip.h"

#include <iostream>

SpaceShip::SpaceShip (std::string const& tx_path, unsigned int width, unsigned int height, unsigned int first_x,
                      unsigned int first_y, unsigned int second_x, unsigned int second_y, float x, float y) {
    this->setSpriteFromFile(tx_path);
    this->x = x;
    this->y = y;

    this->frame_0.x = first_x;
    this->frame_0.y = first_y;
    this->frame_1.x = second_x;
    this->frame_1.y = second_y;

    this->size.x = width;
    this->size.y = height;
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::setSpriteFromFile(std::string const& path) {
    this->sp.setTexture(*Loader::getTexture(path));
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

void SpaceShip::draw (sf::RenderWindow* window) {
    sf::IntRect rect(this->frame_0, this->size);
    sp.setTextureRect(rect);
    this->sp.setPosition(this->x, this->y);
    window->draw(this->sp);
}
