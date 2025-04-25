#include"tabuleiro.h"
#include<stdio.h>
#include<stdlib.h>

//vetor que representa cada uma das direções diagonais
const int DIRECOES[4][2] = {
    {-1, -1},
    {-1,  1},
    { 1, -1},
    { 1,  1}
};

//função que verifica a possibilidade de captura
int capturar(tabuleiro* t, int x, int y, int dx, int dy) {
    int novaX = x + dx * 2;
    int novaY = y + dy * 2;

    //verifica se a captura é possivel
    if (novaX >= 0 && novaX < t->N && novaY >= 0 && novaY < t->M && t->casas[novaX][novaY] == 0) {
        if (t->casas[x + dx][y + dy] == 2) {
            //captura a peça e atualiza as posições do tabuleiro
            t->casas[x + dx][y + dy] = 0;
            t->casas[x][y] = 0; 
            t->casas[novaX][novaY] = 1;  

            return 1;
        }
    }
    return 0;
}



//força bruta: checa capturas para as 4 diagonais para cada posição recursivamente
int maxCapturasFB(tabuleiro* t, int x, int y,int totalCapturas) {
    int maxCapturas = totalCapturas;

    for (int i = 0; i < 4; i++) {
        int dx = DIRECOES[i][0];
        int dy = DIRECOES[i][1];
        //checa a possibilidade de captura
        if (capturar(t, x, y, dx, dy)) {
            int capturas = maxCapturasFB(t, x + dx * 2, y + dy * 2,totalCapturas + 1);

            if (capturas > maxCapturas) {
                maxCapturas = capturas;
            }
            //restaura o tabuleiro para checar outras posições
            t->casas[x + dx][y + dy] = 2; 
            t->casas[x][y] = 1;           
            t->casas[x + dx * 2][y + dy * 2] = 0;  
        }
    }

    return maxCapturas;
}

//programação dinâmica: armazena os resultados das capturas já calculadas para evitar recomputação
int maxCapturasPD(tabuleiro *t, int x, int y) {
    if (t->tabela[x][y] != -1) return t->tabela[x][y];  //se as capturas da posição ja foram calculadas retorna o valor da tabela

    int maxCaptura = 0;

    for (int d = 0; d < 4; d++) {
        int dx = DIRECOES[d][0];
        int dy = DIRECOES[d][1];

        //checa a possibilidade de captura
        if (capturar(t, x, y, dx, dy)) {

            int capturas = 1 + maxCapturasPD(t, x + dx * 2, y + dy * 2);

            //restaura o tabuleiro a disposição anterior
            t->casas[x][y] = 1;
            t->casas[x + dx][y + dy] = 2;
            t->casas[x + dx * 2][y + dy * 2] = 0;

            if (capturas > maxCaptura)
                maxCaptura = capturas;
        }
    }

    t->tabela[x][y] = maxCaptura;   //salva o valor na tabela
    return maxCaptura;
}

//função genérica que utiliza a estratégia escolhida
int maxCapturasPara1(tabuleiro* t, int (*estrategia)(tabuleiro*, int, int, int)) {
    int maxCapturasTotais = 0;

    for (int i = 0; i < t->N; i++) {
        for (int j = 0; j < t->M; j++) {
            if (t->casas[i][j] == 1) {
                int capturas = estrategia(t, i, j, 0);
                if (capturas > maxCapturasTotais) {
                    maxCapturasTotais = capturas;
                }
            }
        }
    }

    return maxCapturasTotais;
}