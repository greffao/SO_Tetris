/**
 * @file main.cpp
 * @author @greffao
 * @brief Implementação de um jogo de Tetris, usando threads e semáforos.
 * 
 *        Implementation of a Tetris game, using threads and semaphores.
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <SFML/Graphics.hpp>
#include <thread>
#include <queue>
#include <mutex>

#include "include/Menu.hpp"
#include "include/Game.hpp"

#define WINDOW_NAME "Tetris"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
    sf::Font arialFont; if(!arialFont.loadFromFile("fonts/Arial.ttf")) return 1;
    sf::Event event;

    Menu menu = Menu(window, arialFont);
    Game game;
    Buffer buffer;

    std::thread t_game;
    
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();

            if(event.type == sf::Event::MouseButtonPressed) 
            {
                if(event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    if(menu.playButtonBox.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                    {
                        menu.hide();
                        t_game = std::thread([&]() { game.start(buffer); });
                    }
                    if(menu.backButtonBox.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                    {
                        game.end(buffer);
                        t_game.join();
                        
                        menu.show();
                    }
                    if(menu.exitButtonBox.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                    {
                        window.close();
                    }
                }
            }
            if(event.type == sf::Event::KeyPressed)
            {
                buffer.acessarBuffer(event.key.code);
            }
        }

        window.clear(sf::Color::Black);

        game.draw(window);

        menu.draw(window, game.accessScore(-1));
        
        window.display();
    }

    return 0;
}
