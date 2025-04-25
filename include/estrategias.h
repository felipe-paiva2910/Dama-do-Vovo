#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include"tabuleiro.h"

extern const int DIRECOES[4][2];

int maxCapturasFB(tabuleiro *t, int x, int y);  //algoritmo de força bruta
int maxCapturasPD(tabuleiro *t, int x, int y);  //otimização usando programação dinâmica
int maxCapturasPara1(tabuleiro *t, int (*estrategia)(tabuleiro*, int, int)); //funcao generica para executar a estrategia

#endif