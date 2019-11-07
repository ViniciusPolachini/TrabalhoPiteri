/* 
 * Trabalho Prático de Programação 04 - ATP II
 * Rafael Bassi Rosseto // 191251968
 * Vinicius Polachini Mayer Freitas de Jesus // 191251852
 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define MAX 20

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void inicializarmatriz(char *matriz){

    for(int i = 0; i <= (MAX*MAX); i++){
        *(matriz + i) = 32;
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void gerarmatriz(char *matriz){

    clock_t seed;
    seed = clock();
    srand(seed);
    for(int i = 0; i <= (MAX*MAX); i++){
        if(*(matriz + i) == 32){
           *(matriz + i) = rand() % (90 + 1 - 65) + 65;
        }
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void imprimirmatriz(char *matriz){

    for(int i = 1; i <= (MAX*MAX); i++){
        printf("%3c", *(matriz + i));
        if(i % 20 == 0) printf("\n");
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void){

    char *palavras[MAX] = {"BARCELONA", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE", "DUSSELDORF",
    "EDIMBURGO", "FRANKFURT", "KIEV", "LIVERPOOL", "LEEDS", "MAASTRICHT", "MADRID", "MANCHESTER",
    "LISBOA", "LONDRES", "PALERMO", "PARIS", "SERVILHA", "SHEFFIED", "TURIM"};

    char matriz[MAX][MAX];
    inicializarmatriz(&matriz[0][0]);
    gerarmatriz(&matriz[0][0]);
    imprimirmatriz(&matriz[0][0]);
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
