#include "../include/Game.hpp"
#include <iostream>

std::mutex mt_inplay;
std::mutex mt_speed;
std::mutex mt_score;

Game::Game()
{
    inPlay = false;
    score = 0;
    speed = 500;
}

int Game::accessScore(int x)
{
    mt_score.lock();
    if(x == -1)
    {
        mt_score.unlock();
        return score;
    }
    else score += x;
    mt_score.unlock();
    return -1;
}

void Game::draw(sf::RenderWindow& window)
{
    if(inPlay) gridGame.draw(window);
}

void Game::start(Buffer& buffer)
{   
    mt_inplay.lock();
    inPlay = true;
    mt_inplay.unlock();

    play(buffer);
}

void Game::end(Buffer& buffer)
{
    mt_inplay.lock();
    
    inPlay = false;

    buffer.esvaziarBuffer();
    gridGame.resetGrid();

    mt_inplay.unlock();
}

void Game::playerMov(sf::Keyboard::Key tecla, Piece& peca, int* flag)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));

    if(tecla == sf::Keyboard::A)
    {
        peca.left(gridGame);

    }
    else if(tecla == sf::Keyboard::D)
    {
        peca.right(gridGame);
    }
    else
    {
        (*flag) = peca.down(gridGame);
    }
}

void gridDown(TetrisGrid& gridGame, int linhaInicial)
{
    for(int i = linhaInicial; i > 0; i--)
    {
        for(int j = 0; j < GRID_COLUMNS; j++)
        {
            int conteudo = gridGame.acessarGrid(j, i-1, ACCESS);
            gridGame.acessarGrid(j, i, conteudo);
        }
    }
    for(int j = 0; j < GRID_COLUMNS; j++)
    {
        gridGame.acessarGrid(j, 0, 0);
    }
}

void Game::scoreCalculator()
{
    for(int i = GRID_LINES - 1; i >= 0; i--)
    {
        for(int j = 0; j < GRID_COLUMNS; j++)
        {
            if(gridGame.acessarGrid(j, i, ACCESS) == 0) break;
            
            if(j == GRID_COLUMNS - 1)
            {
                gridDown(gridGame, i);
                accessScore(250);
                i++;
            }
        }
    }
}

void scoreChanger(Game* g)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
    (*g).accessScore(1);
}

void Game::play(Buffer& buffer)
{
    PieceGenerator pieceGen;
    Piece* piece = NULL;
    int flag = REACHED_BOTTOM;

    sf::Keyboard::Key tecla;

    std::thread t_speed;

    while(inPlay)
    {
        t_speed = std::thread(scoreChanger, this);

        if(flag == REACHED_BOTTOM)
        {
            if(piece != NULL)
            {
                delete piece;
                piece = NULL;
            }

            piece = pieceGen.newRandomPiece();
            flag = NO_REACHED_BOTTOM;
        }

        tecla = buffer.acessarBuffer(RETURN);
        
        if(flag == NO_REACHED_BOTTOM) playerMov(tecla, *piece, &flag);

        if(flag == REACHED_BOTTOM)
        {
            scoreCalculator();
        }
        if(flag == GAME_OVER)
        {
            delete piece;
            this->end(buffer);
        }

        t_speed.join();
    }
    if(piece != NULL) delete piece;

}
