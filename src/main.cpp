/* Build
 * g++ -std=c++17 -W -c src/main.cpp -o build/main.o && g++ build/main.o -o space-invaders -lsfml-graphics -lsfml-window -lsfml-system && ./space-invaders 
 */

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}