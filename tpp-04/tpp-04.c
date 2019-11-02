#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 11
#define MAX2 10
typedef char string[MAX];

void Random(int *ptr, int Maximo, int minimo)
{
     clock_t seed;
     seed = clock();
     srand(seed);
    *ptr= rand() % (Maximo + 1 - minimo) + minimo; /* [minimo, Maximo] */
     return;
}

void GerarLetras(char *Matriz, int ordem){
    int i,j;
    for(i=0; i<ordem*ordem; i++){
        if(*Matriz+i!=35){
        Random(&j, 122, 97);
        *(Matriz+i)=j;
        } 
    }

}

void GerarMatriz(char *Matriz, int ordem){
    int i;
    for(i=0; i<ordem*ordem; i++){
        *(Matriz+i)=35;
    }
}

void ImprimeMatriz(char *Matriz, int ordem){
    int i, j;
    for(i=0; i<ordem; i++){
        for(j=0; j<ordem; j++) printf("%4c", *(Matriz+i*ordem+j));
        printf("\n");
    }
}

void inseriPalavras(string Palavras,const char *Matriz, int ordem){
    int i,j, NL, DS, coluna, linha;//DS=DireçãoSentido & NL=NúmeroDeLetras

        for(NL=0; *(Palavras+NL)!='\0'; NL++)
        Random(&DS, 5, 0);//5=VerticalCima - 4=VerticalBaixo - 3=HorizontalDireita - 2=HorizonalEsquerda - 1=DiagonalCima - 0=DiagonalBaixo
        if(DS=5){
            Random(&coluna, ordem-1, 0);
            Random(&linha, ordem-1, NL-1);
        }
            else if(DS=4){
                Random(&coluna, ordem-1, 0);
                Random(&linha, ordem-NL, 0);
            }
                else if(DS=3){
                    Random(&coluna, ordem-NL, 0);
                    Random(&linha, ordem-1, 0);
                }
                    else if(DS=2){
                        Random(&coluna, ordem-1, NL-1);
                        Random(&linha, ordem-1, 0);
                    }
                        else if(DS=1){
                            Random(&coluna, ordem-NL, 0);
                            Random(&linha, ordem-1, NL-1);
                        }
                            else{
                                Random(&coluna, ordem, NL-1);
                                Random(&linha, ordem-NL, 0);
                            }
}


int main(){
    string Palavras;
    char Matriz[MAX2][MAX2];
    int ordem;
    printf("Qual a dimensão do caça palavras?");
    scanf("%d", &ordem);
    printf("Digite uma palavra");
    fgets(Palavras, MAX, stdin);
    fgets(Palavras, MAX, stdin);
    Matriz[ordem][ordem];
    GerarMatriz(&Matriz[0][0], ordem);
    inseriPalavras(Palavras, &Matriz[0][0], ordem);
    GerarLetras(&Matriz[0][0], ordem);
    ImprimeMatriz(&Matriz[0][0], ordem);
}