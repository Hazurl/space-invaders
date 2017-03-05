#include "Input.h"

Input& Input::get() {
    static Input instance;
    return instance;
}

Input::Input () {
    this->keysMap[Button::up]            = { sf::Keyboard::Key::Up };
    this->keysMap[Button::down]          = { sf::Keyboard::Key::Down };
    this->keysMap[Button::right]         = { sf::Keyboard::Key::Right };
    this->keysMap[Button::left]          = { sf::Keyboard::Key::Left };
    this->keysMap[Button::fire]          = { sf::Keyboard::Key::Space };
    this->keysMap[Button::pause]         = { sf::Keyboard::Key::P, sf::Keyboard::Key::Escape };
    this->keysMap[Button::start]         = { sf::Keyboard::Key::Space };

    this->buttonMap[Button::up]         = this->lastButtonMap[Button::up]     = false;
    this->buttonMap[Button::down]       = this->lastButtonMap[Button::down]   = false;
    this->buttonMap[Button::right]      = this->lastButtonMap[Button::right]  = false;
    this->buttonMap[Button::left]       = this->lastButtonMap[Button::left]   = false;
    this->buttonMap[Button::fire]       = this->lastButtonMap[Button::fire]   = false;
    this->buttonMap[Button::pause]      = this->lastButtonMap[Button::pause]  = false;
    this->buttonMap[Button::start]      = this->lastButtonMap[Button::start]  = false;
}

Input::~Input () {}

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

    bool isPress = false;
    for (auto it = this->keysMap[but].begin(); it < this->keysMap[but].end(); ++it)
        isPress = isPress || sf::Keyboard::isKeyPressed(*it);

    this->buttonMap[but] = isPress;
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