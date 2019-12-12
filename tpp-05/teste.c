#include <stdio.h>
#include <stdlib.h>
#define PROX(p) p->prox
#define ANT(p) p->ant
#define EXPO(p) p->expo
#define COEF(p) p->coef
typedef struct no *No;
typedef struct no{
    int expo;
    double coef;
    No prox, ant;
}poli;

No geraNo(int expo, double coef){
    No p;
    p=(No)malloc(sizeof(poli));
    if(p==NULL){
        printf("ERRO");
        exit(1);
    }
    PROX(p) = NULL;
    ANT(p) = NULL;
    EXPO(p) = expo;
    COEF(p) = coef;
    return(p);
}

void criaPolinomio(No inicio, No fim){
    int expo;
    double coef;
    No p, ini=inicio, fm=fim;
    int verificador=1;
    do{
        printf("\nNovo termo para o polinomio:");
        printf("\nIntroduza o coeficiente que acompanha x: ");
        scanf("%lf", &coef);
        printf("\nIntroduza o expoente que acompanha %lfx: ", coef);
        scanf("%d", &expo);
        if(inicio==NULL){ 
            p = geraNo(expo, coef);
            inicio=fim=p;
        }
        else if(expo>EXPO(ini)){
            p = geraNo(expo, coef);
            PROX(p) = ini;
            ANT(ini) = p;
            inicio=p;
        }
        else if(expo<EXPO(fm)){
             p = geraNo(expo, coef);
             ANT(p) = fm;
             PROX(fm) = p;
             fim=p;
        }
        else{
            No ptr;
            p=geraNo(expo, coef);
            for(ptr=inicio; expo>PROX(ptr)->expo; ptr=PROX(ptr)->prox);
            PROX(ptr)->ant=p;
            PROX(p)=PROX(ptr);
            PROX(ptr)=p;
            ANT(p)=ptr;
        }
        printf("\nDeseja adicionar outro termo no polinomio? ([1]Sim / [0]Não) ");
        scanf("%d", &verificador);
    }while(verificador);
}

void imprime(No inicio){
    inicio;
    do{
        printf("%lfX^%d", COEF(inicio), EXPO(inicio));
        if(PROX(inicio)!=NULL) printf(" + ");
    }while(PROX(inicio)==NULL);
}

int main(){
    No ini=(No)NULL, fim=(No)NULL;
    criaPolinomio(ini, fim);
    imprime(ini);
}