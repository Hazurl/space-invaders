#include "Invader.h"

Invader::Invader (std::string const& imgName, float x, float y, int life, float speed)
    :   SpaceShip(imgName, x, y, life, speed) {}

Invader::~Invader() {}

void Invader::update(float speed, sf::IntRect screenInnerCollider) {

}