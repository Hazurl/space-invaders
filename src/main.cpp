#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Loader.h"

#define WIDTH 800
#define HEIGHT 450

int main()
{
    sf::RenderWindow window (sf::VideoMode(WIDTH, HEIGHT), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(120);

    Game game(window, WIDTH, HEIGHT);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            game.onEvent(event.type, event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.update();

        window.clear();

        game.draw();

        window.display();
    }

    Loader::clean();

    return 0;
}