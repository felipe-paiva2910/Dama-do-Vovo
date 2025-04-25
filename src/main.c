#include<stdio.h>
#include<stdlib.h>

#include"time.h"
#include"file.h"
#include"tabuleiro.h"
#include"estrategias.h"

int main(int argc, char* argv[]) {
    tabuleiro t;
    analise x;
    int op = 0;
    int resultado;

    FILE *entrada, *saida;
    char *nomeEntrada, *nomeSaida;

    // lê a linha de comando
    lerEntrada(argc, argv, &nomeEntrada, &nomeSaida, &op);

    //abre os arquivos de entrada e saida, para leitura e escrita respectivamente
    abrirArquivos(nomeEntrada, nomeSaida, &entrada, &saida);

    while (1) {
        lerTabuleiro(&t, entrada);
        if (t.N == 0 && t.M == 0) break;

        switch (op) {
            case 1:     //forca bruta
                inicioAnalise(&x);
                resultado = maxCapturasPara1(&t, maxCapturasFB);
                escreverSaida(saida, resultado);
                fimAnalise(&x);
                imprimirAnalise(&x);
                break;
            case 2:     //programacao dinamica
                inicioAnalise(&x);
                criarTabela(&t);
                resultado = maxCapturasPara1(&t, maxCapturasPD);
                escreverSaida(saida, resultado);
                liberarTabela(&t);
                fimAnalise(&x);
                imprimirAnalise(&x);
                break;
            default:
                liberarTabuleiro(&t);
                fecharArquivos(entrada, saida);
                return 1;
        }

        liberarTabuleiro(&t);
    }

    fecharArquivos(entrada, saida);
    return 0;
}
