#include <stdio.h>

int main() {
    // ======================================================
    // Simulação de Movimentos de Peças de Xadrez
    // Torre, Bispo, Rainha e Cavalo
    // ======================================================
    // Cada peça usa uma estrutura de repetição diferente,
    // conforme solicitado nos desafios nível novato e aventureiro.
    // ======================================================

    // -----------------------------
    // Movimentação da TORRE (for)
    // -----------------------------
    int casasTorre = 5; // número de casas que a torre se moverá
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // -----------------------------
    // Movimentação do BISPO (while)
    // -----------------------------
    int casasBispo = 5;
    int contadorBispo = 1;
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo <= casasBispo) {
        printf("Cima, Direita\n");
        contadorBispo++;
    }

    // -----------------------------
    // Movimentação da RAINHA (do-while)
    // -----------------------------
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    // -----------------------------
    // Movimentação do CAVALO (for + while)
    // -----------------------------
    // O cavalo se move em "L": duas casas para baixo e uma para a esquerda.
    // Usaremos dois loops aninhados:
    // - O loop for controlará o movimento vertical (duas casas para baixo)
    // - O loop while controlará o movimento horizontal (uma casa para a esquerda)
    // -----------------------------
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;

    printf("\nMovimento do Cavalo:\n");

    for (int i = 1; i <= movimentosBaixo; i++) {
        printf("Baixo\n");
        if (i == movimentosBaixo) {
            // Após completar o movimento para baixo, move uma casa à esquerda
            int contadorEsquerda = 0;
            while (contadorEsquerda < movimentosEsquerda) {
                printf("Esquerda\n");
                contadorEsquerda++;
            }
        }
    }

    return 0;
}
