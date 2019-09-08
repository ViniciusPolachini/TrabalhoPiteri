
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 100
#define QUEBRA "\n\n"
#define BARRA ----------------------------------------------------------------------------------------------------------------------------
#define OPCOES "[1]Criar/Editar conjuntos\n[2] Intersecção entre A e B \n[3] União entre A e B \n[4] Diferença A menos B \n[5] Diferença B menos A \n[6] Verificar se um elemento arbitrário\n[7] Verificar se há elementos repetidos \n[8] Eliminar elementos repitidos de um conjunto \n[9] Verificar se um conjunto é vazio\n[10] Visualizar conjuntos\n[11]Sair \n\nEscolha uma operação:  "

void Vazio(int *ptr, int dim){
    if(dim) printf("não é vazio.\n");
    else printf("é vazio.\n");
}
void Repetidos(int *ptr, int *dim){
    int i, j;
    for(i=0; i<*dim; i++)
        if(*(ptr+i)==*(ptr+i+1)){
            for(j=i+1; j<*dim; j++){
                *(ptr+j)=*(ptr+j+1);
            }
        *dim=*dim-1;
        }
}
void Uniao(int *ptrA, int *ptrB, int *ptrC, int dimA, int dimB, int *dimC){
    int i=0, j=0;
    while(i<dimA){
        *dimC=*dimC+1;
        *(ptrC+i)=*(ptrA+i);
        i++;
    }
    while(j<dimB){
         *dimC=*dimC+1;
         *(ptrC+i)=*(ptrB+j);
         i++;
         j++;
    }
    ShellSort(ptrC, *dimC);
    Repetidos(ptrC, dimC);
    return;
}

void ElementosRep(int *ptr,int dim){
    int i, aux=0;
    for(i=0; i<dim; i++){
        if(*(ptr+i)==*(ptr+i+1)){
            aux=1;
            printf("[%d]e[%d]=%d", i, i+1, *(ptr+i));
        }
    }

    if(aux) printf("\nsão repetidos!!!!\n");
        else printf("não há elementos repetidos!!\n");
}

void Interseccao(int *ptrA, int *ptrB, int *ptrC, int dimA, int dimB, int *dimC){
    int i,j,k=0, continua, aux=1;

    for(i=0; i<dimA; i++){
        continua=1;
        for(j=0;j<dimB && continua;j++){
            if(*(ptrA+i)==*(ptrB+j)){
                aux=0;
                *dimC=*dimC+1;
                *(ptrC+k)=*(ptrA+i);
                k++;
                continua=0;
            }
        }
    }
    Repetidos(ptrC, dimC);
    if(aux) printf("\n[VAZIO]\n");
}
void difAB(int *ptrA, int *ptrB, int *ptrC, int dimA, int dimB, int *dimC){
    int i,j,k=0, aux;

    for(i=0; i<dimA; i++){
        aux=1;
        for(j=0;j<dimB && aux;j++){
            if(*(ptrA+i)==*(ptrB+j)) aux=0;
        }
        if(aux){
            *dimC=*dimC+1;
            *(ptrC+k)=*(ptrA+i);
            k++;
        }
    }
    Repetidos(ptrC, dimC);
}

void difBA(int *ptrA, int *ptrB, int *ptrC, int dimA, int dimB, int *dimC){
    int i,j,k=0, aux;

    for(i=0; i<dimA; i++){
        aux=1;
        for(j=0;j<dimB && aux;j++){
            if(*(ptrA+j)==*(ptrB+i)) aux=0;
        }
        if(aux){
            *dimC=*dimC+1;
            *(ptrC+k)=*(ptrB+i);
            k++;
        }
    }
    Repetidos(ptrC, dimC);
}

void ElementoArb(int *ptr, int dim, int chave){
    int i;

    for(i=0; i<dim; i++){
        if(*(ptr+i)==chave){
            printf("Está nesse conjunto\n");
            return;
        }
    }

    printf("Não está nesse conjunto\n");
    return;
}

void Dimensao(int *dim){
     do{
      scanf("%d", dim);
     }while(*dim<1 || *dim>MAX);
}

void Introduzir(int *ptr, int dim){
    int i;

    for(i=0; i<=dim-1; i++){
        printf("\n[%d]: ", i);
        scanf("%d", (ptr+i));
        }
}

