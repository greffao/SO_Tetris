# Jogo de Tetris com Threads e Semáforos

## Introdução
Neste projeto, desenvolveremos um jogo de Tetris que faz uso de threads e semáforos para criar uma experiência interativa e concorrente. O jogo envolve a queda de peças e a interação do jogador, com a adição de uma moeda como recurso valioso que pode ser usada para comprar peças e boosts para melhorar o desempenho do jogador.

## Objetivos
Os principais objetivos deste projeto são:
- Implementar um jogo de Tetris funcional.
- Utilizar threads para gerenciar a queda de peças, ações do jogador, atualização dos pontos e etc de forma concorrente.
- Usar semáforos para sincronizar a atualização das moedas.

## Descrição do Jogo
O jogo de Tetris é um quebra-cabeças clássico no qual peças tetromino caem do topo da tela, e o jogador deve rotacioná-las e movê-las lateralmente para preencher linhas completas. Quando uma linha é preenchida, ela é eliminada, e o jogador ganha pontos. O jogo continua até que não haja espaço para a próxima peça cair.

As características adicionais do jogo incluem:
- Queda automática de peças com threads.
- Controles de movimento e rotação para o jogador.
- Verificação de linhas completas com threads e semáforos.
- Sistema de moeda para comprar peças e boosts.
- Pontuação e fim de jogo.

## Implementação de Threads e Semáforos
- Uma thread será responsável pela queda automática das peças.
- Outra thread tratará as ações do jogador, como movimento e rotação de peças.
- Uma terceira thread realizará a verificação de linhas completas.
- Semáforos serão usados para controlar a sincronização entre essas threads, evitando conflitos e garantindo a jogabilidade fluida.

## Sistema de Moeda
- O jogador ganhará moedas ao completar linhas de blocos no Tetris.
- As moedas podem ser usadas para comprar:
  - Peças especiais ou raras.
  - Boosts que melhoram a jogabilidade.
- A interface gráfica deve exibir a quantidade de moedas do jogador.
- O jogador pode gastar moedas de forma estratégica para melhorar seu desempenho no jogo.

## Conclusão
Este projeto de jogo de Tetris com threads e semáforos não apenas demonstrará a aplicação de conceitos de concorrência em um ambiente de programação de jogos, mas também adicionará um elemento de estratégia com o sistema de moeda. Os jogadores serão incentivados a completar linhas de blocos para ganhar moedas e gastá-las com sabedoria para adquirir peças e boosts.

O uso de threads e semáforos permitirá que diferentes partes do jogo funcionem de forma concorrente, garantindo uma jogabilidade suave e responsiva. Este projeto pode servir como um exemplo educativo de como gerenciar a concorrência em aplicativos de jogos e introduzir elementos econômicos para tornar o jogo mais envolvente.
