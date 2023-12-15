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

    /*Caixa do botao 'Exit'*/
    exitButtonBox = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    exitButtonBox.setFillColor(sf::Color::White);
    exitButtonBox.setPosition(EXIT_BUTTON_X, EXIT_BUTTON_Y);

    /*Texto do botao 'Exit'*/
    exitButtonText = sf::Text("Exit", font, 24);
    exitButtonText.setFillColor(sf::Color::Black);
    exitButtonText.setPosition(EXIT_BUTTON_X, EXIT_BUTTON_Y);

    /*Caixa do botao 'Back'*/
    backButtonBox = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    backButtonBox.setFillColor(sf::Color::White);
    backButtonBox.setPosition(BACK_BUTTON_X, BACK_BUTTON_Y);

    /*Texto do botao 'Back'*/
    backButtonText = sf::Text("Back", font, 24);
    backButtonText.setFillColor(sf::Color::Black);
    backButtonText.setPosition(BACK_BUTTON_X, BACK_BUTTON_Y);

    /*Caixa do score'*/
    scoreBox = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH + 100, BUTTON_HEIGHT + 50));
    scoreBox.setFillColor(sf::Color::White);
    scoreBox.setPosition(SCORE_BOX_X, SCORE_BOX_Y);

    /*Texto do score*/
    scoreText = sf::Text("Score:", font, 24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(SCORE_BOX_X, SCORE_BOX_Y);

    /*Texto do score*/
    scorePoints = sf::Text("0", font, 24);
    scorePoints.setFillColor(sf::Color::Black);
    scorePoints.setPosition(SCORE_BOX_X + 40, SCORE_BOX_Y + 30);

    /*Caixa do Titulo*/
    tittleBox = sf::RectangleShape(sf::Vector2f(TITTLE_WIDTH, TITTLE_HEIGHT));
    tittleBox.setFillColor(sf::Color::White);
    tittleBox.setPosition(TITTLE_X, TITTLE_Y);

    /*Texto do Titulo*/
    tittleText = sf::Text("Tetris", font, 32);
    tittleText.setFillColor(sf::Color::Black);
    tittleText.setPosition(TITTLE_X + 55, TITTLE_Y + 15);

    /*Caixa do Tutorial*/
    tutorialBox = sf::RectangleShape(sf::Vector2f(TUTORIAL_WIDTH, TUTORIAL_HEIGHT));
    tutorialBox.setFillColor(sf::Color::White);
    tutorialBox.setPosition(TUTORIAL_X, TUTORIAL_Y);

    /*Texto do Tutorial*/
    tutorialTextTittle = sf::Text("Tutorial:", font, 32);
    tutorialTextTittle.setFillColor(sf::Color::Black);
    tutorialTextTittle.setPosition(TUTORIAL_X + 40, TUTORIAL_Y + 15);
    tutorialText = sf::Text("-Pressione 'A' para mover\n o bloco para esquerda.\n\n-Pressione 'D' para mover\n o bloco para direita.", font, 16);
    tutorialText.setFillColor(sf::Color::Black);
    tutorialText.setPosition(TUTORIAL_X + 5, TUTORIAL_Y + 50);

    /*Outras Variaveis*/
    mainMenu = true;

}

void Menu::hide(){mainMenu = false;}
void Menu::show(){mainMenu = true;}

void Menu::draw(sf::RenderWindow& window, int score)
{
    if(mainMenu)
    {
        window.draw(playButtonBox);
        window.draw(playButtonText);

        window.draw(exitButtonBox);
        window.draw(exitButtonText);

        window.draw(tittleBox);
        window.draw(tittleText);
    }
    else
    {
        window.draw(backButtonBox);
        window.draw(backButtonText);

        window.draw(scoreBox);
        window.draw(scoreText);

        window.draw(tutorialBox);
        window.draw(tutorialText);
        window.draw(tutorialTextTittle);

        std::stringstream ss;
        ss << score;
        std::string scoreString = ss.str();
        scorePoints.setString(scoreString);
        window.draw(scorePoints);
    }
}