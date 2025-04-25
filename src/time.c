#include <stdio.h>
#include "time.h"

void inicioAnalise(analise* x) {
    gettimeofday(&x->TR_inicio, NULL);
    getrusage(RUSAGE_SELF, &x->TU_inicio);
}

void fimAnalise(analise* x) {
    gettimeofday(&x->TR_fim, NULL);
    getrusage(RUSAGE_SELF, &x->TU_fim);
}

void imprimirAnalise(analise* x) {
    double T_real = (x->TR_fim.tv_sec - x->TR_inicio.tv_sec)
                      + (x->TR_fim.tv_usec - x->TR_inicio.tv_usec) / 1e6;

    double T_user = (x->TU_fim.ru_utime.tv_sec - x->TU_inicio.ru_utime.tv_sec)
                      + (x->TU_fim.ru_utime.tv_usec - x->TU_inicio.ru_utime.tv_usec) / 1e6;

    double T_sys = (x->TU_fim.ru_stime.tv_sec - x->TU_inicio.ru_stime.tv_sec)
                     + (x->TU_fim.ru_stime.tv_usec - x->TU_inicio.ru_stime.tv_usec) / 1e6;

    long memoria_kb = x->TU_fim.ru_maxrss; 

    printf("Tempo real: %.6f s\n",  T_real);
    printf("Tempo de Usuario: %.6f s\n",  T_user);
    printf("Tempo do Sistema: %.6f s\n",  T_sys);
    printf("Memória(em KB): %ld KB\n",  memoria_kb);
    printf("-----------------------------\n");
}