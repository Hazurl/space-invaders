#ifndef __GAME_H__
#define __GAME_H__

#include "../Models/SpaceShip.h"
#include "../Utilities/Loader.h"
#include "Input.h"
#include "../Models/Bullet.h"
#include "../Utilities/Define.h"

#include <SFML/Graphics.hpp>
#include <vector>

#define TICKS_TIME 500

enum class State { PAUSE, PLAYING, MENU };

class Game {
public :
    Game(sf::RenderWindow & window, unsigned int width, unsigned int height);
    ~Game();

    void initialize();

    void update(Input input, long deltaTime);
    void fire_player ();
    void fire_invaders ();
    void nextGameTick ();

    void draw();

    void setState(State st);

private :
    bool invadersCollideWithBorders();
    GameObject* collideWithInvaders(GameObject* gm);
    sf::Text createText (std::string text, unsigned int size);

    sf::RenderWindow* window;
    float width;
    float height;

    unsigned int score;
    unsigned int life;

    float invadersXSpeed = 0.1;
    float invadersYSpeed = 5;
    float playerSpeed = 0.3;
    float bulletSpeed = 0.2;

    unsigned long ticks = 0;
    unsigned long ticksDeltaTime = 0;

    SpaceShip* player;
    Bullet* playerBullet;
    
    std::vector<SpaceShip* > invaders;
    Bullet* invBullet;

    State state;

    // Font
    sf::Font main_font; 
 
    // Sprite

        // TITRE
    sf::Sprite title;
};

#endif