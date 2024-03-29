#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define OPCOES "[1]Criar polinomios\n[2]Soma polinomios\n[3]Multiplica polinomios\n[4]Calcula polinomio\n[5]Multiplica polinomio por k\n[6]Deriva Polinomio\n[7]Informações do polinomio\n[8]Sair"
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
        if(EXPO(ptr)!=0) printf("%lfX^%d", COEF(ptr), EXPO(ptr));
        else printf("%lf", COEF(ptr));
        if(PROX(ptr)!=NULL)printf(" + ");
        ptr = PROX(ptr);
    }while(ptr!=NULL);
    
    printf("\n");
}

void criaPolinomio(No *inicio, No *fim, double coef, int expo){
        No p;
        No ini=*inicio, fm=*fim;
        if(coef==0) return;
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
            for(ptr=*inicio; expo<EXPO(ptr); ptr=PROX(ptr));
            if(EXPO(ptr)==expo){
                COEF(ptr)=COEF(ptr)+coef;
            }
            else{
                p=geraNo(expo, coef);
                PROX(p)=ptr;
                ANT(p)= ANT(ptr);
                ANT(ptr)->prox=p;
                ANT(ptr)=p;
            }
        }
}

void multiplicaPolinomio(No *ini){
    int k;
    No p=*ini, ini_R=(No)NULL, fim_R=(No)NULL;
    printf("Insira K:");
    scanf("%d", &k);
    do{
        criaPolinomio(&ini_R,&fim_R,COEF(p)*k,EXPO(p));
        p=PROX(p);
    }while(p!=NULL);
    printf("\nResposta:\n");
    imprime(&ini_R);
}

void derivaPolinomio(No *ini){
    No p=*ini, ini_R=(No)NULL, fim_R=(No)NULL;
    do{
        criaPolinomio(&ini_R,&fim_R,COEF(p)*EXPO(p),EXPO(p)-1);
        p=PROX(p);
    }while(p!=NULL);
    printf("\nResposta:\n");
    imprime(&ini_R);
}

void infoPolinomio(No *ini){
    int grau, elemento=0;
    No p=*ini;
    grau=EXPO(p);
    for(;p!=NULL; p=PROX(p)) elemento++;
    printf("\nGRAU:%d\nELEMENTOS:%d",grau,elemento);
}

void calculaPolinomio(No *ini){
    double X, R=0;
    int pot=1;
    No p=*ini;
    printf("De um valor para X: ");
    scanf("%lf", &X);
    for(;p!=NULL; p=PROX(p)){ 
        for(int i=0; i<EXPO(p);i++) pot*=X;
        R+=pot*COEF(p);
    }
    printf("\nResultado: %lf", R);
}

void multiplicaPolinomios(No *ini_P, No *ini_Q){
   No ini_R=(No)NULL, fim_R=(No)NULL;
   for(No p=*ini_P; p!=NULL; p=PROX(p)){
       for(No q=*ini_Q; q!=NULL; q=PROX(q)){
           criaPolinomio(&ini_R,&fim_R,(COEF(p)*COEF(q)),(EXPO(p)+EXPO(q)));
       }
   }
    printf("\nResposta:\n");
    imprime(&ini_R);
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
    printf("\nResposta:\n");
    imprime(&ini_R);
}


