#include<stdio.h>
#include<stdlib.h>

#include"tabuleiro.h"
//funcao que le e inicializa o tabuleiro
void lerTabuleiro(tabuleiro* t, FILE* arquivo) {
    fscanf(arquivo, "%d %d", &t->N, &t->M);
    
    //condição de parada
    if (t->N == 0 && t->M == 0) {
        return;
    }

    //verifica as condições para dimensões do tabuleiro
    if (t->N < 3 || t->N > 20 || t->M < 3 || t->M > 20 || (t->N * t->M) > 200) {
        fprintf(stderr, "Dimensões invalidas do tabuleiro (N=%d, M=%d)\n", t->N, t->M);
        exit(1);
    }
    t->casas = malloc(t->N * sizeof(int*));
    for (int i = 0; i < t->N; i++) {
        t->casas[i] = malloc(t->M * sizeof(int));
    }

    int peca;
    int qtdpecas = (t->N * t->M) / 2;
    int peca1 = 0, peca2 = 0;

    //lê a disposição do tabuleiro e verifica condições de entrada
    for (int i = 0, idx = 0; i < t->N; i++) {
        for (int j = 0; j < t->M; j++) {
            if ((i + j) % 2 == 0) {     //casa jogável
                if (fscanf(arquivo, "%d", &peca) != 1) {
                    fprintf(stderr, "Entrada invalida: Numero de pecas insuficientes\n");
                    exit(1);
                }
                if (peca < 0 || peca > 2) {
                    fprintf(stderr, "Entrada invalida: Apenas serao aceitos '0,1 e 2' como valores\n");
                    exit(1);
                }
                if (peca == 1) peca1++;
                if (peca == 2) peca2++;

                t->casas[i][j] = peca;
                idx++;
            } else {
                t->casas[i][j] = -1;    //casa não jogável
            }
        }
    }

    //verifica se a quantidade de peças de cada jogador está dentro do limite N*M/4
    int limiteJogador = qtdpecas / 2; 
    if (peca1 > limiteJogador || peca2 > limiteJogador) {
        fprintf(stderr, "Limite de pecas por jogador excedido\n");
        exit(1);
    }
}

void liberarTabuleiro(tabuleiro *t) {
    for (int i = 0; i < t->N; i++) {
        free(t->casas[i]);
    }
    free(t->casas);
}

void criarTabela(tabuleiro *t) {
t->tabela = malloc(t->N * sizeof(int*));
                for (int i = 0; i < t->N; i++) {
                    t->tabela[i] = malloc(t->M * sizeof(int));
                    for (int j = 0; j < t->M; j++) {
                        t->tabela[i][j] = -1;
                    }
                }
}

void liberarTabela(tabuleiro *t){
    for (int i = 0; i < t->N;i++) free(t->tabela[i]);
        free(t->tabela);
}