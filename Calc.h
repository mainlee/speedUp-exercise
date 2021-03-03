//
// Created by simao on 25/02/2021.
//
#include <stdio.h>
#include <time.h>
#include <math.h>

//Biblioteca de funções para testar os primos
#include "TestaPrimo.h"

#ifndef SPEEDUP_CALC_H
#define SPEEDUP_CALC_H

int i, j;

void zeroFill(float V[NUM]){
    for(i = 0; i<NUM; i++){
        V[i] = 0;
    }
}

void progress(int n, int m){
    float r = (float)(n+1)/m;
    //printf("%f\n", r);
    printf("Progresso: %.1f%%\n", r*100);
}

void media(int n, float medias[NUM], float tempos[NUM][REP]) {
    printf("====== Somatoria Alg. %d======\n", n);
    //Calc somatoria do tempo
    for (i = 0; i < REP; i++) {
        for (j = 0; j < NUM; j++) {
            medias[j] += tempos[j][i];
            //printf("Tempo medio: %.5lf ms do valor %d \n", medias[j]);
        }
    }

    //Media do tempo
    printf("====== Calc. media Alg. %2 ======\n", n);
    for (i = 0; i < NUM; i++) {
        medias[i] = medias[i] / REP;
        printf("Media: %.5lf\n", medias[i]);
    }
}

void desvioP(float medias[NUM], float tempos[NUM][REP], float dp[NUM], int num_ava[NUM]) {
    printf("====== Calculando desvio ======\n");
    //Desvio padrão
    for(i = 0; i<NUM; i++){
        double temp = 0;
        for(j = 0; j<REP; j++){
            temp += (pow((tempos[i][j]-medias[i]),2));
        }
        dp[i] = sqrt(temp/REP);
        printf("Desvio de %d: %.5lf \n", num_ava[i], dp[i]);
    }

}

void testaPrimo(int alg, int num_ava[NUM], float tempos[NUM][REP]){
    clock_t t;
    if(alg == 0){
        printf("====== Alg. 1 ======\n");
        for(i = 0; i < NUM; i++){
            for(j = 0; j < REP; j++){
                t = clock();
                //Alg. fornecido
                TestaPrimoD(num_ava[i]);
                t = clock() - t;
                tempos[i][j] = ((double)t) / ((CLOCKS_PER_SEC / 1000));
                //printf("Tempos em %d add: %.5lf ms\n", num_ava[i], tempos[i][j]);
            }
            progress(i, NUM);
        }
    }
    else if(alg == 1){
        printf("====== Alg. 2 ======\n");
        for(i = 0; i < NUM; i++){
            for(j = 0; j < REP; j++){
                t = clock();
                //Alg. fornecido
                TestaPrimoS(num_ava[i]);
                t = clock() - t;
                tempos[i][j] = ((double)t) / ((CLOCKS_PER_SEC / 1000));
                //printf("Tempos em %d add: %.5lf ms\n", num_ava[i], tempos[i][j]);
            }
            progress(i, NUM);
        }
    }
    else if(alg == 2){
        printf("====== Alg. 2 ======\n");
        for(i = 0; i < NUM; i++){
            for(j = 0; j < REP; j++){
                t = clock();
                //Alg. fornecido
                TestaPrimoQ(num_ava[i]);
                t = clock() - t;
                tempos[i][j] = ((double)t) / ((CLOCKS_PER_SEC / 1000));
                //printf("Tempos em %d add: %.5lf ms\n", num_ava[i], tempos[i][j]);
            }
            progress(i, NUM);
        }
    }
}

void speedup(int num_ava[NUM], float mediaOld[NUM], float mediaNew[NUM],float spdup[NUM]){
    for(i = 0; i<NUM; i++){
        if(mediaNew[i] != 0){
            spdup[i] = mediaOld[i]/mediaNew[i];
            printf("SpeedUp do tempo %d: %f\n", num_ava[i],  spdup[i]);
        }
        else{
            spdup[i] = 0;
            printf("SpeedUp do tempo %d: %f\n", num_ava[i],  spdup[i]);
        }
    }
}




#endif //SPEEDUP_CALC_H
