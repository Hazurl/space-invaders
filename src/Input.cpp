#include "Input.h"

Input::Input () {
    this->keyMap[Button::up]            = sf::Keyboard::Key::Up;
    this->keyMap[Button::down]          = sf::Keyboard::Key::Down;
    this->keyMap[Button::right]         = sf::Keyboard::Key::Right;
    this->keyMap[Button::left]          = sf::Keyboard::Key::Left;
    this->keyMap[Button::fire]          = sf::Keyboard::Key::Space;
    this->keyMap[Button::pause]         = sf::Keyboard::Key::P;
    this->keyMap[Button::start]         = sf::Keyboard::Key::Space;

    this->buttonMap[Button::up]         = this->lastButtonMap[Button::up]     = false;
    this->buttonMap[Button::down]       = this->lastButtonMap[Button::down]   = false;
    this->buttonMap[Button::right]      = this->lastButtonMap[Button::right]  = false;
    this->buttonMap[Button::left]       = this->lastButtonMap[Button::left]   = false;
    this->buttonMap[Button::fire]       = this->lastButtonMap[Button::fire]   = false;
    this->buttonMap[Button::pause]      = this->lastButtonMap[Button::pause]  = false;
    this->buttonMap[Button::start]      = this->lastButtonMap[Button::start]  = false;
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
    this->lastButtonMap[but] = this->buttonMap[but];
    this->buttonMap[but] = sf::Keyboard::isKeyPressed(this->keyMap[but]);
}

bool Input::isPressed (Input::Button but) {
    return this->buttonMap[but];
}

bool Input::isJustPressed (Input::Button but) {
    return !this->lastButtonMap[but] && this->buttonMap[but];
}

bool Input::isReleased (Input::Button but) {
    return this->lastButtonMap[but] && !this->buttonMap[but];
}