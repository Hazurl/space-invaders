#include "Bullet.h"

#include <iostream>

/*
   ============================ 
   ======= CONSTRUCTORS ======= 
   ============================ 
*/

Bullet::Bullet (std::string const& imgName, float x, float y, bool move_down) :
    GameObject(imgName, x, y), move_down(move_down) {
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

void Bullet::update (float speed) {
    if (move_down)
        this->collider.top += speed;
    else
        this->collider.top -= speed;
}

/*
   ============================ 
   =========== DRAW =========== 
   ============================ 
*/

void Bullet::draw(sf::RenderWindow* window) {
    // Place the rect on the right position to find the correct frame
    sf::IntRect rect(this->getWidth() * this->currentFrame, 0,  // pos
                     this->getWidth(), this->getHeight()     ); // size

    // Set the frame from the texture
    sp.setTextureRect(rect);

    // Set the sprite at the the right position
    this->sp.setPosition(this->getX(), this->getY());

    // Face the correct durection
    if (!move_down) {
        this->sp.setOrigin(this->getWidth() / 2, this->getHeight() / 2);
        this->sp.setRotation(180);
    }

    // Draw it finally
    window->draw(this->sp);
}
