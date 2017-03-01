#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "../Utilities/Settings.h"
#include "GameObject.h"

#include <string>
#include <SFML/Graphics.hpp>

class SpaceShip : public GameObject {
public :
/*              CONSTRUCTORS                                                    */
    SpaceShip (std::string const& imgName, float x = 0.0, float y = 0.0);

/*              DESTRUCTOR                                                      */
    ~SpaceShip();

/*              UPDATE                                                          */
    void update(float speed);
    void moveX(float amount);
    void moveY(float amount);
    void invertX();

/*              SETTER                                                          */
    void setPosition (float x, float y);
    void setLife (unsigned int life);

/*              GETTER                                                          */
    unsigned int getLife();

private :
    bool move_right = true;
    unsigned int life = 1;
};

#endif