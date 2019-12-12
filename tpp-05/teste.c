#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define PROX(p) p->prox
#define ANT(p) p->ant
#define EXPO(p) p->expo
#define COEF(p) p->coef
typedef struct no *No;
typedef struct no{
    int expo;
    double coef;
    No prox, ant;
}NO;

No geraNo(int expo, double coef){
    No p;
    p=(No)malloc(sizeof(NO));
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

void imprime(No *inicio){
    No ptr=*inicio;
    do{
        printf("%lfX^%d", COEF(ptr), EXPO(ptr));
        if(PROX(ptr)!=NULL){ 
            printf(" + ");
            ptr = PROX(ptr);
            }
    }while(PROX(ptr)!=NULL);
     printf("%lfX^%d", COEF(ptr), EXPO(ptr));
    printf("\n");
}

void criaPolinomio(No *inicio, No *fim, double coef, int expo){
        No p;
        No ini=*inicio, fm=*fim;
        if(*inicio==NULL){ 
            p = geraNo(expo, coef);
            *inicio=*fim=p;
        }
        else if(expo>EXPO(ini)){
            p = geraNo(expo, coef);
            PROX(p) = ini;
            ANT(ini) = p;
            *inicio=p;
        }
        else if(expo<EXPO(fm)){
             p = geraNo(expo, coef);
             ANT(p) = fm;
             PROX(fm) = p;
             *fim=p;
        }
        else{
            No ptr;
            p=geraNo(expo, coef);
            for(ptr=*inicio; expo>EXPO(ptr); ptr=PROX(ptr));
            PROX(ptr)->ant=p;
            PROX(p)=PROX(ptr);
            PROX(ptr)=p;
            ANT(p)=ptr;
        }
}
void somaPolinomios(No *ini_P, No *ini_Q){
    No p = *ini_P, q = *ini_Q, ini_R=(No)NULL, fim_R=(No)NULL;
    do{
        if(p!=NULL&&q!=NULL&&EXPO(p)==EXPO(q)){
            criaPolinomio(&ini_R,&fim_R,(COEF(p)+COEF(q)),EXPO(p));
            p=PROX(p);
            q=PROX(q);
        }
        else if(p==NULL||EXPO(q)>EXPO(p)){
            criaPolinomio(&ini_R,&fim_R,COEF(q),EXPO(q));
            q=PROX(q);
        }
        else{
            criaPolinomio(&ini_R,&fim_R,COEF(p),EXPO(p));
            p=PROX(p);
        }
    }while(p!=NULL||q!=NULL);
    printf("Polinomio R:\n");
            imprime(&ini_R);
}


int main(){
    No ini_P=(No)NULL, fim_P=(No)NULL, ini_Q=(No)NULL, fim_Q=(No)NULL;
    int verificador=1, expo, X;
    double coef;
    do{
        system(CLEAR);
        printf("Escolha uma função: ");
        scanf("%d", &X);
        if(X==1){
            do{
                system(CLEAR);
                printf("Polinomio P:\n\n");
                printf("\nIntroduza o coeficiente que acompanha x: ");
                scanf("%lf", &coef);
                printf("\nIntroduza o expoente que acompanha %lfx: ", coef);
                scanf("%d", &expo);
                criaPolinomio(&ini_P,&fim_P, coef, expo);
                printf("Deseja inserir mais termos?\n[1]SIM || [2]NAO\nR: ");
                scanf("%d", &X);
            }while(X!=2);
             do{
                system(CLEAR);
                printf("Polinomio Q:\n\n");
                printf("\nIntroduza o coeficiente que acompanha x: ");
                scanf("%lf", &coef);
                printf("\nIntroduza o expoente que acompanha %lfx: ", coef);
                scanf("%d", &expo);
                criaPolinomio(&ini_Q,&fim_Q, coef, expo);
                printf("Deseja inserir mais termos?\n[1]SIM || [2]NAO\nR: ");
                scanf("%d", &X);
            }while(X!=2);
            printf("Polinomio P:\n");
            imprime(&ini_P);
            printf("Polinomio Q:\n");
            imprime(&ini_Q);
        }
        else if(X==2){
            system(CLEAR);
            printf("Polinomio P:\n");
            imprime(&ini_P);
            printf("Polinomio Q:\n");
            imprime(&ini_Q);
            somaPolinomios(&ini_P, &ini_Q);
        }
        printf("\nDeseja realizar mais operações? \n[1]SIM || [2]NAO\nR: ");
        scanf("%d", &verificador);
    }while(verificador!=2);
}