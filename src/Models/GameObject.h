#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <SFML/Graphics.hpp>
#include <string>
#include "../Utilities/Loader.h"
#include "../Utilities/Settings.h"

class GameObject {
public: 
/*              CONSTRUCTORS                                                    */
                    GameObject(std::string const& imgName, float x = 0.0, float y = 0.0);

/*              DESTRUCTOR                                                      */
    virtual         ~GameObject();

/*              DRAW                                                            */
    void            setSpriteFromFile(std::string const& imgName);
    void            nextFrame();

    virtual void    update(float speed) = 0;
    virtual void    draw (sf::RenderWindow* window);

/*              GETTER                                                          */
    float           getX();
    float           getY();
    int             getWidth();
    int             getHeight();
    sf::FloatRect   getCollider ();

protected:
    sf::Sprite      sp;
    sf::FloatRect   collider;

    unsigned int    framesCount;
    unsigned int    currentFrame;
};

#endif