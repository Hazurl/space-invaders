#ifndef __ENVIRONEMENT_H__
#define __ENVIRONEMENT_H__

#include "Game.h"
#include "../Models/SpaceShip/SpaceShip.h"
#include "../Models/SpaceShip/Player.h"
#include "../Models/Bullet.h"
#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "../Utilities/Input.h"
#include "InvadersManager.h"

#include <SFML/Graphics.hpp>

class Environement {
public:
                            Environement(sf::IntRect screenInnerCollider);
                            ~Environement();
    void                    initialize();

    void                    update(long deltaTime);
    void                    onTick ();

    void                    draw(sf::RenderWindow* const window);

private:
    unsigned int            score = 0;
    sf::IntRect             border;
    Player*                 player = nullptr;
    InvadersManager         invManager;

    unsigned long           ticks = 0;
    unsigned long           ticksDeltaTime = 0;
};

#endif