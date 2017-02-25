#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Loader.h"
#include "Input.h"
#include "Define.h"
#include "Settings.h"

#include <iostream>

int main()
{
    sf::RenderWindow window (sf::VideoMode(WIDTH, HEIGHT), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    Game game(window, WIDTH, HEIGHT);
    Input input;
    sf::Clock clock;
    Settings::get();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        input.updateButtons();

        game.update(input, (long)clock.restart().asMilliseconds() * SPEED);

        window.clear();

        game.draw();

        window.display();
    }

    return 0;
}