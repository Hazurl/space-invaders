#ifndef __GAME_H__
#define __GAME_H__

#include "SpaceShip.h"
#include "Loader.h"
#include "Input.h"

#include <SFML/Graphics.hpp>
#include <vector>

enum class State { PAUSE, PLAYING, MENU };

class Game {
public :
    Game(sf::RenderWindow & window, unsigned int width, unsigned int height);
    ~Game();

    void initialize();
    void update(Input input, long deltaTime);
    void draw();
    void setState(State st);

private :
    bool invadersCollideWithBorders();

    sf::RenderWindow* window;
    float width;
    float height;

    unsigned int score;
    unsigned int life;

    float invadersSpeed = 1;

    SpaceShip* player;
    std::vector<SpaceShip* > invaders;

    State state;

    // Font
    sf::Font main_font; 
 
    // Sprite

        // TITRE
    sf::Sprite title;
};

#endif