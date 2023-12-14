#include "../include/Game.hpp"

std::mutex mt_inplay;

Game::Game()
{
    inPlay = false;
    score = 0;
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

    gridGame.resetGrid();
    buffer.esvaziarBuffer();

    mt_inplay.unlock();
}

void playerMov(sf::Keyboard::Key tecla, TetrisGrid& gridGame, Piece& peca, int* flag)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(TIME));

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

void scoreCalculator(TetrisGrid& gridGame, int* score)
{
    for(int i = GRID_LINES - 1; i >= 0; i--)
    {
        for(int j = 0; j < GRID_COLUMNS; j++)
        {
            if(gridGame.acessarGrid(j, i, ACCESS) == 0) break;
            else if(j == GRID_COLUMNS - 1)
            {
                gridDown(gridGame, i);
                (*score) += 10;
                i++;
            }
        }
    }
}

void Game::play(Buffer& buffer)
{
    
    PieceGenerator pieceGen;
    Piece* piece = NULL;
    int flag = REACHED_BOTTOM;

    sf::Keyboard::Key tecla;
    
    while(inPlay)
    {
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
        
        if(flag == NO_REACHED_BOTTOM) playerMov(tecla, this->gridGame, *piece, &flag);
        if(flag == REACHED_BOTTOM)
        {
            scoreCalculator(gridGame, &score);
        }
        if(flag == GAME_OVER)
        {
            this->end(buffer);
        }

    }

}
