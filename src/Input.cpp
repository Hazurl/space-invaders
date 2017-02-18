#include "Input.h"

Input::Input () {
    this->keyMap[Button::up]        = sf::Keyboard::Key::Up;
    this->keyMap[Button::down]      = sf::Keyboard::Key::Down;
    this->keyMap[Button::right]     = sf::Keyboard::Key::Right;
    this->keyMap[Button::left]      = sf::Keyboard::Key::Left;
    this->keyMap[Button::fire]      = sf::Keyboard::Key::Space;
    this->keyMap[Button::pause]     = sf::Keyboard::Key::P;
    this->keyMap[Button::start]     = sf::Keyboard::Key::Space;

    this->buttonMap[Button::up]     = false;
    this->buttonMap[Button::down]   = false;
    this->buttonMap[Button::right]  = false;
    this->buttonMap[Button::left]   = false;
    this->buttonMap[Button::fire]   = false;
    this->buttonMap[Button::pause]  = false;
    this->buttonMap[Button::start]  = false;
}

Input::~Input () {

}

void Input::updateButtons () {
    this->updateButton(Button::up);
    this->updateButton(Button::down);
    this->updateButton(Button::right);
    this->updateButton(Button::left);
    this->updateButton(Button::fire);
    this->updateButton(Button::pause);
    this->updateButton(Button::start);
}

void Input::updateButton (Button but) {
    this->buttonMap[but] = sf::Keyboard::isKeyPressed(this->keyMap[but]);
}

bool Input::isPressed (Input::Button but) {
    return this->buttonMap[but];
}
