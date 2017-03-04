#ifndef __INVADERS_MANAGER_H__
#define __INVADERS_MANAGER_H__

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Utilities/Define.h"
#include "../Models/SpaceShip/SpaceShip.h"
#include "../Models/SpaceShip/Invader.h"

class InvadersManager {
public:
    InvadersManager();
    ~InvadersManager();

    void Init(unsigned int invColumns, std::string pattern); // pattern is like "abbcc"

    void update (float deltaTime, sf::IntRect screenInnerCollider);
    void onTick (); // animation

    void draw (sf::RenderWindow* window);

private:
    std::vector<Invader* > invaders;
};

#endif