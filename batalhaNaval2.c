#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Por exemplo, 5x5 para as matrizes de habilidade

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


void inicializarMatrizHabilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade Cone
void criarHabilidadeCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatrizHabilidade(matriz);
    matriz[1][2] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;
    matriz[2][3] = 1;
    matriz[3][0] = 1;
    matriz[3][1] = 1;
    matriz[3][2] = 1;
    matriz[3][3] = 1;
    matriz[3][4] = 1;
}

// Função para criar a matriz de habilidade Cruz
void criarHabilidadeCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatrizHabilidade(matriz);
    matriz[2][0] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;
    matriz[2][3] = 1;
    matriz[2][4] = 1;
    matriz[1][2] = 1;
    matriz[3][2] = 1;

}

// Função para criar a matriz de habilidade Octaedro
void criarHabilidadeOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    inicializarMatrizHabilidade(matriz);
    
    matriz[0][2] = 1;
    matriz[1][2] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;
    matriz[2][3] = 1;
    matriz[3][2] = 1;

    
}


void aplicarHabilidadeNoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    
    int deslocamento = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (matrizHabilidade[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem + (i - deslocamento);
                int colunaTabuleiro = colunaOrigem + (j - deslocamento);

                // Verifica se a posição está dentro dos limites do tabuleiro
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    // Marca a posição com 5 (área afetada pela habilidade)
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");

    // Posicionamento de navios
    posicionarNavioHorizontal(tabuleiro, 7, 1); 
    posicionarNavioVertical(tabuleiro, 3, 4);   

    printf("\nTabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");

    // Criação das matrizes de habilidade
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidadeCone, 1, 2); // Cone na Linha 2, Coluna C
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidadeCruz, 6, 6); // Cruz na Linha 7, Coluna G
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidadeOctaedro, 1, 8); // Octaedro na Linha 2, Coluna I

    printf("\nTabuleiro com navios e habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}