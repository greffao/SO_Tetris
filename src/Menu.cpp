#include "../include/Menu.hpp"

Menu::Menu(sf::RenderWindow& mainWindow, sf::Font& font)
{
    /*Caixa do botao 'Play'*/
    playButtonBox = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    playButtonBox.setFillColor(sf::Color::White);
    playButtonBox.setPosition(PLAY_BUTTON_X, PLAY_BUTTON_Y);

    /*Texto do botao 'Play'*/
    playButtonText = sf::Text("Play", font, 24);
    playButtonText.setFillColor(sf::Color::Black);
    playButtonText.setPosition(PLAY_BUTTON_X, PLAY_BUTTON_Y);

    /*Caixa do botao 'Eair'*/
    exitButtonBox = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    exitButtonBox.setFillColor(sf::Color::White);
    exitButtonBox.setPosition(EXIT_BUTTON_X, EXIT_BUTTON_Y);

    /*Texto do botao 'Exit'*/
    exitButtonText = sf::Text("Exit", font, 24);
    exitButtonText.setFillColor(sf::Color::Black);
    exitButtonText.setPosition(EXIT_BUTTON_X, EXIT_BUTTON_Y);

}