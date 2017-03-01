#include "GameObject.h"

/*
   ============================ 
   ======= CONSTRUCTORS ======= 
   ============================ 
*/

GameObject::GameObject(std::string const& imgName, float x, float y) 
    : this->collider(sf::FloatRect(x, y, 0, 0)) {
    
    this->setSpriteFromFile(imgName);
}

/*
   ============================ 
   ======== DESTRUCTOR ======== 
   ============================ 
*/

GameObject::~GameObject() {}

/*
   ============================ 
   =========== DRAW =========== 
   ============================ 
*/

void GameObject::setSpriteFromFile(std::string const& imgName) {
    this->sp.setTexture( Loader::get().getTexture( IMAGE_PATH("") + imgName ) );

    ImageSettings sett = Settings::get().getImageSettings(imgName);

    this->collider.width = sett.width;
    this->collider.height = sett.height;

    this->framesCount = sett.frame;
    this->currentFrame = 0;
}

void GameObject::nextFrame() {
    this->currentFrame = (++this->currentFrame) % this->framesCount;
}

void GameObject::draw (sf::RenderWindow* window) {
    // Place the rect on the right position to find the correct frame
    sf::IntRect rect(sf::Vector2i(this->getWidth() * this->currentFrame, 0), // pos
                     sf::Vector2i(this->getWidth(), this->getHeight())); // size

    // Set the frame from the texture
    sp.setTextureRect(rect);

    // Set the sprite at the the right position
    this->sp.setPosition(this->getX(), this->getY());

    // Draw it finally
    window->draw(this->sp);
}

/*
   ============================ 
   ========== GETTER ========== 
   ============================ 
*/

float GameObject::getX() {
    return this->collider.left;
}

float GameObject::getY() {
    return this->collider.top;
}

int GameObject::getWidth() {
    return this->collider.width;
}

int GameObject::getHeight() {
    return this->collider.height;
}

sf::FloatRect GameObject::getCollider () {
    return this->collider;
}