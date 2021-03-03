//
// Created by simao on 25/02/2021.
//

#ifndef SPEEDUP_TESTAPRIMO_H
#define SPEEDUP_TESTAPRIMO_H

//Quadrado
int TestaPrimoQ(int n){
    int i;
    for(i = 2; i <= (floor(sqrt(n))); i++){
        if(n%i == 0){
            return 0;
        }
    }
    if(i == (floor(sqrt(n))+1)){
        return 1;
    }
}

//Simples
int TestaPrimoS(int n) {
    int i;
    for(i = 2; i < n; i++){
        if(n % i == 0) {
            return 0;
        }
    }
    if(i == n){
        return 1;
    }
}
//Divisivel por 2
int TestaPrimoD(int n) {
    int EhPrimo = 1,
            d=2;

    if (n <= 1)
        EhPrimo = 0;

    while (EhPrimo == 1 && d <= n /2) {
        if (n % d  == 0)
            EhPrimo = 0;
        d = d + 1;
    }
    return EhPrimo;
}

#endif //SPEEDUP_TESTAPRIMO_H