int main(){
    No ini_P=(No)NULL, fim_P=(No)NULL, ini_Q=(No)NULL, fim_Q=(No)NULL;
    int verificador=1, expo, X;
    double coef;
    do{
        system(CLEAR);
        if(ini_P==NULL && ini_Q==NULL) printf("[ATENÇÃO]: Polinomios inexistente\n\n");
        else if(ini_P==NULL){
            printf("Polinomio_Q: ");
            imprime(&ini_Q);
            printf("\n");
        }
        else if(ini_Q==NULL){
            printf("Polinomio_P: ");
            imprime(&ini_P);
            printf("\n");
        }
        else{
            printf("Polinomio_P: ");
            imprime(&ini_P);
            printf("Polinomio_Q: ");
            imprime(&ini_Q);
            printf("\n");
        }
        puts(OPCOES);
        printf("\n\nEscolha uma função: ");
        scanf("%d", &X);
        //Cria Polinomios
        if(X==1){
            system(CLEAR);
            printf("[1]Polinomio P\n[2]Polinomio Q\n[3]Polinomio Q e P\n\nEscolha uma opção: ");
            scanf("%d", &X);
            if(X==1){
                ini_P=(No)NULL;
                fim_P=(No)NULL;
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
                system(CLEAR);
                printf("Polinomio P:\n");
                imprime(&ini_P);
            }
            else if(X==2){
                ini_Q=(No)NULL;
                fim_Q=(No)NULL;
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
                system(CLEAR);
                printf("Polinomio Q:\n");
                imprime(&ini_Q);
            }
            else if(X==3){
                do{
                    ini_P=(No)NULL;
                    fim_P=(No)NULL;
                    ini_Q=(No)NULL;
                    fim_Q=(No)NULL;
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
                system(CLEAR);
                printf("Polinomio P:\n");
                imprime(&ini_P);
                printf("\nPolinomio Q:\n");
                imprime(&ini_Q);
            }
        }
        //SomaPolinomios
        else if(X==2){
            if(ini_Q!=NULL && ini_P!=NULL){
                system(CLEAR);
                printf("Polinomio P:\n");
                imprime(&ini_P);
                printf("Polinomio Q:\n");
                imprime(&ini_Q);
                somaPolinomios(&ini_P, &ini_Q);
            }
            else{
                system(CLEAR);
                printf("[ALERTA]: São necessários dois polinômios para essa operação\n");
            }
        }
        //MultiplicaPolinomios
        else if(X==3){
            if(ini_Q!=NULL && ini_P!=NULL){
                system(CLEAR);
                printf("Polinomio P:\n");
                imprime(&ini_P);
                printf("Polinomio Q:\n");
                imprime(&ini_Q);
                multiplicaPolinomios(&ini_P, &ini_Q);
            }
            else{
                system(CLEAR);
                printf("[ALERTA]: São necessários dois polinômios para essa operação\n");
            }
        }
        //Calcula Polinomio para um X
        else if(X==4){
            if(ini_Q!=NULL || ini_P!=NULL){
                system(CLEAR);
                printf("[1]Polinomio P:\n");
                if(ini_P!=NULL) imprime(&ini_P);
                else printf("[VAZIO]\n");
                printf("[2]Polinomio Q:\n");
                if(ini_Q!=NULL) imprime(&ini_Q);
                else printf("[VAZIO]\n");
                printf("\nEscolha um Polinomio: ");
                scanf("%d", &X);
                if(X==1){
                    system(CLEAR);
                    printf("Polinomio P:\n");
                    imprime(&ini_P);
                    calculaPolinomio(&ini_P);
                }
                else if(X==2){
                    system(CLEAR);
                    printf("Polinomio Q:\n");
                    imprime(&ini_Q);
                    calculaPolinomio(&ini_Q);
                }
            }
            else{
                system(CLEAR);
                printf("[ALERTA]: É necessário pelo menos 1 polinomio\n");
            }
        }
        //MultiplicaPolinomio
        else if(X==5){
            if(ini_Q!=NULL || ini_P!=NULL){
                system(CLEAR);
                printf("[1]Polinomio P:\n");
                if(ini_P!=NULL) imprime(&ini_P);
                else printf("[VAZIO]\n");
                printf("[2]Polinomio Q:\n");
                if(ini_Q!=NULL) imprime(&ini_Q);
                else printf("[VAZIO]\n");
                printf("\nEscolha um Polinomio: ");
                scanf("%d", &X);
                if(X==1){
                    system(CLEAR);
                    printf("Polinomio P:\n");
                    imprime(&ini_P);
                    multiplicaPolinomio(&ini_P);
                }
                else if(X==2){
                    system(CLEAR);
                    printf("Polinomio Q:\n");
                    imprime(&ini_Q);
                    multiplicaPolinomio(&ini_Q);
                }
            }
            else{
                system(CLEAR);
                printf("[ALERTA]: É necessário pelo menos 1 polinomio\n");
            }
        }
        //Deriva Polinomio
        else if(X==6)
        {
            if(ini_Q!=NULL || ini_P!=NULL){
                system(CLEAR);
                printf("[1]Polinomio P:\n");
                if(ini_P!=NULL) imprime(&ini_P);
                else printf("[VAZIO]\n");
                printf("[2]Polinomio Q:\n");
                if(ini_Q!=NULL) imprime(&ini_Q);
                else printf("[VAZIO]\n");
                printf("\nEscolha um Polinomio: ");
                scanf("%d", &X);
                if(X==1){
                    system(CLEAR);
                    printf("Polinomio P:\n");
                    imprime(&ini_P);
                    derivaPolinomio(&ini_P);
                }
                else if(X==2){
                    system(CLEAR);
                    printf("Polinomio Q:\n");
                    imprime(&ini_Q);
                    derivaPolinomio(&ini_Q);
                }
            }
            else{
                 system(CLEAR);
                printf("[ALERTA]: É necessário pelo menos 1 polinomio\n");
            }
        }
        //Grau e elementos do Polinomio
        else if(X==7){
            if(ini_Q!=NULL || ini_P!=NULL){
                system(CLEAR);
                printf("[1]Polinomio P:\n");
                if(ini_P!=NULL) imprime(&ini_P);
                else printf("[VAZIO]\n");
                printf("[2]Polinomio Q:\n");
                if(ini_Q!=NULL) imprime(&ini_Q);
                else printf("[VAZIO]\n");
                printf("\nEscolha um Polinomio: ");
                scanf("%d", &X);
                if(X==1){
                    system(CLEAR);
                    printf("Polinomio P:\n");
                    imprime(&ini_P);
                    infoPolinomio(&ini_P);
                }
                else if(X==2){
                    system(CLEAR);
                    printf("Polinomio Q:\n");
                    imprime(&ini_Q);
                    infoPolinomio(&ini_Q);
                }
            }
            else{
                system(CLEAR);
                printf("[ALERTA]: É necessário pelo menos 1 polinomio\n");
            }
        }
        else if(X==8){
            return(0);
        }
        else{
            printf("Função não existente!\n");
        }
        printf("\nDeseja realizar mais operações? \n[1]SIM || [2]NAO\nR: ");
        scanf("%d", &verificador);
    }while(verificador!=2);
}