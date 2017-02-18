#ifndef __INPUT_H__
#define __INPUT_H__

#include <map>
#include <SFML/Graphics.hpp>

class Input {
public :
    enum class Button {
        up,
        down,
        right,
        left,
        fire,
        pause,
        start
    };

    Input ();
    ~Input ();

    void updateButtons ();
    void updateButton (Button but);
    bool isPressed (Button but);

private :

    std::map<Input::Button, bool> buttonMap;
    std::map<Input::Button, sf::Keyboard::Key> keyMap;
};

#endif