#include <time.h>

//NUM de termos e repeticoes
#define NUM 8
#define REP 31

//Biblioteca de calculos
#include "Calc.h"


int main() {
    clock_t t;
    int i,j;
    //int num_ava[NUM] = {7, 37, 8431, 13033,524287, 664283, 3531271};
    int num_ava[NUM] = {7, 37, 8431, 13033,524287, 664283, 3531271, 2147483647};
    float tempos[NUM][REP], medias[NUM], dp[NUM];
    float tempos2[NUM][REP], medias2[NUM], speedup2[NUM];
    float tempos3[NUM][REP], medias3[NUM], speedup3[NUM];

    testaPrimo(0, num_ava, tempos);
    testaPrimo(1, num_ava, tempos2);
    testaPrimo(2, num_ava, tempos3);

    //Preenche vetores com zero
    //Para evitar lixo de memória
    zeroFill(medias);
    zeroFill(medias2);
    zeroFill(medias3);
    zeroFill(dp);

    //Calculo das médias
    media(0, medias, tempos);
    media(1, medias2, tempos2);
    media(2, medias3, tempos3);

    //Calculo do desvio padrão
    desvioP(medias, tempos, dp, num_ava);

    //Calculo do Speed Up
    printf("====== SpeedUp Alg. 2 ======\n");
    speedup(num_ava, medias, medias2,speedup2);
    printf("====== SpeedUp Alg. 3 ======\n");
    speedup(num_ava, medias, medias3,speedup3);
    return 0;
}