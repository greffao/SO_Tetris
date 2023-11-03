#include <SFML/Graphics.hpp>

#include "include/Menu.hpp"

#define WINDOW_NAME "Threatris"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

    sf::Font arialFont;
    if (!arialFont.loadFromFile("fonts/Arial.ttf")) return 1;


    Menu menu(window, arialFont);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    if (menu.playButtonBox.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                    {
                        /*Se clicou com o botao esquerdo do mouse no botao 'play'*/
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        /*Desenho do botao 'play*/
        window.draw(menu.playButtonBox);
        window.draw(menu.playButtonText);

        /*Desenho do botao 'Exit*/
        window.draw(menu.exitButtonBox);
        window.draw(menu.exitButtonText);

        window.display();
    }

    return 0;
}