void ShellSort (int *ptr, int dim) {
int i, j, x, salto;

for (salto=dim/2; salto>0; salto /=2){
   for (i = salto; i <dim; i++) {
     x = *(ptr+i);
     for (j=i; j >= salto && x < *(ptr+j-salto); j=j-salto)
        *(ptr+j) = *(ptr+j-salto);
     *(ptr+j) = x;
   }
}
return;
}


void Troca(int *PtrA) {
     int aux;

     aux = *PtrA;
     *PtrA = *(PtrA+1);
     *(PtrA+1) = aux;
}

void Random(int *ptrA, int *ptrB, int DimA, int DimB)
{
     int i,j;
     clock_t seed;
     seed = clock();
     srand((unsigned) seed);
     for (i = 0; i < DimA; i++)
         *(ptrA + i)= rand();

     for (j = 0; j < DimB; j++)
         ptrB[j]= rand();

     return;
}

void Visualizar(int *ptr, int dim){
    int i;
    for(i=0; i<=dim-1; i++){
        printf("[%d]=%d\n", i,*(ptr+i));
    }
}

int main(void)
{
    int dimA=MAX, dimB=MAX, dimC=MAX*2, VA[dimA],VB[dimB],VC[dimC], x, y, z, continua=1;
    char ch='N';
    dimA=0;
    dimB=0;
    setlocale(LC_ALL,"Portuguese");
    do{
    system("cls");
    printf("[TRABALHO PRÁTICO DE PROGRAMAÇÃO]");
    puts(QUEBRA);
    if(!dimA && !dimB) printf("[ALERTA]: todos os conjuntos estão vazios");
    puts(QUEBRA);
    puts(OPCOES);
    scanf("%d", &y);
    switch(y){
    case 1:system("cls");
           printf("Qual conjunto você deseja editar?\n[1]A e B\n[2]A\n[3]B\n[4]VOLTAR\n[OPÇÃO]=");
           scanf("%d", &x);
           break;

    case 2:system("cls");
            dimC=0;
            printf("[INTERSECÇÃO]\n");
            Interseccao(VA, VB, VC, dimA, dimB, &dimC);
            Visualizar(VC, dimC);
            system("pause");
            break;

    case 3:system("cls");
           dimC=0;
           Uniao(VA, VB, VC, dimA, dimB, &dimC);
           printf("[UNIÃO]\n");
           Visualizar(VC, dimC);
           system("pause");
           break;
    case 4:system("cls");
            dimC=0;
            difAB(VA, VB, VC, dimA, dimB, &dimC);
            printf("A-B:\n");
            Visualizar(VC, dimC);
            system("pause");
            break;
    case 5:system("cls");
            dimC=0;
            difBA(VA, VB, VC, dimA, dimB, &dimC);
            printf("B-A:\n");
            Visualizar(VC, dimC);
            system("pause");
            break;
    case 6:system("cls");
            int chave;
           printf("Deseja checar a existencia de um elemento arbitrário no conjunto:\n[1]A e B\n[2]A\n[3]B\n[4]Último conjunto resultante\n[5]VOLTAR\n[OPÇÃO]=");
           scanf("%d", &z);
           printf("Escolha um elemento: ");
           scanf("%d", &chave);
           if(z==1){
                printf("VA: ");
                ElementoArb(VA, dimA, chave);
                printf("VB: ");
                ElementoArb(VB, dimB, chave);
           };
           if(z==2){
                printf("VA: ");
                ElementoArb(VA, dimA, chave);
           };
           if(z==3){
                printf("VB: ");
                ElementoArb(VB, dimB, chave);
           };
           if(z==4){
                printf("[CONJUNTO RESULTANTE]:");
                ElementoArb(VC, dimC, chave);
           }
           system("pause");
            break;
    case 7:system("cls");
            printf("Deseja checar a existencia de elementos repetidos no conjunto:\n[1]A e B\n[2]A\n[3]B\n[4]VOLTAR\n[OPÇÃO]=");
            scanf("%d", &z);
            if(z==1){
                printf("Em A ");
                ElementosRep(VA, dimA);
                printf("Em B ");
                ElementosRep(VB, dimB);
            };
             if(z==2){
                printf("Em A ");
                ElementosRep(VA, dimA);
            };
             if(z==3){
                printf("Em A ");
                ElementosRep(VB, dimB);
            };
            system("pause");
            break;
    case 8:system("cls");
            printf("Deseja excluir os elementos repetidos do conjunto:\n[1]A e B\n[2]A\n[3]B\n[4]VOLTAR\n[OPÇÃO]=");
            scanf("%d", &z);
            if(z==1){
                Repetidos(VA, &dimA);
                Repetidos(VB, &dimB);
                printf("Concluido!\n");
            };
            if(z==2){
                Repetidos(VA, &dimA);
                printf("Concluido!\n");
            };
            if(z==3){
                Repetidos(VB, &dimB);
                printf("Concluido!\n");
            };
            system("pause");
            break;
    case 9: system("cls");
            printf("Deseja checar o conjunto:\n[1]A e B\n[2]A\n[3]B\n[4]VOLTAR\n[OPÇÃO]=");
            scanf("%d", &z);
            system("cls");
            if(z==1){
                printf("Conjunto A:");
                Vazio(VA, dimA);
                printf("Conjunto B:");
            Vazio(VB, dimB);
            };
            if(z==2){
                printf("Conjunto A:");
                Vazio(VA, dimA);
            };
            if(z==3){
                printf("Conjunto B:");
                Vazio(VB, dimB);
            };
            system("pause");
            break;
    case 10:system("cls");
            printf("Deseja visualizar o conjunto:\n[1]A e B\n[2]A\n[3]B\n[4]Último conjunto resultante\n[5]VOLTAR\n[OPÇÃO]=");
            scanf("%d", &z);
            system("cls");
            if(z==1){
                printf("Conjunto A:\n");
                Visualizar(VA,dimA);
                printf("\nConjunto B:\n");
                Visualizar(VB, dimB);
            }
            if(z==2){
                printf("Conjunto A:\n");
                Visualizar(VA,dimA);
            };
            if(z==3){
                printf("\nConjunto B:\n");
                Visualizar(VB, dimB);
            }
            if(z==4){
                printf("\nConjunto resultante:\n");
                Visualizar(VC, dimC);
            }
            system("pause");
            break;
    case 11: printf("Deseja encerrar o programa?[S/N]\n[OPÇÃO]=");
            do{
            fflush(stdin);
            scanf("%c", &ch);
            fflush(stdin);
            }while(ch!='S' && ch!='N');
            break;
    }
    switch(x){
    case 1: system("cls");
            printf("[ENTRE 1 A 100]\n\n Insira o tamanho de A: ");
            Dimensao(&dimA);
            printf("\n\n Insira o tamanho de B: ");
            Dimensao(&dimB);
            system("cls");
            printf("Deseja:\n [1]Inserir os elementos manualmente\n [2]Gerar os elementos randomicamente\n[OPÇÃO]= ");
            scanf("%d", &z);
            if(z==1){
                system("cls");
                printf("Insira os elementos de A:");
                Introduzir(VA, dimA);
                system("cls");
                printf("Insira os elementos de B:");
                Introduzir(VB, dimB);
            }
             else if(z==2){
                Random(VA, VB, dimA, dimB);
            };
            ShellSort(VA, dimA);
            ShellSort(VB, dimB);
            x=0;
            break;

    case 2: system("cls");
            printf("[ENTRE 1 A 100]\n\n Insira o tamanho de A: ");
            Dimensao(&dimA);
            system("cls");
            printf("Deseja:\n [1]Inserir os elementos manualmente\n [2]Gerar os elementos randomicamente\n[OPÇÃO]= ");
            scanf("%d", &z);
            if(z==1){
                system("cls");
                printf("Insira os elementos de A:");
                Introduzir(VA, dimA);
            }
            else if(z==2){
                Random(VA, VB, dimA, dimB);
            };
            ShellSort(VA, dimA);
            x=0;
            break;
    case 3:system("cls");
            printf("[ENTRE 1 A 100]\n\n Insira o tamanho de B: ");
            Dimensao(&dimB);
            system("cls");
            printf("Deseja:\n [1]Inserir os elementos manualmente\n [2]Gerar os elementos randomicamente\n[OPÇÃO]= ");
            scanf("%d", &z);
            if(z==1){
                system("cls");
                printf("Insira os elementos de B:");
                Introduzir(VB, dimB);
            }
            else if(z==2){
                Random(VA, VB, dimA, dimB);
            };
            ShellSort(VB, dimB);
            x=0;
            break;
     case 4: break;
    }
    }while(ch=='N');
    return(0);
}
