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

void Random(int *num, int fim){
    clock_t seed;
    seed = clock();
    srand(seed);
    *(num) = rand() % (fim+1);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void posicionarpalavra(char **palavras, char *matriz){
    int i, j, NL, coluna, linha, aux;
    //Horizontal
        for(i=0; i<4; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                Random(&coluna,19-NL);
                Random(&linha,19);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+linha*20+coluna+j) == 45 || *(matriz+linha*20+coluna+j)==*(palavras[i]+j)){
                        *(matriz+linha*20+coluna+j)=*(palavras[i]+j);
                    }
                    else{
                        aux=1;
                        break;
                    }
                }
            }while(aux);
        }
    //vertical

    //diagonal principal

    //diagonal secundária
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void FisherYates(char **palavras){
   
    clock_t seed;
    seed = clock();
    srand(seed);

   for(int i = 20-1; i > 0; i--){
        int j = rand() % (i+1);
        char *aux = palavras[i];
        palavras[i] = palavras[j];
        palavras[j] = aux;
   }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void inicializarmatriz(char *matriz){

    for(int i = 0; i <= (MAX*MAX); i++){
        *(matriz + i) = 45;
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void gerarmatriz(char *matriz){

    clock_t seed;
    seed = clock();
    srand(seed);
    for(int i = 0; i <= (MAX*MAX); i++){
        if(*(matriz + i) == 45){
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
    char *palavras[MAX] = {"BARCELONA ", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE", "DUSSELDORF",
    "EDIMBURGO", "FRANKFURT", "KIEV", "LIVERPOOL", "LEEDS", "MAASTRICHT", "MADRID", "MANCHESTER",
    "LISBOA", "LONDRES", "PALERMO", "PARIS", "SERVILHA", "SHEFFIED", "TURIM"};

    FisherYates(palavras);

    char matriz[MAX][MAX];
    inicializarmatriz(&matriz[0][0]);
    posicionarpalavra(palavras, &matriz[0][0]);
    imprimirmatriz(&matriz[0][0]);
    printf("\n\n\n");
    gerarmatriz(&matriz[0][0]);
    imprimirmatriz(&matriz[0][0]);
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
