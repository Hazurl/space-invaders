#ifndef __GAME_H__
#define __GAME_H__

#include "../Models/SpaceShip/SpaceShip.h"
#include "../Models/SpaceShip/Player.h"
#include "../Models/Bullet.h"
#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "Input.h"
#include "InvadersManager.h"

#include <SFML/Graphics.hpp>
#include <vector>

#define TICKS_TIME 500

enum class State { PAUSE, PLAYING, MENU };

class Game {
public :
    Game(sf::RenderWindow & window, unsigned int width, unsigned int height);
    ~Game();

    void initialize();

    void update(long deltaTime);
    //void fire_invaders ();
    void onTick ();

    void draw();

    void setState(State st);

private :
    //bool invadersCollideWithBorders();
    //std::vector<SpaceShip*>::iterator collideWithInvaders(GameObject* gm);
    sf::Text createText (std::string text, unsigned int size);
    sf::Text textPosition(sf::Text txt, float xCoef, float yCoef);

    sf::RenderWindow* window;
    sf::IntRect screenInnerCollider;
    float width;
    float height;

    unsigned int score;
    //unsigned int life;

    //float invadersXSpeed = 0.1;
    //float invadersYSpeed = 5;
    //float playerSpeed = 0.3;
    //float bulletSpeed = 0.2;

    unsigned long ticks = 0;
    unsigned long ticksDeltaTime = 0;

    Player* player;
    InvadersManager invManager;
    
    //std::vector<SpaceShip* > invaders;
    //Bullet* invBullet;

    State state;

    // Font
    sf::Font main_font; 
 
    // Sprite

        // TITRE
    sf::Sprite title;
};

#endif