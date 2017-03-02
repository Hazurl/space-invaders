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

void SpaceShip::hit(int damage) {
    this->life -= damage; 
}

bool SpaceShip::isDead() {
    return this->life <= 0;
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

void SpaceShip::setLife (int life) {
    this->life = life;
}

/*
   ============================ 
   ========== GETTER ========== 
   ============================ 
*/

int SpaceShip::getLife () {
    return this->life;
}