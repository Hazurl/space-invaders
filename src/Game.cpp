#include "Game.h"

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

    // Sprite
    this->title.setTexture(Loader::getTexture("img/title.bmp"));
    this->title.setPosition(this->width / 2 - this->title.getTextureRect().width / 2,
                            this->height * 0.2);
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

    this->player = new SpaceShip("img/player_0.bmp", 32, this->width / 2, this->height - 50);
    for (int i = 0; i < 11; ++i) {
        this->invaders.push_back(new SpaceShip("img/inv_a.bmp", 32, this->width * i / 14, 10)); // rangé du fond
        this->invaders.push_back(new SpaceShip("img/inv_b.bmp", 32, this->width * i / 14, 60)); // rangé du milieu
        this->invaders.push_back(new SpaceShip("img/inv_b.bmp", 32, this->width * i / 14, 110)); // de meme
        this->invaders.push_back(new SpaceShip("img/inv_c.bmp", 32, this->width * i / 14, 160)); // seconde rangé
        this->invaders.push_back(new SpaceShip("img/inv_c.bmp", 32, this->width * i / 14, 210)); // première rangé
    }
}

void Game::update(Input input) {
    switch (this->state) {
        case State::PLAYING :
            if (input.isPressed(Input::Button::right))
                this->player->moveX(10);
            if (input.isPressed(Input::Button::left))
                this->player->moveX(-10);
            for (int i = this->invaders.size() -1; i >= 0; --i)
                this->invaders.at(i)->update(this->invadersSpeed);
        break;

        case State::PAUSE :
        break;

        case State::MENU :
            if (input.isPressed(Input::Button::start))
                this->setState(State::PLAYING);
        break; 
    }
}

void Game::draw () {
    switch (this->state) {
        case State::PLAYING :
            this->player->draw(this->window);
            for (int i = this->invaders.size() -1; i >= 0; --i)
                this->invaders.at(i)->draw(this->window);
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

            float w = press_space_text.getGlobalBounds().width;

            press_space_text.setPosition(this->width / 2 - w / 2,
                                         this->height * 0.7);

            this->window->draw(press_space_text);
        break; 
    }
}

void Game::setState(State st) {
    if (this->state == st)
        return;

    if (st == State::PLAYING) {
        this->state = st;
        this->initialize();
    }
    //std::cout << "Changement d'état en " << (st == State::PAUSE ? "Pause" : st == State::PLAYING ? "Playing" : "Menu") << std::endl;
}