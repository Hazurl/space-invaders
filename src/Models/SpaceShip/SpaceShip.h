#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include "GameObject.h"

#include <string>

class SpaceShip : public GameObject {
public :
/*              CONSTRUCTORS                                                    */
    SpaceShip (std::string const& imgName, float x = 0.0, float y = 0.0, int life = 0, float speed = 1.0);

/*              DESTRUCTOR                                                      */
    ~SpaceShip();

/*              UPDATE                                                          */
    void hit(int damage);
    bool isDead();

/*              SETTER                                                          */
    void setLife (int life);
    void setSpeed (float speed);

/*              GETTER                                                          */
    int getLife();
    float getSpeed();

private :
    int life = 1;
    float speed;
};

#endif