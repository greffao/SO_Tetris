/**
 * @file Buffer.hpp
 * @author @greffao
 * @brief A classe Buffer é responsável por administrar a entrada de teclas
 *        inseridas pelo usuário, a fim de controlar as peças do tetris, e o 
 *        consumo das mesmas pelo programa, para mudar a posição desses objetos.
 * 
 *        The Buffer class is responsible for managing the user's input of keys,
 *        controlling the Tetris pieces, and handling their consumption by the program
 *        to change the position of these objects.
 * 
 * @version 0.1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <mutex>
#include <queue>
#include <SFML/Window.hpp>

/*Flag que indica que o acesso ao buffer eh para consulta.*/
#define RETURN sf::Keyboard::Unknown

class Buffer
{
private:
    std::mutex mt_buffer;
    std::queue<sf::Keyboard::Key> buffer;

public:

    /*Funções de acesso ao buffer. Note que há o uso de semáforos,
    visto que o buffer é acessado pela funcao main e pela thread t_game. */
    sf::Keyboard::Key acessarBuffer(sf::Keyboard::Key tecla);
    void esvaziarBuffer();
};

#endif