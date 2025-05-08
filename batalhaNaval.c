#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define MAR 0
#define NAVIO 3

int main() {
    // Matriz representando o tabuleiro do jogo (inicializado com 0 - mar)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais para os dois navios (pode ajustar conforme necessário)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação do navio horizontal (verifica se cabe no tabuleiro)
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Validação do navio vertical (verifica se cabe no tabuleiro)
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Verifica se há sobreposição entre os dois navios
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha_h = linha_horizontal;
        int coluna_h = coluna_horizontal + i;

        int linha_v = linha_vertical + i;
        int coluna_v = coluna_vertical;

        if (linha_h == linha_v && coluna_h == coluna_v) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: Navios se sobrepõem!\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
