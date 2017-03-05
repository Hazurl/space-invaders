#include "Environement.h"

Environement::Environement () {}

Environement::~Environement() {
    if (this->player)
        delete player;
}

void Environement::initialize () {
    this->score = 0;
    this->ticks = 0;

    this->player = new Player("player_0.bmp", this->width / 2, this->height - PLAYER_POS_Y_OFFSET);
    
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
    this->player->update(deltaTime, this->screenInnerCollider);
    this->invManager.update(deltaTime, this->screenInnerCollider);
}

void Environement::onTick () {
    this->ticks++;
    this->invManager.onTick();
}

void draw (sf::RenderWindow const& window) {
    this->player->draw(window);
    this->invManager.draw(window);
}