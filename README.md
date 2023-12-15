# Jogo Tetris com Threads e Semáforos

*Lucas Greff Meneses - 13671615 <br>
Henrique Souza Marques - 11815722 <br>
Vinicius Carneiro Macedo - 11915752 <br> <br>
Instituto de Ciências Matemáticas e de Computação <br>
Universidade de São Paulo* <br>

Este projeto implementa um jogo Tetris utilizando threads e semáforos para controlar a mecânica do jogo.

## Introdução

Este projeto em C++ implementa um jogo Tetris com o uso de threads e semáforos para gerenciar a mecânica do jogo. Possui uma interface gráfica e segue a jogabilidade clássica do Tetris.
Estrutura do Projeto

O projeto está estruturado com os seguintes arquivos principais:

- `main.cpp`: Controla o loop principal do jogo e as interações do usuário.
- `Buffer.cpp`: Gerencia as entradas do teclado para controlar as peças do Tetris, utilizando semáforos para lidar com acesso concorrente.
- `Game.hpp`: Implementa a lógica do jogo, incluindo movimentos das peças, detecção de colisões e cálculo da pontuação, enquanto utiliza threads para controlar o gameplay.
- `Piece.hpp` e classes derivadas: Definem as peças do Tetris e seus movimentos.
- `TetrisGrid.hpp`: Manipula o grid do jogo e sua exibição na interface gráfica.
- `Menu.cpp`: Gerencia o menu do jogo e elementos da interface.

## Tutorial

- O jogo inicia com um menu permitindo ao jogador iniciar o gameplay ou sair.
- Use as teclas 'A' e 'D' do teclado para mover as peças para a esquerda ou para a direita, respectivamente.
- O jogo termina quando as peças alcançam o topo do grid.

## Uso de Threads e Semáforos

O jogo conta com 3 threads:
- A thread `main` lida com os eventos de entrada de informacao (botões 'Play', 'Exit' e 'Back', bem como teclas 'A' e 'D') e display de informações na tela.
- A thread `t_game` lida com toda a lógica do jogo, como a movimentação das peças, por comando do jogador ou descida automática feita pelo sistema, atualização do grid, criação de novas peças, cálculo do score quando uma linha é completada.
- A thread `t_score` lida com a contagem progressiva do score conforme a passagem do tempo.

### Regiões Críticas

- `TetrisGrid` é uma região crítica, pois é acessada pela thread `main`, para fazer o display na tela, e pela thread `t_game`, para a lógica do jogo (movimento das peças no grid).
- `Buffer` é a região de comunicação entre a thread `main`, que vai ler as entradas do usuário, e a thread `t_game` que vai interpretá-las.
- `score` (variável da classe `Game`) é acessada simultaneamente pela thread `t_game` e `t_score`.
- `inplay` (variável da classe `Game`) é acessada simultaneamente pela thread `main` e pela thread `t_game`. Ela dita se o jogo está em execução ou não.
- 

A sincronização multithread foi realizada pelo uso de semáforos mutex.

## Instalação

**Pré-Requisitos:** Um computador, sistema operacional Linux e a biblioteca SFML.

1. Entre no [repositório do jogo no Github](https://github.com/greffao/SO_Tetris).
2. Abra o terminal no diretório em que vc deseja clonar o jogo.
3. Clone o repositório:
```
git clone https://github.com/greffao/SO_Tetris.git
```
4. Entre no diretório recém criado `SO_Tetris` com o terminal.
5. Digite o comando:
```
make
```
6. Execute o jogo com o comando:
```
make run
```
