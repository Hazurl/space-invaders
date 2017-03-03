#include "SpaceShip.h"
#include "../Bullet.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player : public SpaceShip {
public:
/*              CONSTRUCTORS                                                    */
                    Player (std::string const& imgName, float x = 0.0, float y = 0.0, int life = 0, float speed = 1.0);

/*              DESTRUCTOR                                                      */
                    ~Player ();

/*              UPDATE                                                          */
    void            update (float speed, sf::IntRect screenInnerCollider);

/*              SETTER                                                          */

/*              GETTER                                                          */

private:

    void            fire ();

    Bullet* bullet = nullptr;
};

#endif