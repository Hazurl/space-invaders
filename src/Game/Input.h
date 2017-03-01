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
    bool isJustPressed (Input::Button but);
    bool isReleased (Input::Button but);

private :

    std::map<Input::Button, bool> lastButtonMap;
    std::map<Input::Button, bool> buttonMap;

    std::map<Input::Button, std::vector<sf::Keyboard::Key>> keysMap; // which keyboard keys corresponds to each action
};

#endif