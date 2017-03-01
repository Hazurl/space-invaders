#include "SpaceShip.h"

#include <iostream>

/*
   ============================ 
   ======= CONSTRUCTORS ======= 
   ============================ 
*/

SpaceShip::SpaceShip (std::string const& imgName, float x, float y) 
    : GameObject(imgName, x, y) {
}

/*
   ============================ 
   ======== DESTRUCTOR ======== 
   ============================ 
*/

SpaceShip::~SpaceShip() {}

/*
   ============================ 
   ========== UPDATE ========== 
   ============================ 
*/

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

/*
   ============================ 
   ========== SETTER ========== 
   ============================ 
*/

void SpaceShip::setPosition (float x, float y) {
    this->collider.left = x;
    this->collider.top = y;
}

void SpaceShip::setLife (unsigned int life) {
    this->life = life;
}

/*
   ============================ 
   ========== GETTER ========== 
   ============================ 
*/

unsigned int SpaceShip::getLife () {
    return this->life;
}