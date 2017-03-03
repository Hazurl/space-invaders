#ifndef __INVADER_H__
#define __INVADER_H__

#include "../GameObject.h"
#include "SpaceShip.h"
#include <string>
#include <SFML/Graphics.hpp>

class Invader : public SpaceShip {
public:
/*              CONSTRUCTORS                                                    */
                    Invader (std::string const& imgName, float x = 0.0, float y = 0.0, int life = 0, float speed = 1.0);

/*              DESTRUCTOR                                                      */
                    ~Invader ();

/*              UPDATE                                                          */
    void            update (float speed, sf::IntRect screenInnerCollider);

/*              SETTER                                                          */

/*              GETTER                                                          */

private:
    bool            move_right = true;
};

#endif