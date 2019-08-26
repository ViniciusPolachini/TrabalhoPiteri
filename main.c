#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 100
#define QUEBRA "\n\n\n"
#define OPCOES "\n[1] Intersecção entre A e B \n[2] União entre A e B \n[3] Diferença A menos B \n[4] Diferença B menos A \n[5] Verificar se um elemento arbitrário pertence ao conjunto \n[6] Verificar se há elemtos repetidos em A ou B \n[7] Eliminar elementos repitidos de um conjunto \n[8] Verificar se um conjunto é vazio\n[9] Determinar a quantidade de elementos do conjunto\n[10] Visualizar em qualquer momeno os conjuntos envolvidos A e B e os conjuntos resultantes \n\nEscolha uma operação: "


int Dimensao(){
 int dim;
 do{
  printf("Selecione um tamanho para os conjuntos entre 1 e 100: ");
  scanf("%d", &dim);
 }while(dim<1 || dim>MAX);
 return(dim);
}
void Introduzir(int *ptr, int dim){
int i;
for(i=0; i<=dim-1; i++) scanf("%d", &*(ptr+i));
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
                Swap (ptrA+j);
                continua = 1;
            }
        i++;
    }
return;
}

void Swap(int *PtrA) {
 int aux;

 aux = *PtrA;
 *PtrA = *(PtrA+1);
 *(PtrA+1) = aux;
}

void Random(int *ptrA, int *ptrB, int Dim)
{
 int i,j;
 clock_t seed;

 seed = clock();
 srand((unsigned) seed);
 for (i = 0; i < Dim; i++)
     ptrA[i]= rand();

 for (j = 0; j < Dim; j++)
     ptrB[j]= rand();

 return;
}


void Visualizar(int *ptrA, int *ptrB, int dim){
    int i;
    for(i=0; i<=dim-1; i++){
        printf("%d////%d\n", *(ptrA+i), *(ptrB+i));
    }
}

int main(void)
{
    int x, y, dim=0,VA[dim],VB[dim],VC[dim*2];
    setlocale(LC_ALL,"portuguese");
    do{
    system("cls");
    printf(" ####### Trabalho pratico de programacao 1 - ATP 2 #######");
    puts(QUEBRA);
    dim = Dimensao();
    printf("Como deseja gerar os conjuntos A e B?\n\n");
    printf("[1]-Gerar randomicamente \n[2]-Introduzir os valores\n[3]-Sair");
    puts(QUEBRA);
    printf("Escolha uma operação: ");
    scanf("%d", &x);
    }while(x<1 || x>3);

    switch(x){
    case 1: do{Random(VA,VB,dim); Bubble_Sort(VA, dim);Bubble_Sort(VB, dim);system("cls");puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 2: do{system("cls");printf("Introduza os valores de A:"); Introduzir(VA, dim);printf("Introduza os valores de B:"); Introduzir(VB, dim);puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 3: return 0;
    }
    switch(y){
    case 10: printf("A////B\n"); Visualizar(VA, VB, dim); break;
    }
    return 0;
}
