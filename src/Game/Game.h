#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>

#include "Environement.h"
#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "../Utilities/Input.h"

enum class State { PAUSE, PLAYING, MENU };

class Environement;

class Game {
public:
                            Game();
                            ~Game();

    void                    setState(State st);
    void                    run ();

private:
    void                    draw ();
    void                    update(long deltaTime);

    sf::Text                createText (std::string text, unsigned int size);
    sf::Text                textPosition(sf::Text txt, float xCoef, float yCoef);

    sf::RenderWindow*       window = nullptr;
    sf::IntRect             screenInnerCollider;

    sf::Clock               clock;

    Environement*           env;
    
    State                   state;

    // Font
    sf::Font                main_font; 
 
    // Sprite
    sf::Sprite              title;
};

#endif