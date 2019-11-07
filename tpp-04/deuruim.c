#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void randomizarpalavras(char *fonte, char *alvo, int *verificador, int lim){

    clock_t seed;
    seed = clock();
    srand(seed);
    int i=0;
    while(i < lim){
        int aux = rand() % 20;
        if(*(verificador + aux) == 0){
            *(alvo + i) = *(fonte + aux);
            *(verificador + aux) = 1;
            i++;
        }
    }

}

int main(void){

    char *palavras[20] = {"BARCELONA", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE", "DUSSELDORF",
    "EDIMBURGO", "FRANKFURT", "KIEV", "LIVERPOOL", "LEEDS", "MAASTRICHT", "MADRID", "MANCHESTER",
    "LISBOA", "LONDRES", "PALERMO", "PARIS", "SERVILHA", "SHEFFIED", "TURIM"};

    char *hor_normal[4], *hor_reverso[4], *ver_normal[4], *ver_reverso[4], *diag_princ[2], *diag_sec[2];

    int verificador[20];
    
    randomizarpalavras(&palavras[0], &hor_normal[0], &verificador[0], 4);
    randomizarpalavras(&palavras[0], &hor_reverso[0], &verificador[0], 4);
    randomizarpalavras(&palavras[0], &ver_normal[0], &verificador[0], 4);
    randomizarpalavras(&palavras[0], &ver_reverso[0], &verificador[0], 4);
    randomizarpalavras(&palavras[0], &diag_princ[0], &verificador[0], 2);
    randomizarpalavras(&palavras[0], &diag_sec[0], &verificador[0], 2);

    for (int i = 0; i < 4; i++){
       printf("%s \n", hor_normal[i]);
    }
    for (int i = 0; i < 4; i++){
       printf("%s \n", hor_reverso[i]);
    }
    for (int i = 0; i < 4; i++){
       printf("%s \n", ver_normal[i]);
    }
    for (int i = 0; i < 4; i++){
       printf("%s \n", ver_reverso[i]);
    }
    for (int i = 0; i < 2; i++){
       printf("%s \n", diag_princ[i]);
    }
    for (int i = 0; i < 2; i++){
       printf("%s \n", diag_sec[i]);
    }

    return 0;
}