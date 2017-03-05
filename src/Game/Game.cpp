#include "Game.h"

#include <iostream>

#define PLAYER_POS_Y_OFFSET 100

Game::Game(sf::RenderWindow & window, unsigned int width, unsigned int height) :
    window(&window), width(width), height(height), state(State::MENU) {

    this->screenInnerCollider = sf::IntRect(0, 0, width, height);
    this->invManager = InvadersManager();

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
        case State::PLAYING :

        /* TICKS */
            this->ticksDeltaTime += deltaTime;

            if (this->ticksDeltaTime >= TICKS_TIME) {
                ticksDeltaTime -= TICKS_TIME;
                this->onTick();
            }

        /* INPUT */
            if (Input::get().isJustPressed(Input::Button::pause))
                this->setState(State::PAUSE);

        /* UPDATE POSITION */
            this->player->update(deltaTime, this->screenInnerCollider);
            this->invManager.update(deltaTime, this->screenInnerCollider);

        break;

        case State::PAUSE :
            if (Input::get().isJustPressed(Input::Button::pause))
                this->setState(State::PLAYING);
        break;

        case State::MENU :
            if (Input::get().isJustPressed(Input::Button::start))
                this->setState(State::PLAYING);
        break; 
    }
}

void Game::onTick () {
    this->ticks++;
    this->invManager.onTick();
}

void Game::draw () {
    switch (this->state) {
        case State::PLAYING :
            this->player->draw(this->window);
            this->invManager.draw(this->window);
        break;

        case State::PAUSE :
            // Draw game in background
            this->state = State::PLAYING;
            this->draw();
            this->state = State::PAUSE;

            this->window->draw(
                this->textPosition(
                    this->createText("PAUSE", 40),
                    0.5, 
                    0.7
                )
            );
        break;

        case State::MENU :
            this->window->draw(title);

            this->window->draw(
                this->textPosition(
                    this->createText("Press SPACE to start", 32),
                    0.5, 
                    0.7
                )
            );
        break;
    }
}

void Game::setState(State st) {
    if (st == State::PLAYING && this->state == State::MENU) // passage du menu au jeu
        this->initialize();

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

sf::Text Game::textPosition(sf::Text txt, float xCoef, float yCoef) {
    sf::FloatRect bounds = txt.getGlobalBounds();
    float w = bounds.width;
    float h = bounds.height;
    txt.setPosition(this->width * xCoef - w / 2, this->height * yCoef - h / 2);
}