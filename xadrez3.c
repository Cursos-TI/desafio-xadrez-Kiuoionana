#include <stdio.h>

/*
    XADREZ – Nível Mestre
    ---------------------------------------------
    - Torre, Bispo e Rainha: MOVIMENTOS RECURSIVOS
    - Bispo: TAMBÉM com LOOPS ANINHADOS (externo = vertical; interno = horizontal)
    - Cavalo: LOOPS ANINHADOS com múltiplas variáveis/condições + break/continue
    - Impressões por casa: "Cima", "Baixo", "Esquerda", "Direita"
    - Linhas em branco separando as peças
    ---------------------------------------------
    Observação sobre desempenho:
    As profundidades de recursão são pequenas (ex.: 5–8), evitando stack overflow.
*/

/* =========================
   Funções RECURSIVAS
   ========================= */
void mover_torre_direita(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    mover_torre_direita(casas - 1);
}

void mover_rainha_esquerda(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    mover_rainha_esquerda(casas - 1);
}

/* Bispo (versão recursiva):
   Cada passo diagonal é de 1 para cima + 1 para direita.
   Mantemos a impressão em duas linhas para respeitar o padrão exigido. */
void mover_bispo_cima_direita_rec(int passos) {
    if (passos <= 0) return;
    printf("Cima\n");
    printf("Direita\n");
    mover_bispo_cima_direita_rec(passos - 1);
}

/* =========================
   Bispo com LOOPS ANINHADOS
   (externo = vertical; interno = horizontal)
   ========================= */
void mover_bispo_cima_direita_loops(int passos) {
    /* Para cada “passo diagonal”, fazemos 1 movimento vertical (externo)
       e 1 movimento horizontal (interno). */
    for (int v = 0; v < passos; v++) {   // externo: vertical
        printf("Cima\n");
        for (int h = 0; h < 1; h++) {    // interno: horizontal
            printf("Direita\n");
        }
    }
}

/* =========================
   Cavalo com LOOPS ANINHADOS
   (duas para CIMA e uma para DIREITA)
   - múltiplas variáveis/condições
   - uso de break/continue
   ========================= */
void mover_cavalo_cima_direita_complexo(int subir, int direita) {
    /* Ideia:
       fase 0 = faz 'subir' vezes "Cima"
       fase 1 = faz 'direita' vezes "Direita"
       Usamos um 'for' externo controlando a fase e
       um 'while' interno controlando o contador daquela fase.
    */
    for (int fase = 0; fase < 2; fase++) {               // 0: vertical; 1: horizontal
        int alvo = (fase == 0) ? subir : direita;        // quantas casas nesta fase
        int i = 0;

        while (1) {
            // Se já atingimos o objetivo da fase, saímos do while:
            if (i >= alvo) {
                break; // concluiu a fase atual
            }

            // Controle de fluxo com múltiplas condições:
            if (fase == 0 && alvo == 0) {
                // sem movimento vertical necessário — segue para próxima fase
                break;
            }
            if (fase == 1 && alvo == 0) {
                // sem movimento horizontal necessário — nada a fazer
                break;
            }

            // Executa a ação da fase:
            if (fase == 0) {
                printf("Cima\n");
            } else {
                // Caso a lógica mudasse para outro L, poderíamos pular impressões inválidas:
                if (direita <= 0) {      // exemplo de proteção + continue
                    i++;
                    continue;            // ignora impressão nesta iteração
                }
                printf("Direita\n");
            }

            i++;

            // Exemplo de uso de continue para deixar explícito o fluxo
            if (i < alvo) {
                continue; // ainda restam passos nesta fase; volta ao topo do while
            }

            // quando i == alvo, while terminará pelo if (i >= alvo)
        }
        // próxima fase (se houver)
    }
}

int main() {
    // Parâmetros (definidos em código, conforme requisitos)
    int casasTorre   = 5;  // Torre: 5 para a Direita
    int passosBispo  = 5;  // Bispo: 5 passos de (Cima + Direita)
    int casasRainha  = 8;  // Rainha: 8 para a Esquerda
    int cavaloUp     = 2;  // Cavalo: 2 para Cima
    int cavaloRight  = 1;  //          1 para Direita

    /* =========================
       TORRE – Recursivo
       ========================= */
    printf("Movimento da Torre (recursivo):\n");
    mover_torre_direita(casasTorre);

    /* =========================
       BISPO – Recursivo
       ========================= */
    printf("\nMovimento do Bispo (recursivo):\n");
    mover_bispo_cima_direita_rec(passosBispo);

    /* =========================
       BISPO – Loops aninhados
       (externo vertical, interno horizontal)
       ========================= */
    printf("\nMovimento do Bispo (loops aninhados: externo=vertical, interno=horizontal):\n");
    mover_bispo_cima_direita_loops(passosBispo);

    /* =========================
       RAINHA – Recursivo
       ========================= */
    printf("\nMovimento da Rainha (recursivo):\n");
    mover_rainha_esquerda(casasRainha);

    /* =========================
       CAVALO – Loops aninhados complexos
       (duas para CIMA e uma para DIREITA)
       ========================= */
    printf("\nMovimento do Cavalo (loops aninhados complexos):\n");
    mover_cavalo_cima_direita_complexo(cavaloUp, cavaloRight);

    return 0;
}
