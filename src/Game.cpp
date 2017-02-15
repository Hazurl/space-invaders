#include "Game.hpp"
#include "SpaceShip.hpp"
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow & window) {
    this->window = &window;
}

Game::~Game () {
    if (this->player)
        delete player;

    while (!this->invaders.empty()) {
        delete this->invaders.back();
        this->invaders.pop_back();
    }
}

void Game::initialize () {
    this->score = 0;
    this->life = 3;

    this->player = new SpaceShip();
}

void Game::update() {
    for (int i = this->invaders.size() -1; i >= 0; --i) {
        this->invaders.at(i)->update(this->invadersSpeed);
    }
}

void Game::onEvent(sf::Event::EventType const& type, sf::Event const& event) {

}

void Game::draw () {

}