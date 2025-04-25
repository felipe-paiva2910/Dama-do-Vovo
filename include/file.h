#ifndef FILE_H
#define FILE_H

#include <stdio.h>

void abrirArquivos(char *entrada, char *saida, FILE **arqIn, FILE **arqOut);
void lerEntrada(int argc, char* argv[], char** entrada, char** saida, int* estrategia);
void escreverSaida(FILE *arqOut, int maxCapturas);
void fecharArquivos(FILE* arqIn, FILE* arqOut);

#endif