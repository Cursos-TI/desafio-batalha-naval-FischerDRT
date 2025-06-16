#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
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

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio está dentro dos limites do tabuleiro
    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna < 0 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Posicionamento diagonal principal fora dos limites do tabuleiro.\n");
        return 0;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] == 3) {
            printf("Erro: Sobreposição de navios no posicionamento diagonal principal.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // 3 representa parte do navio
    }
    return 1;
}

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio está dentro dos limites do tabuleiro
    if (linha < 0 || linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna < TAMANHO_NAVIO - 1 || coluna >= TAMANHO_TABULEIRO) {
        printf("Erro: Posicionamento diagonal secundária fora dos limites do tabuleiro.\n");
        return 0;
    }

    // Valida se há sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] == 3) {
            printf("Erro: Sobreposição de navios no posicionamento diagonal secundária.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3; // 3 representa parte do navio
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);


    int linhaNavioHorizontal1 = 1; // Linha 2 do usuário
    int colunaNavioHorizontal1 = 0; // Coluna A do usuário

    int linhaNavioVertical1 = 3; // Linha 4 do usuário
    int colunaNavioVertical1 = 4; // Coluna E do usuário

    // Novos navios diagonais
    int linhaNavioDiagonalPrincipal1 = 0; // Linha 1 do usuário
    int colunaNavioDiagonalPrincipal1 = 6; // Coluna G do usuário

    int linhaNavioDiagonalSecundaria1 = 6; // Linha 7 do usuário
    int colunaNavioDiagonalSecundaria1 = 2; // Coluna C do usuário

    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");


    if (posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal1, colunaNavioHorizontal1)) {
        printf("Navio horizontal 1 posicionado com sucesso em (%d, %c).\n", linhaNavioHorizontal1 + 1, 'A' + colunaNavioHorizontal1);
    } else {
        printf("Falha ao posicionar navio horizontal 1.\n");
    }

    if (posicionarNavioVertical(tabuleiro, linhaNavioVertical1, colunaNavioVertical1)) {
        printf("Navio vertical 1 posicionado com sucesso em (%d, %c).\n", linhaNavioVertical1 + 1, 'A' + colunaNavioVertical1);
    } else {
        printf("Falha ao posicionar navio vertical 1.\n");
    }

    if (posicionarNavioDiagonalPrincipal(tabuleiro, linhaNavioDiagonalPrincipal1, colunaNavioDiagonalPrincipal1)) {
        printf("Navio diagonal principal 1 posicionado com sucesso em (%d, %c).\n", linhaNavioDiagonalPrincipal1 + 1, 'A' + colunaNavioDiagonalPrincipal1);
    } else {
        printf("Falha ao posicionar navio diagonal principal 1.\n");
    }

    if (posicionarNavioDiagonalSecundaria(tabuleiro, linhaNavioDiagonalSecundaria1, colunaNavioDiagonalSecundaria1)) {
        printf("Navio diagonal secundária 1 posicionado com sucesso em (%d, %c).\n", linhaNavioDiagonalSecundaria1 + 1, 'A' + colunaNavioDiagonalSecundaria1);
    } else {
        printf("Falha ao posicionar navio diagonal secundária 1.\n");
    }

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}