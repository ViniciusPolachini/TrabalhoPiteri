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

#define MAX 20

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void randomizar(int *num, int ini, int fim){
    
    *(num) = rand() % (fim+1-ini)+ini;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void posicionarPalavra(char **palavras, char *matriz){
    
    int i, j, NL, coluna, linha, aux, verificador = 0;

    do{
        int cont = 0;

        //Horizontal
        for(i=0; i<8; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                randomizar(&coluna,0,19-NL);
                randomizar(&linha,0,19);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+linha*20+coluna+j+1) != 45 && *(matriz+linha*20+coluna+j+1)!=*(palavras[i]+j)){
                        aux=1;
                        cont++;
                        if(cont > 350) break;
                        break;
                    }
                }
            }while(aux);

            for(j=0; j<NL; j++){
                *(matriz+linha*20+coluna+j+1)=*(palavras[i]+j);
            }
        }

        //vertical
        for(i=8; i<16; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                randomizar(&coluna,0,19);
                randomizar(&linha,0,19-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna+1) != 45 && *(matriz+(linha+j)*20+coluna+1)!=*(palavras[i]+j)){
                        aux=1;
                        cont++;
                        if(cont > 350) break;
                        break;
                    }
                }
            }while(aux);

            for(j=0; j<NL; j++){
                *(matriz+(linha+j)*20+coluna+1)=*(palavras[i]+j);
            }
        }

        //diagonal principal
        for(i=16; i<18; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                randomizar(&coluna,0,20-NL);
                randomizar(&linha,0,20-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna+j+1) != 45 && *(matriz+(linha+j)*20+coluna+j+1)!=*(palavras[i]+j)){
                        aux=1;
                        cont++;
                        if(cont > 350) break;
                        break;
                    }
                }
            }while(aux);

            for(j=0; j<NL; j++){
                *(matriz+(linha+j)*20+coluna+j+1)=*(palavras[i]+j);
            }
        }

        //diagonal secundária
        for(i=18; i<20; i++){

            for(NL=0; *(palavras[i]+NL)!='\0';NL++);
            do{
                aux=0;
                randomizar(&coluna,NL-1,19);
                randomizar(&linha,0,20-NL);
                for(j=0; j<NL; j++){ 
                    if(*(matriz+(linha+j)*20+coluna-j+1) != 45 && *(matriz+(linha+j)*20+coluna-j+1)!=*(palavras[i]+j)){
                        aux=1;
                        cont++;
                        if(cont > 350) break;
                        break;
                    }
                }
            }while(aux);

            for(j=0; j<NL; j++){
                *(matriz+(linha+j)*20+coluna-j+1)=*(palavras[i]+j);
            }
            verificador = 1;
        }

    }while(!verificador);
    
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void fisherYates(char **palavras){

    for(int i = 20-1; i > 0; i--){
        int j = rand() % (i+1);
        char *aux = palavras[i];
        palavras[i] = palavras[j];
        palavras[j] = aux;
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void inicializarMatriz(char *matriz){

    for(int i = 0; i <= (MAX*MAX); i++){
        *(matriz + i) = 45;
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void gerarMatriz(char *matriz){

    for(int i = 0; i <= (MAX*MAX); i++){
        if(*(matriz + i) == 45){
           *(matriz + i) = rand() % (90 + 1 - 65) + 65;
        }
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void imprimirMatriz(char *matriz){

    for(int i = 1; i <= (MAX*MAX); i++){
        printf("%3c", *(matriz + i));
        if(i % 20 == 0) printf("\n");
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void imprimirMatrizColorida(char *matriz){

    for(int i = 1; i <= (MAX*MAX); i++){
        if(*(matriz+i)!=45){
            printf("\x1b[1;32m%3c\e[0;37m" , *(matriz + i));
        }
        else{
            printf("\e[0;37m%3c\e[0;37m", *(matriz + i));
        }
        if(i % 20 == 0) printf("\n");
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void){

    system(CLEAR);

    char *palavras[MAX] = {"BARCELONA", "BRATISLAVA", "CAMBRIDGE", "COPENHAGUE", "DUSSELDORF",
    "EDIMBURGO", "FRANKFURT", "KIEV", "LIVERPOOL", "LEEDS", "MAASTRICHT", "MADRID", "MANCHESTER",
    "LISBOA", "LONDRES", "PALERMO", "PARIS", "SEVILHA", "SHEFFIED", "TURIM"}, palavras_rev[MAX];

    puts("\n TPP-04 - Caça Palavras");
    puts("\n Palavras para serem encontradas:");
    for(int i=0; i<20; i++){
        printf("\n \x1b[1;32m%s\e[0;37m", *(palavras+i));
    }

    fisherYates(palavras);

    char matriz[MAX][MAX];

    inicializarMatriz(&matriz[0][0]);

    posicionarPalavra(palavras, &matriz[0][0]);

    char matriz_resposta[MAX][MAX];
    
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            matriz_resposta[i][j] = matriz[i][j];
        }
    }

    gerarMatriz(&matriz[0][0]);

    puts("\n\n Precione [ENTER] para ver o caça paralvras.\n");
    getchar();

    imprimirMatrizColorida(&matriz[0][0]);

    puts("\n\n Precione [ENTER] para ver a resolução do caça paralvras.\n");
    getchar();

    imprimirMatrizColorida(&matriz_resposta[0][0]);

    puts("\n\n Precione [ENTER] para finalizar o programa.\n");
    getchar();


    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
