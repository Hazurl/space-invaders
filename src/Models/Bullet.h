#ifndef __BULLET_H__
#define __BULLET_H__

#include "../Utilities/Loader.h"
#include "../Utilities/Define.h"
#include "../Utilities/Settings.h"
#include "GameObject.h"

#include <string>
#include <SFML/Graphics.hpp>

class Bullet : public GameObject {
public :
/*              CONSTRUCTORS                                                    */
    Bullet (std::string const& path, float x = 0, float y = 0, bool move_down = false);

/*              DESTRUCTOR                                                      */
    ~Bullet ();

/*              UPDATE                                                          */
    void update (float speed);
    void draw(sf::RenderWindow* window);

private :
    bool move_down;
};

#endif
