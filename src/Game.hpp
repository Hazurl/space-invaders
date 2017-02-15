#include <SFML/Graphics.hpp>

class Game {
public :
    Game(sf::RenderWindow & window);

    initialize();
    onEvent(sf::Event::EventType const& type, sf::Event const& event);
    draw();

private :
    sf::RenderWindow* window;

    unsigned int score;
    unsigned int life;
}