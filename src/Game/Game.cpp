#include "Game.h"

#include <iostream>

#define PLAYER_POS_Y_OFFSET 100

Game::Game(sf::RenderWindow & window, unsigned int width, unsigned int height) :
    window(&window), width(width), height(height)/*, player(nullptr), playerBullet(nullptr), invBullet(nullptr)*/, state(State::MENU) {

    // Font
    if (!this->main_font.loadFromFile(FONT_PATH("pixelmix/pixelmix.ttf"))) {
        std::cerr << "Impossible d'ouvrir la police principale" << std::endl;
        exit(1);
    }

    // Sprite
    this->title.setTexture(Loader::get().getTexture(IMAGE_PATH("title.bmp")));
    this->title.setPosition(this->width / 2 - this->title.getTextureRect().width / 2,
                            this->height * 0.2);
} 

Game::~Game () {
    if (this->player)
        delete this->player;
}

void Game::initialize () {
    this->score = 0;
    this->ticks = 0;

    this->player = new Player("player_0.bmp", this->width / 2, this->height - PLAYER_POS_Y_OFFSET);
    
    this->invManager.Init(11, DEFAULT_INV_PATTERN);
}

void Game::update(long deltaTime) {
    switch (this->state) {
        case State::PLAYING : {

        /* TICKS */
            this->ticksDeltaTime += deltaTime;

            if (this->ticksDeltaTime >= TICKS_TIME) {
                ticksDeltaTime -= TICKS_TIME;
                this->nextGameTick();
            }

        /* INPUT */
            if (Input::get().isJustPressed(Input::Button::pause))
                this->setState(State::PAUSE);

        /* UPDATE POSITION */
/*
            if (this->playerBullet) {
                this->playerBullet->update(bulletSpeed * deltaTime);
                auto inv = this->collideWithInvaders(playerBullet);
                if (inv != this->invaders.end()) {
                    delete playerBullet;
                    playerBullet = nullptr;

                    (*inv)->hit(1);
                    if ((*inv)->isDead()) {
                        delete *inv;
                        this->invaders.erase(inv);
                    }
                }
            }

            if (this->invBullet)
                this->invBullet->update(bulletSpeed * deltaTime);
*/
        break;

        } case State::PAUSE :
            if (Input::get().isJustPressed(Input::Button::pause))
                this->setState(State::PLAYING);
        break;

        case State::MENU :
            if (Input::get().isJustPressed(Input::Button::start))
                this->setState(State::PLAYING);
        break; 
    }
}

void Game::nextGameTick () {
    this->ticks++;
    this->invManager.onTick();
}

void Game::draw () {
    switch (this->state) {
        case State::PLAYING : {
/*            this->player->draw(this->window);
            this->invManager.draw(this->window);

            if (this->playerBullet)
                this->playerBullet->draw(this->window);

            if (this->invBullet)
                this->invBullet->draw(this->window);*/
        break;}

        case State::PAUSE : {
            // Draw game in background
            this->state = State::PLAYING;
            this->draw();
            this->state = State::PAUSE;

            sf::Text pause_text = this->createText("PAUSE", 48);

            float w = pause_text.getGlobalBounds().width;

            pause_text.setPosition(this->width / 2 - w / 2,
                                   this->height * 0.7);

            this->window->draw(pause_text);
        break; }

        case State::MENU : {
            this->window->draw(title);

            sf::Text press_space_text = this->createText("Press SPACE to start", 32);

            float w = press_space_text.getGlobalBounds().width;

            press_space_text.setPosition(this->width / 2 - w / 2,
                                         this->height * 0.7);

            this->window->draw(press_space_text);
        break; }
    }
}

void Game::setState(State st) {
    if (this->state == st)
        return;

    if (st == State::PLAYING && this->state == State::MENU) { // passage du menu au jeu
        this->initialize();
    }

    this->state = st;
}

sf::Text Game::createText (std::string text, unsigned int size) {
    sf::Text txt;
    txt.setFont(this->main_font);
    txt.setString(text);
    txt.setCharacterSize(size);
    txt.setColor(sf::Color::White);

    return txt;
}

