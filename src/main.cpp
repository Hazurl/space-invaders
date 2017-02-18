#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Loader.h"
#include "Input.h"

#define WIDTH 800
#define HEIGHT 450

int main()
{
    sf::RenderWindow window (sf::VideoMode(WIDTH, HEIGHT), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(120);

    Game game(window, WIDTH, HEIGHT);
    Input input;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        input.updateButtons();
        game.update(input);

        window.clear();

        game.draw();

        window.display();
    }

    Loader::clean();

    return 0;
}