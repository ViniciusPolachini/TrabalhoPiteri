
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 100
#define QUEBRA "\n\n\n"
#define OPCOES "\n[1] Intersecção entre A e B \n[2] União entre A e B \n[3] Diferença A menos B \n[4] Diferença B menos A \n[5] Verificar se um elemento arbitrário pertence ao conjunto \n[6] Verificar se há elemtos repetidos em A ou B \n[7] Eliminar elementos repitidos de um conjunto \n[8] Verificar se um conjunto é vazio\n[9] Determinar a quantidade de elementos do conjunto\n[10] Visualizar em qualquer momeno os conjuntos envolvidos A e B e os conjuntos resultantes \n\nEscolha uma operação: "

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

void    ElementosRep(int *ptrA, int *ptrB, int dimA, int dimB){
    int i, j, aux=0;
    for(i=0; i<dimA; i++)
        for(j=0; j<dimB; j++)
            if(*(ptrA+i)==*(ptrB+j)){
                printf("%d\n", *(ptrA+i));
                aux=1;
            }

    if(aux) printf("[ELEMENTOS REPETIDOS ACIMA]");
        else printf("Não há elementos repetidos");
}

void Interseccao(int *ptrA, int *ptrB, int *ptrC, int dimA, int dimB, int *dimC){
    int i,j,k=0, continua;

    for(i=0; i<dimA; i++){
        continua=1;
        for(j=0;j<dimB && continua;j++){
            if(*(ptrA+i)==*(ptrB+j)){
                *dimC=*dimC+1;
                *(ptrC+k)=*(ptrA+i);
                k++;
                continua=0;
            }
        }
    }

    printf("Conjunto interscção: ");
    Visualizar(ptrC, *dimC);

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

    printf("A-B: ");
    Visualizar(ptrC, *dimC);

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

    printf("A-B: ");
    Visualizar(ptrC, *dimC);
}

void ElementoArb(int *ptr, int dim, int chave){
    int i;

    for(i=0; i<dim; i++){
        if(*(ptr+i)==chave){
            printf(" Não está nesse conjunto\n");
            return;
        }
    }

    printf(" Está nesse conjunto\n");
    return;
}

int Dimensao(){
     int dim;

     do{
      scanf("%d", &dim);
     }while(dim<1 || dim>MAX);

     return(dim);
}

void Introduzir(int *ptr, int dim){
    int i;

    for(i=0; i<=dim-1; i++){
        printf("\nV[%d]: ", i);
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

void Bubble_Sort (int *ptrA, int Dim)
{
    int i=1, j=1, lim, continua=1;
    while ( (i< Dim) && continua )
    {
        continua = 0;
        lim = Dim - 1;
        for(j=0; j<lim; j++)
            if ( *(ptrA+j+1) < *(ptrA+j) )
            {
                Troca (ptrA+j);
                continua = 1;
            }
        i++;
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
        printf("\n%d", *(ptr+i));
    }
}

int main(void)
{
    int dimA=MAX, dimB=MAX, dimC=MAX*2, VA[dimA],VB[dimB],VC[dimC], x, y;
    dimC=0;
    setlocale(LC_ALL,"Portuguese");

    do{
    system("cls");
    printf(" ####### Trabalho pratico de programacao 1 - ATP 2 #######");
    puts(QUEBRA);
    printf("Selecione um tamanho para o conjunto A, entre 1 e 100: ");
    dimA = Dimensao();
    printf("Selecione um tamanho para o conjunto B, entre 1 e 100: ");
    dimB = Dimensao();
    printf("Como deseja gerar os conjuntos A e B?\n\n");
    printf("[1]-Gerar randomicamente \n[2]-Introduzir os valores\n[3]-Sair");
    puts(QUEBRA);
    printf("Escolha uma operação: ");
    scanf("%d", &x);
    }while(x<1 || x>3);

    switch(x){
    case 1: do{Random(VA,VB,dimA, dimB);
            ShellSort(VA, dimA);
            ShellSort(VB, dimB);
            system("cls");
            puts(OPCOES);
            scanf("%d", &y);}while(y<1 || y>10);
            break;

    case 2: do{system("cls");
            printf("Introduza os valores de A:");
            Introduzir(VA, dimA);
            printf("Introduza os valores de B:");
            Introduzir(VB, dimB);
            ShellSort(VA, dimA);
            ShellSort(VB, dimB);
            puts(OPCOES);
            scanf("%d", &y);}while(y<1 || y>10);
            break;

    case 3: return(0);
    }

    switch(y){
    case 1:system("cls");
            Interseccao(VA, VB, VC, dimA, dimB, &dimC);
            break;
    case 2:system("cls");
           Uniao(VA, VB, VC, dimA, dimB, &dimC);
           Visualizar(VC, dimC);
           break;
    case 3:system("cls");
            difAB(VA, VB, VC, dimA, dimB, &dimC);
            break;
    case 4:system("cls");
            difBA(VA, VB, VC, dimA, dimB, &dimC);
            break;
    case 5:system("cls");
            int chave;
           printf("Escolha um elemento: ");
           scanf("%d", &chave);
           printf("VA: ");
           ElementoArb(VA, dimA, chave);
           printf("VB: ");
           ElementoArb(VB, dimB, chave);
           printf("VC: ");
           ElementoArb(VC, dimC, chave);
            break;
    case 6:system("cls");
            ElementosRep(VA, VB, dimA, dimB);
            break;
    case 7:system("cls");
            Repetidos(VA, &dimA);
            Repetidos(VB, &dimB);
            printf("Conjunto A: ");
            Visualizar(VA,dimA);
            printf("\nConjunto B: ");
            Visualizar(VB, dimB);
            break;
    case 8: system("cls");
            printf("Conjunto A ");
            Vazio(VA, dimA);
            printf("Conjunto B ");
            Vazio(VB, dimB);
            printf("Conjunto C ");
            Vazio(VC, dimC);
            break;
    case 10:system("cls");
            printf("Conjunto A: ");
            Visualizar(VA,dimA);
            printf("\nConjunto B: ");
            Visualizar(VB, dimB);
            printf("\nConjunto C: ");
            Visualizar(VC, dimC);
            break;
    }

}
