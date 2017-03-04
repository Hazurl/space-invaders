#include "SpaceShip.h"

/*
   ============================ 
   ======= CONSTRUCTORS ======= 
   ============================ 
*/

SpaceShip::SpaceShip (std::string const& imgName, float x, float y, int life, float speed) 
    : GameObject(imgName, x, y), life(life), speed(speed) {
}

/*
   ============================ 
   ======== DESTRUCTOR ======== 
   ============================ 
*/

SpaceShip::~SpaceShip() {}

/*
   ============================ 
   ========== METHODS ========= 
   ============================ 
*/

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

void SpaceShip::setLife (int life) {
    this->life = life;
}

void SpaceShip::setSpeed (float speed) {
    this->speed = speed;
}

/*
   ============================ 
   ========== GETTER ========== 
   ============================ 
*/

int SpaceShip::getLife () {
    return this->life;
}

float SpaceShip::getSpeed () {
    return this->speed;
}