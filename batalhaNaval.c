#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   "); // Espaço para o cabeçalho das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", 'A' + j); // Colunas de A a J
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Linhas de 1 a 10
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Posicionamento horizontal fora dos limites do tabuleiro.\n");
        return 0;
    }

    // Valida se há sobreposição
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][coluna + j] == 3) {
            printf("Erro: Sobreposição de navios no posicionamento horizontal.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = 3; // 3 representa parte do navio
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio está dentro dos limites do tabuleiro
    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        printf("Erro: Posicionamento vertical fora dos limites do tabuleiro.\n");
        return 0;
    }


    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == 3) {
            printf("Erro: Sobreposição de navios no posicionamento vertical.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa parte do navio
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    int linhaNavioHorizontal = 1; // Linha 2 do usuário
    int colunaNavioHorizontal = 0; // Coluna A do usuário

    int linhaNavioVertical = 3; // Linha 4 do usuário
    int colunaNavioVertical = 4; // Coluna E do usuário

    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");


    if (posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Navio horizontal posicionado com sucesso em (%d, %c).\n", linhaNavioHorizontal + 1, 'A' + colunaNavioHorizontal);
    } else {
        printf("Falha ao posicionar navio horizontal.\n");
    }


    if (posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Navio vertical posicionado com sucesso em (%d, %c).\n", linhaNavioVertical + 1, 'A' + colunaNavioVertical);
    } else {
        printf("Falha ao posicionar navio vertical.\n");
    }

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}