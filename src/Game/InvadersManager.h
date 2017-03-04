#ifndef __INVADERS_MANAGER_H__
#define __INVADERS_MANAGER_H__

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Utilities/Define.h"
#include "../Utilities/Settings.h"
#include "../Models/SpaceShip/SpaceShip.h"
#include "../Models/SpaceShip/Invader.h"

#define SPACE_BETWEEN_INV_X 35 
#define SPACE_BETWEEN_INV_Y 40 
#define INV_POS_Y 5

class InvadersManager {
public:
    InvadersManager();
    ~InvadersManager();

    void Init(unsigned int invColumns, std::string pattern); // pattern is like "abbcc"

    void update (float deltaTime, sf::IntRect screenInnerCollider);
    void onTick (); // animation

    void draw (sf::RenderWindow* window);

    std::vector<Invader*>::iterator collideWithInvaders(GameObject* gm);

private:
    std::vector<Invader* > invaders;

    void deleteInvaders();
    bool invadersCollideWithBorders(sf::IntRect screenInnerCollider);
};

#endif