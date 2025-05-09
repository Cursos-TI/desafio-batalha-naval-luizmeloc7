#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

// Função para verificar se há sobreposição antes de posicionar
int podePosicionar(int tabuleiro[TAM][TAM], int posicoes[3][2]) {
    for (int i = 0; i < 3; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
            return 0; // Fora dos limites
        if (tabuleiro[linha][coluna] != AGUA)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int posicoes[3][2]) {
    for (int i = 0; i < 3; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa com água (0)

    // Coordenadas dos 4 navios (tamanho fixo = 3 posições)
    int navio1[3][2] = { {2, 1}, {2, 2}, {2, 3} };         // Horizontal
    int navio2[3][2] = { {5, 7}, {6, 7}, {7, 7} };         // Vertical
    int navio3[3][2] = { {0, 0}, {1, 1}, {2, 2} };         // Diagonal principal
    int navio4[3][2] = { {0, 9}, {1, 8}, {2, 7} };         // Diagonal secundária

    // Tenta posicionar todos os navios com validação
    if (!podePosicionar(tabuleiro, navio1)) {
        printf("Erro ao posicionar navio1!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio1);

    if (!podePosicionar(tabuleiro, navio2)) {
        printf("Erro ao posicionar navio2!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio2);

    if (!podePosicionar(tabuleiro, navio3)) {
        printf("Erro ao posicionar navio3!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio3);

    if (!podePosicionar(tabuleiro, navio4)) {
        printf("Erro ao posicionar navio4!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navio4);

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO 10x10 ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
