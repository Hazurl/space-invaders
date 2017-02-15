#include "SpaceShip.hpp"

SpaceShip::SpaceShip () {

}

SpaceShip::~SpaceShip() {

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
