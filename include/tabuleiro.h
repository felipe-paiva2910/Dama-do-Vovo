#ifndef TABULEIRO_H 
#define TABULEIRO_H
#include<stdio.h>

typedef struct Tabuleiro{
    int N,M;
    int **casas;
    int **tabela;   //tabela usada na PD
}tabuleiro;

void criarTabela(tabuleiro *);          //cria a tabela usada na memorização da PD
void liberarTabela(tabuleiro *);
void lerTabuleiro(tabuleiro *,FILE *);  
void liberarTabuleiro(tabuleiro *);

#endif