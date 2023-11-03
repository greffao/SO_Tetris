#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

/*Defines de Botao*/
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 50

/*Botao 'Play'*/
#define PLAY_BUTTON_X 187.5
#define PLAY_BUTTON_Y 175

/*Botaoa 'Exit'*/
#define EXIT_BUTTON_X 187.5
#define EXIT_BUTTON_Y 275

class Menu
{
public:
    bool menuShowing;

    /*Botao 'Play*/
    sf::RectangleShape playButtonBox;
    sf::Text playButtonText;

    /*Botao 'Exit*/
    sf::RectangleShape exitButtonBox;
    sf::Text exitButtonText;

public:
    Menu(sf::RenderWindow& mainWindow, sf::Font& font);

};

#endif