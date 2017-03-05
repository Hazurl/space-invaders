#include "Game.h"

#include <iostream>

#define PLAYER_POS_Y_OFFSET 100

Game::Game() :
    state(State::MENU) {

    this->window = sf::RenderWindow window (
                       sf::VideoMode(WIDTH, HEIGHT),
                       "Space Invaders", 
                       sf::Style::Close | sf::Style::Titlebar
                   );
    this->window.setFramerateLimit(FPS);
    this->clock = sf::Clock();

    this->screenInnerCollider = sf::IntRect(0, 0, WIDTH, HEIGHT);
    this->invManager = InvadersManager();

    // Font
    if (!this->main_font.loadFromFile(FONT_PATH("pixelmix/pixelmix.ttf"))) {
        std::cerr << "Impossible d'ouvrir la police d'ecriture principale" << std::endl;
        exit(1);
    }

    // Sprite
    this->title.setTexture(Loader::get().getTexture(IMAGE_PATH("title.bmp")));
    this->title.setPosition(this->width / 2 - this->title.getTextureRect().width / 2,
                            this->height * 0.2);
} 

Game::~Game () {}

void Game::Run () {
    while (this->window.isOpen()) {
        /* INPUT - EVENT */
        sf::Event event;
        while (this->window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        Input::get().updateButtons();

        /* UPDATE */
        this->update((long)this->clock.restart().asMilliseconds() * SPEED);

        /* DRAW */
        window.clear();
        this->draw();
        window.display();
    }
}

void Game::update(long deltaTime) {
    switch (this->state) {
        case State::PLAYING :
        /* INPUT */
            if (Input::get().isJustPressed(Input::Button::pause))
                this->setState(State::PAUSE);

            this->env.update(deltatTime);
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

void Game::draw () {
    switch (this->state) {
        case State::PLAYING :
            this->env.draw(this->window);
        break;

        case State::PAUSE :
            // Draw game in background
            this->state = State::PLAYING;
            this->draw();
            this->state = State::PAUSE;

            this->window.draw(
                this->textPosition(
                    this->createText("PAUSE", 40),
                    0.5, 
                    0.7
                )
            );
        break;

        case State::MENU :
            this->window.draw(title);

            this->window.draw(
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
        this->env.initialize();

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