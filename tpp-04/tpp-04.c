/* 
 * Trabalho Prático de Programação 04 - ATP II
 * Rafael Bassi Rosseto // 191251968
 * Vinicius Polachini Mayer Freitas de Jesus // 191251852
 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GRAY     "\e[0;37m"
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

void Random(int *num, int ini,int fim){
    clock_t seed;
    seed = clock();
    srand(seed);
    *(num) = rand() % (fim+1-ini)+ini;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void posicionarpalavra(char **palavras, char *matriz){
    int i, j, NL, coluna, linha, aux;
    //Horizontal
        for(i=0; i<4; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                Random(&coluna,0,19-NL);
                Random(&linha,0,19);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+linha*20+coluna+j+1) != 45 && *(matriz+linha*20+coluna+j+1)!=*(palavras[i]+j)){
                       aux=1;
                        break;
                    }
                }
            }while(aux);
             for(j=0; j<NL; j++){
              *(matriz+linha*20+coluna+j+1)=*(palavras[i]+j);
            }
                
        }
    //vertical
        for(; i<8; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                Random(&coluna,0,19);
                Random(&linha,0,19-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna+1) != 45 && *(matriz+(linha+j)*20+coluna+1)!=*(palavras[i]+j)){
                       aux=1;
                        break;
                    }
                }
            }while(aux);
             for(j=0; j<NL; j++){
              *(matriz+(linha+j)*20+coluna+1)=*(palavras[i]+j);
            }
                
        }
    //diagonal principal
        for(; i<10; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                Random(&coluna,0,20-NL);
                Random(&linha,0,20-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna+j+1) != 45 && *(matriz+(linha+j)*20+coluna+j+1)!=*(palavras[i]+j)){
                       aux=1;
                        break;
                    }
                }
            }while(aux);
             for(j=0; j<NL; j++){
              *(matriz+(linha+j)*20+coluna+j+1)=*(palavras[i]+j);
            }
                
        }
    //diagonal secundária
        for(; i<12; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                Random(&coluna,NL-1,19);
                Random(&linha,0,20-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna-j+1) != 45 && *(matriz+(linha+j)*20+coluna-j+1)!=*(palavras[i]+j)){
                       aux=1;
                        break;
                    }
                }
            }while(aux);
             for(j=0; j<NL; j++){
              *(matriz+(linha+j)*20+coluna-j+1)=*(palavras[i]+j);
            }
                
        }
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
void imprimirmatrizcolorida(char *matriz){
    for(int i = 1; i <= (MAX*MAX); i++){
        if(*(matriz+i)!=45){
            printf("\x1b[31m%3c\e[0;37m" , *(matriz + i));
        }
        else{
            printf("\e[0;37m%3c", *(matriz + i));
        }
        if(i % 20 == 0) printf("\n");
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void){
    char *palavras[MAX] = {"BARCELONA", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE", "DUSSELDORF",
    "EDIMBURGO", "FRANKFURT", "KIEV", "LIVERPOOL", "LEEDS", "MAASTRICHT", "MADRID", "MANCHESTER",
    "LISBOA", "LONDRES", "PALERMO", "PARIS", "SERVILHA", "SHEFFIED", "TURIM"};

    FisherYates(palavras);

    char matriz[MAX][MAX];
    inicializarmatriz(&matriz[0][0]);
    posicionarpalavra(palavras, &matriz[0][0]);
    imprimirmatrizcolorida(&matriz[0][0]);
    printf("\n\n\n");
    gerarmatriz(&matriz[0][0]);
    imprimirmatriz(&matriz[0][0]);
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
