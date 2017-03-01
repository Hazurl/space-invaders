#include "Game.h"

#include <iostream>

#define SPACE_BETWEEN_INV_X 35 
#define SPACE_BETWEEN_INV_Y 40 

#define INV_POS_Y 5
#define PLAYER_POS_Y_OFFSET 100

Game::Game(sf::RenderWindow & window, unsigned int width, unsigned int height) :
    window(&window), width(width), height(height), player(nullptr), playerBullet(nullptr), invBullet(nullptr), state(State::MENU) {

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

    while (!this->invaders.empty()) {
        delete this->invaders.back();
        this->invaders.pop_back();
    }
}

void Game::initialize () {
    this->score = 0;
    this->life = 3;

    this->ticks = 0;

    this->player = new SpaceShip("player_0.bmp", this->width / 2, this->height - PLAYER_POS_Y_OFFSET);
    for (int i = 1; i < 12; ++i) {
        float posX = SPACE_BETWEEN_INV_X * i;
        this->invaders.push_back(new SpaceShip("inv_a.bmp", posX, INV_POS_Y)); // rangé du fond
        this->invaders.push_back(new SpaceShip("inv_b.bmp", posX, INV_POS_Y + SPACE_BETWEEN_INV_Y)); // rangé du milieu
        this->invaders.push_back(new SpaceShip("inv_b.bmp", posX, INV_POS_Y + SPACE_BETWEEN_INV_Y * 2)); // de meme
        this->invaders.push_back(new SpaceShip("inv_c.bmp", posX, INV_POS_Y + SPACE_BETWEEN_INV_Y * 3)); // seconde rangé
        this->invaders.push_back(new SpaceShip("inv_c.bmp", posX, INV_POS_Y + SPACE_BETWEEN_INV_Y * 4)); // première rangé
    }
}

void Game::update(Input input, long deltaTime) {
    switch (this->state) {
        case State::PLAYING : {

        /* TICKS */
            this->ticksDeltaTime += deltaTime;

            if (this->ticksDeltaTime >= TICKS_TIME) {
                ticksDeltaTime -= TICKS_TIME;
                this->nextGameTick();
            }

        /* INPUT */

            if (input.isJustPressed(Input::Button::fire))
                this->fire_player();                

            if (input.isJustPressed(Input::Button::pause))
                this->setState(State::PAUSE);

            if (input.isPressed(Input::Button::right)) {
                this->player->moveX(this->playerSpeed * deltaTime);
                float limit = this->width - this->player->getCollider().width / 2;
                if (this->player->getX() > limit)
                    this->player->setPosition(limit, this->player->getY());
            }

            if (input.isPressed(Input::Button::left)) {
                this->player->moveX(-this->playerSpeed * deltaTime);
                float limit = - this->player->getCollider().width / 2;
                if (this->player->getX() < limit)
                    this->player->setPosition(limit, this->player->getY());
            }

        /* UPDATE POSITION */

            for (auto it = this->invaders.begin(); it != this->invaders.end(); ++it)
                (*it)->update(this->invadersXSpeed * deltaTime);
                
            if (this->invadersCollideWithBorders()) {
                for (auto inv = this->invaders.begin(); inv != this->invaders.end(); ++inv) {
                    (*inv)->invertX();
                    (*inv)->moveY(this->invadersYSpeed);
                    (*inv)->update(this->invadersXSpeed * deltaTime * 2);
                }
            }

            if (this->playerBullet)
                this->playerBullet->update(bulletSpeed * deltaTime);

            if (this->invBullet)
                this->invBullet->update(bulletSpeed * deltaTime);

        break;

        } case State::PAUSE :
            if (input.isJustPressed(Input::Button::pause))
                this->setState(State::PLAYING);
        break;

        case State::MENU :
            if (input.isJustPressed(Input::Button::start))
                this->setState(State::PLAYING);
        break; 
    }
}

void Game::fire_player() {
    if (this->playerBullet != nullptr)
        return;

    this->playerBullet = new Bullet("shot.bmp", this->player->getX() 
                                                - Settings::get().getImageSettings("shot.bmp").width / 2
                                                + this->player->getCollider().width / 2, this->player->getY());
}

void Game::fire_invaders() {

}

void Game::nextGameTick () {
    this->ticks++;

    // SpaceShip Animation
    for (int i = this->invaders.size() -1; i >= 0; --i)
        this->invaders.at(i)->nextFrame();
}

void Game::draw () {
    switch (this->state) {
        case State::PLAYING : {
            this->player->draw(this->window);
            for (int i = this->invaders.size() -1; i >= 0; --i)
                this->invaders.at(i)->draw(this->window);

            if (this->playerBullet)
                this->playerBullet->draw(this->window);

            if (this->invBullet)
                this->invBullet->draw(this->window);
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

bool Game::invadersCollideWithBorders() {
    for (auto inv = this->invaders.begin(); inv != this->invaders.end(); ++inv) {
        sf::FloatRect collider = (*inv)->getCollider();
        if (collider.left < 0 || collider.left + collider.width > this->width) {
            return true;
        }
    }
    return false;
}

sf::Text Game::createText (std::string text, unsigned int size) {
    sf::Text txt;
    txt.setFont(this->main_font);
    txt.setString(text);
    txt.setCharacterSize(size);
    txt.setColor(sf::Color::White);

    return txt;
}
