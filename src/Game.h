#ifndef __GAME_H__
#define __GAME_H__

#include "SpaceShip.h"

#include <SFML/Graphics.hpp>
#include <vector>

enum class State { PAUSE, PLAYING, MENU };

class Game {
public :
    Game(sf::RenderWindow & window, unsigned int width, unsigned int height);
    ~Game();

    void initialize();
    void update();
    void onEvent(sf::Event::EventType const& type, sf::Event const& event);
    void draw();
    void setState(State st);

private :
    sf::RenderWindow* window;
    float width;
    float height;

    unsigned int score;
    unsigned int life;

    float invadersSpeed;

    SpaceShip* player;
    std::vector<SpaceShip* > invaders;

    State state;

    // Font
    sf::Font main_font; 
 
    // Texture / Image

        // TITRE
    sf::Texture tx_title;
    sf::Sprite title;
};

#endif