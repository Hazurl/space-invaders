#include "Game.hpp"
#include "SpaceShip.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow & window, unsigned int width, unsigned int height) {
    this->window = &window;
    this->height = height;
    this->width = width;

    this->state = State::MENU;

    this->player = nullptr;

    // Font
    if (!this->main_font.loadFromFile("font/pixelmix/pixelmix.ttf")) {
        std::cerr << "Impossible d'ouvrir la police principale" << std::endl;
        exit(1);
    }

    // Texture / Image
    if (!this->tx_title.loadFromFile("img/title.bmp", sf::IntRect(0, 0, 246, 178))) {
        std::cerr << "Impossible d'ouvrir la texture de titre" << std::endl;
        exit(1);
    }

    this->title.setTexture(tx_title);
    this->title.setPosition(this->width / 2 - this->title.getTextureRect().width / 2,
                            this->height / 2 - this->title.getTextureRect().height / 2);
} 

Game::~Game () {
    if (this->player)
        delete this->player;

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
    if (this->state == State::PLAYING) {
        for (int i = this->invaders.size() -1; i >= 0; --i)
            this->invaders.at(i)->update(this->invadersSpeed);
    }
}

void Game::onEvent(sf::Event::EventType const& type, sf::Event const& event) {

}

void Game::draw () {
    switch (this->state) {
        case State::PLAYING :
        break;

        case State::PAUSE :
        break;

        case State::MENU :
            this->window->draw(title);

            sf::Text press_space_text;
            press_space_text.setFont(this->main_font);
            press_space_text.setString("Press SPACE to start");
            press_space_text.setCharacterSize(32);
            press_space_text.setColor(sf::Color::White);

            this->window->draw(press_space_text);
        break; 
    }
}