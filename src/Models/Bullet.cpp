#include "Bullet.h"

#include <iostream>

/*
   ============================ 
   ======= CONSTRUCTORS ======= 
   ============================ 
*/

Bullet::Bullet (std::string const& imgName, float x, float y, bool move_down) :
    GameObject(imgName, x, y), move_down(move_down) {
    if(!move_down)
        this->rotation = 180;
}

/*
   ============================ 
   ======== DESTRUCTOR ======== 
   ============================ 
*/

Bullet::~Bullet () {}

/*
   ============================ 
   ========== UPDATE ========== 
   ============================ 
*/

void Bullet::update (float speed), sf::IntRect screenInnerCollider {
    if (move_down)
        this->collider.top += speed;
    else
        this->collider.top -= speed;
}
