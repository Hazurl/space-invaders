#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "SpaceShip.h"
#include "../Bullet.h"
#include "../../Utilities/Input.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player : public SpaceShip {
public:
/*              CONSTRUCTORS                                                    */
                    Player (std::string const& imgName, float x = 0.0, float y = 0.0, int life = 0, float speed = 1.0);

/*              DESTRUCTOR                                                      */
                    ~Player ();

/*              UPDATE                                                          */
    void            update (float deltaTime, sf::IntRect screenInnerCollider);
    virtual void    draw (sf::RenderWindow* window);

/*              SETTER                                                          */

/*              GETTER                                                          */

private:

    void            fire ();

    Bullet* bullet = nullptr;
};

#endif