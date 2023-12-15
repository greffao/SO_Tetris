/**
 * @file Menu.hpp
 * @author greffao
 * @brief Classe 'Menu' que implementa todos os botões e textos da interface gráfica.
 *        Class 'Menu' that implements all the buttons and text of the graphical interface.
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <sstream>

/*Defines de Botao*/
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 50

/*Botao 'Play'*/
#define PLAY_BUTTON_X 350
#define PLAY_BUTTON_Y 175

/*Botao 'Exit'*/
#define EXIT_BUTTON_X 350
#define EXIT_BUTTON_Y 275

/*Botao 'Voltar'*/
#define BACK_BUTTON_X 100
#define BACK_BUTTON_Y 100

/*Caixa 'Score'*/
#define SCORE_BOX_X 550
#define SCORE_BOX_Y 100

/*Titulo*/
#define TITTLE_X 300
#define TITTLE_Y 75
#define TITTLE_WIDTH 200
#define TITTLE_HEIGHT 75

/*Tutorial*/
#define TUTORIAL_X 75
#define TUTORIAL_Y 200
#define TUTORIAL_WIDTH 200
#define TUTORIAL_HEIGHT 200

class Menu
{
public:
    bool mainMenu;

    /*Botao 'Play*/
    sf::RectangleShape playButtonBox;
    sf::Text playButtonText;

    /*Botao 'Exit*/
    sf::RectangleShape exitButtonBox;
    sf::Text exitButtonText;

    /*Botao 'Back"*/
    sf::RectangleShape backButtonBox;
    sf::Text backButtonText;

    /*Caixa 'Score"*/
    sf::RectangleShape scoreBox;
    sf::Text scoreText;
    sf::Text scorePoints;

    /*Titulo*/
    sf::RectangleShape tittleBox;
    sf::Text tittleText;

    /*Tutorial*/
    sf::RectangleShape tutorialBox;
    sf::Text tutorialTextTittle;
    sf::Text tutorialText;

public:
    Menu(sf::RenderWindow& window, sf::Font& font);

    void hide();
    void show();

    void draw(sf::RenderWindow& window, int score);

};

#endif