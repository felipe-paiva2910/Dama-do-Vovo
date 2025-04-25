#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void abrirArquivos(char *entrada, char *saida, FILE **arqIn, FILE **arqOut) {
    *arqIn = fopen(entrada, "r");
    if (*arqIn == NULL) {
        perror("Nao foi possivel abrir o arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }

    *arqOut = fopen(saida, "w");
    if (*arqOut == NULL) {
        perror("Nao foi possivel abrir o arquivo de saida\n");
        exit(EXIT_FAILURE);
    }
}

void lerEntrada(int argc, char* argv[], char** entrada, char** saida, int* estrategia) {
    if (argc < 4) {
        fprintf(stderr, "Entrada incompativel, leia as instrucoes\n");
        exit(EXIT_FAILURE);
    }

    *entrada = argv[1];
    *saida = argv[2];
    *estrategia = atoi(argv[3]);

    if (*estrategia < 1 || *estrategia > 3) {
        fprintf(stderr, "Estrategia invalida: %d. Sao aceitos penas 1 e 2.\n", *estrategia);
        exit(EXIT_FAILURE);
    }
}

void escreverSaida(FILE *arqOut, int maxCapturas) {
    fprintf(arqOut, "%d\n", maxCapturas);
}

void fecharArquivos(FILE* arqIn, FILE* arqOut) {
    if (arqIn) fclose(arqIn);
    if (arqOut) fclose(arqOut);
}
