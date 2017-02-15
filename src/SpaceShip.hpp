#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__

class SpaceShip {
public :
    SpaceShip ();
    ~SpaceShip();

    void update(float speed);
    void moveX(float amount);
    void moveY(float amount);
    void invertX();

private :
    float x;
    float y;
    bool move_right;
};

#endif