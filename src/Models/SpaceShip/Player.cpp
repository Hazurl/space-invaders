#include "Player.h"

Player::Player (std::string const& imgName, float x, float y, int life, float speed)
    :   SpaceShip(imgName, x, y, life, speed) {}

Player::~Player() {
    if (this->bullet)
        delete this->bullet;
}

void Player::update(float deltaTime, sf::IntRect screenInnerCollider) {
    if (Input::get().isJustPressed(Input::Button::fire))
        this->fire();                

    if (Input::get().isPressed(Input::Button::right)) {
        this->collider.left += this->speed * deltaTime;
        float limit = this->getWidth() - this->getWidth() / 2;
        if (this->getX() < limit)
            this->collider.left = limit;
    }

    if (Input::get().isPressed(Input::Button::left)) {
        this->collider.left -= this->speed * deltaTime;
        float limit = -this->getWidth() / 2;
        if (this->getX() < limit)
            this->collider.left = limit;
    }

    if (this->bullet)
        this->bullet->update(deltaTime, screenInnerCollider);
}

void Player::fire () {
    if (this->bullet != nullptr)
        return;

    this->bullet = new Bullet("shot.bmp", this->getX() 
                                          - Settings::get().getImageSettings("shot.bmp").width / 2
                                          + this->getWidth() / 2, this->getY());
}

void Player::draw (sf::RenderWindow* window) {
    GameObject::draw(window);
    if (this->bullet)
        this->bullet->draw(window);
}