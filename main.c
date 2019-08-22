#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 100
#define QUEBRA "\n\n\n"
#define OPCOES "\n[1] Intersecção entre A e B \n[2] União entre A e B \n[3] Diferença A menos B \n[4] Diferença B menos A \n[5] Verificar se um elemento arbitrário pertence ao conjunto \n[6] Verificar se há elemtos repetidos em A ou B \n[7] Eliminar elementos repitidos de um conjunto \n[8] Verificar se um conjunto é vazio\n[9] Determinar a quantidade de elementos do conjunto\n[10] Visualizar em qualquer momeno os conjuntos envolvidos A e B e os conjuntos resultantes \n\nEscolha uma operação:"
void Introduzido();
void Ordenacao();
void Interseccao();
void Uniao();
void Diferenca();
void Arbitrario();
void Repetidos();
void Elimina();
void Vazio();
void Quantidade();
void Visualizar(int *ptrA, int *ptrB);

void Bubble_Sort (int *A, int Dim)
{
    int i=1, j=1, lim, continua=1;
    while ( (i< Dim) && continua )
    {
        continua = 0;
        lim = Dim - 1;
        for(j=0; j<lim; j++)
            if ( *(A+j+1) < *(A+j) )
            {
                Swap (A+j);
                continua = 1;
            }
        i++;
    }
return;
}

void Swap(int *Ptra) {
 int aux;

 aux = *Ptra;
 *Ptra = *(Ptra+1);
 *(Ptra+1) = aux;
}

void Random(int *A, int *B, int Dim)
{
 int i,j;
 clock_t seed;

 seed = clock();
 srand((unsigned) seed);
 for (i = 0; i < Dim; i++)
     A[i]= rand();

 for (j = 0; j < Dim; j++)
     B[j]= rand();

 return;
}

void Visualizar(int *ptrA, int *ptrB){
    int i;
    for(i=0; i<=MAX-1; i++){
        printf("%d////%d\n", *(ptrA+i), *(ptrB+i));
    }
}

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    int x, y, VA[MAX],VB[MAX],VC[MAX*2];
    do{
    system("cls");
    printf(" ####### Trabalho prático de programação 1 - ATP 2 #######");
    puts(QUEBRA);
    printf("Como deseja gerar os conjuntos A e B?\n\n");
    printf("[1]-Gerar randomicamente \n[2]-Introduzir os valores\n[3]-Sair");
    puts(QUEBRA);
    printf("Escolha uma operação: ");
    scanf("%d", &x);
    }while(x<1 || x>3);

    switch(x){
    case 1: do{Random(VA,VB,MAX); Bubble_Sort(VA, MAX);Bubble_Sort(VB, MAX);system("cls");puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 2: do{system("cls");puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 3: return 0;
    }
    switch(y){
    case 10: printf("A////B\n"); Visualizar(VA, VB); break;
    }
    return 0;
}
