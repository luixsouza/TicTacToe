#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um jogador
struct Jogador {
    char nome[50];
    char simbolo;
};

// Cadastro de jogadores
void cadastrarJogador(struct Jogador *jogador, char simbolo) {
    printf("Cadastro do Jogador %c:\n", simbolo);
    printf("Nome: ");
    scanf("%s", jogador->nome);
    jogador->simbolo = simbolo;
}

// Criando o tabuleiro
void tabuleiro(char casas2[3][3]) {
    system("clear");
    printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
}

int main() {
    char casas[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    // Cadastro de jogadores
    struct Jogador jogadorX, jogadorO;
    cadastrarJogador(&jogadorX, 'X');
    cadastrarJogador(&jogadorO, 'O');

    // Condições de jogadas
    char resposta;
    int contador_jogadas;
    int linha, coluna;
    int vez = 0;

    do {
        contador_jogadas = 1;

        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                casas[i][j] = ' ';
            }
        }

        do {
            tabuleiro(casas);

            struct Jogador jogadorAtual = vez % 2 == 0 ? jogadorX : jogadorO;
            printf("Vez do jogador %s (%c)\n", jogadorAtual.nome, jogadorAtual.simbolo);

            printf("Digite a linha: \n");
            scanf("%i", &linha);

            printf("Digite a coluna: \n");
            scanf("%i", &coluna);

            if (linha < 1 || coluna < 1 || linha > 3 || coluna > 3) {
                linha = 0;
                coluna = 0;
            } else if (casas[linha - 1][coluna - 1] != ' ') {
                linha = 0;
                coluna = 0;
            } else {
                casas[linha - 1][coluna - 1] = jogadorAtual.simbolo;
                vez++;
                contador_jogadas++;
            }

            // Condições de vitória do 'X'

            if ((casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') ||
                (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') ||
                (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') ||
                
                (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') ||
                (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') ||
                (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') ||
               
                (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') ||
                (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X')) {
                contador_jogadas = 11;
            }

            // Condições de vitória do 'O'

            if ((casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') ||
                (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') ||
                (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') ||
                
                (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') ||
                (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') ||
                (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') ||
                
                (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') ||
                (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O')) {
                contador_jogadas = 12;
            }

        } while (contador_jogadas <= 9);

        // Indicando Vencedor
        tabuleiro(casas);

        if (contador_jogadas == 10) {
            printf("Deu velha!\n");
        } else {
            struct Jogador vencedor = vez % 2 == 0 ? jogadorO : jogadorX;
            struct Jogador perdedor = vez % 2 == 0 ? jogadorX : jogadorO;
            printf("Vitória do Jogador %s (%c)!\n", vencedor.nome, vencedor.simbolo);
            printf("Derrota do Jogador %s (%c)!\n", perdedor.nome, perdedor.simbolo);
        }

        printf("Deseja jogar novamente? [S/N]\n");
        scanf(" %c", &resposta);

    } while (resposta == 's' || resposta == 'S');

    return 0;
}
