#include "InvadersManager.h"

InvadersManager::InvadersManager() {}

InvadersManager::~InvadersManager() {
    this->deleteInvaders();
}

void InvadersManager::Init(unsigned int invColumns, std::string pattern) {
    this->deleteInvaders();

    float posY = INV_POS_Y;

    for(char& c : str) {
        std:string imgName = Settings::getImageForPattern(c);

        float posX = 0;
        for (int i = invColumns - 1; i >= 0; --i) {
            this->invaders.push_back(
                new SpaceShip(imgName, posX, posY)
            );

            posX += SPACE_BETWEEN_INV_X;
        }

        posY += SPACE_BETWEEN_INV_Y;
    }
}

void InvadersManager::update (float deltaTime, sf::IntRect screenInnerCollider) {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        (*it)->update(deltaTime, screenInnerCollider);
        
    if (this->invadersCollideWithBorders(screenInnerCollider)) {
        for (auto inv = this->invaders.begin(); inv != this->invaders.end(); ++inv) {
            (*inv)->invertX();
            (*inv)->moveDown();
            (*inv)->update(deltaTime * 2, screenInnerCollider);
        }
    }
}

void InvadersManager::onTick () {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        (*it)->nextFrame();
}

void InvadersManager::draw (sf::RenderWindow* window) {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        (*it)->draw(this->window);
}

void InvadersManager::deleteInvaders() {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        delete it;

    this->invaders.clear();
}

bool InvadersManager::invadersCollideWithBorders(sf::IntRect screenInnerCollider) {
    for (auto inv = this->invaders.begin(); inv != this->invaders.end(); ++inv) {
        sf::FloatRect collider = (*inv)->getCollider();
        if (collider.left < screenInnerCollider.left || 
            collider.left + collider.width > screenInnerCollider.left + screenInnerCollider.width)

            return true;
    }
    return false;
}

std::vector<Invaders*>::iterator InvadersManager::collideWithInvaders(GameObject* gm) {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        if (gm->collideWith(*it))
            return it;

    return this->invaders.end();
}
