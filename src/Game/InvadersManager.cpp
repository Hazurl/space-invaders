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

}

void InvadersManager::onTick () {

}

void InvadersManager::draw (sf::RenderWindow* window) {

}

void InvadersManager::deleteInvaders() {
    for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
        delete it;

    this->invaders.clear();
}