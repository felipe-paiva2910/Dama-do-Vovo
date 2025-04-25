#ifndef TIME_H
#define TIME_H

#include <sys/time.h>
#include <sys/resource.h>

typedef struct Analise{
    struct timeval TR_inicio, TR_fim;
    struct rusage TU_inicio, TU_fim;
}analise;

void inicioAnalise(analise* x);
void fimAnalise(analise* x);
void imprimirAnalise(analise* x);

#endif
