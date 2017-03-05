#include "Environement.h"

Environement::Environement (sf::IntRect screenInnerCollider) :
    border(screenInnerCollider) {

}

Environement::~Environement() {
    if (this->player)
        delete player;
}

void Environement::initialize () {
    this->score = 0;
    this->ticks = 0;

    this->player = new Player("player_0.bmp", this->border.width / 2, this->border.height - PLAYER_POS_Y_OFFSET);
    
    this->invManager.Init(11, DEFAULT_INV_PATTERN);
}

void Environement::update(long deltaTime) {
    /* TICKS */
    this->ticksDeltaTime += deltaTime;

    if (this->ticksDeltaTime >= TICKS_TIME) {
        ticksDeltaTime -= TICKS_TIME;
        this->onTick();
    }

    /* UPDATE POSITION */
    this->player->update(deltaTime, this->border);
    this->invManager.update(deltaTime, this->border);
}

void Environement::onTick () {
    this->ticks++;
    this->invManager.onTick();
}

void Environement::draw (sf::RenderWindow const* window) {
    this->player->draw(window);
    this->invManager.draw(window);
}