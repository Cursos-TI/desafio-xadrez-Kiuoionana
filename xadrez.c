#include <stdio.h>


int main() {
    // ================================================
    // Simulação de Movimentos de Peças de Xadrez
    // Torre (for), Bispo (while) e Rainha (do-while)
    // ================================================

    // -----------------------------
    // Movimentação da TORRE (for)
    // -----------------------------
    // A torre se move em linha reta, aqui iremos mover 5 casas para a direita.
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // -----------------------------
    // Movimentação do BISPO (while)
    // -----------------------------
    // O bispo se move na diagonal; simularemos 5 casas para cima e à direita.
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
    // A rainha pode se mover em qualquer direção. Aqui, 8 casas para a esquerda.
    int casasRainha = 8;
    int contadorRainha = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    return 0;
}

