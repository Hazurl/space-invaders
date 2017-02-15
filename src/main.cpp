/* Build
 * g++ -std=c++17 -W -c src/SpaceShip.cpp src/main.cpp -o build/main.o && g++ build/main.o -o space-invaders -lsfml-graphics -lsfml-window -lsfml-system && ./space-invaders 
 */

#include <SFML/Graphics.hpp>
#include "Game.hpp"

#define HEIGHT 900
#define WIDTH 450

int main()
{
    sf::RenderWindow window (sf::VideoMode(HEIGHT, WIDTH), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(false);

    Game game(window);

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

    return 0;
}