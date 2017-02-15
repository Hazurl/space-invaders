#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.hpp"

enum class State { PAUSE, PLAYING, MENU };

class Game {
public :
    Game(sf::RenderWindow & window);
    ~Game();

    void initialize();
    void update();
    void onEvent(sf::Event::EventType const& type, sf::Event const& event);
    void draw();

private :
    sf::RenderWindow* window;

    unsigned int score;
    unsigned int life;

    float invadersSpeed;

    SpaceShip* player;
    std::vector<SpaceShip* > invaders;

    State state;
};

#endif