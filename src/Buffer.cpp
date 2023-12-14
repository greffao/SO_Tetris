#include "../include/Buffer.hpp"

sf::Keyboard::Key Buffer::acessarBuffer(sf::Keyboard::Key tecla) {
    sf::Keyboard::Key retorno;

    std::lock_guard<std::mutex> lock(mt_buffer); // Usando um mutex para garantir a segurança entre threads

    // Verificando a tecla de entrada
    if (tecla == RETURN) {
        // Se o buffer não estiver vazio, obtém e remove a tecla da frente
        if (!buffer.empty()) {
            retorno = buffer.front();
            buffer.pop();
        } else {
            // Se o buffer estiver vazio, retorna a tecla 'RETURN'
            retorno = RETURN;
        }
    } else {
        // Se a tecla de entrada não for 'RETURN', coloca-a no buffer
        buffer.push(tecla);
        retorno = RETURN;
    }

    return retorno; // Retorna a tecla processada
}

void Buffer::esvaziarBuffer() {
    mt_buffer.lock(); // Bloqueia o mutex para operação segura no buffer

    while (!buffer.empty()) 
    {
        buffer.pop(); // Remove todas as teclas do buffer enquanto ele não estiver vazio
    }

    mt_buffer.unlock(); // Libera o mutex após a operação no buffer
}
