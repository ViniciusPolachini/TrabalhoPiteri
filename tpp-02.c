/* TPP-02 ATP II */
/* Rafael Bassi Rosseto // 191251968 */
/* Vinicius Polachini Mayer Freitas de Jesus // 191251852 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Bibliotecas */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Definir limpeza de tela para Windows e Linux */

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Maximo valor do Array */

#define MAX 1000

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Merge Sort */

void Merge(int array[], int inicio, int meio, int fim) 
{
  int i, j, k;
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++) L[i] = array[inicio + i];
  for (j = 0; j < n2; j++) R[j] = array[meio + 1 + j];
  i = 0;
  j = 0;
  k = inicio;
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      array[k] = L[i];
      i++;
    }
    else{
      array[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1){
    array[k] = L[i];
    i++;
    k++;
  }
  while (j < n2){
    array[k] = R[j];
    j++;
    k++;
  }
}

void MergeSort(int *array, int inicio, int fim){
  if ( inicio < fim ){
    int meio = (inicio + fim)/2;
    MergeSort(array, inicio, meio);
    MergeSort(array, meio+1, fim);
    Merge(array, inicio, meio, fim);
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Quick Sort */

void QuickSort(int array[], int inicio, int fim){
  int i, j, pivot, temp;
  if (inicio < fim){
    pivot = inicio;
    i = inicio;
    j = fim;
    while(i < j){
      while(array[i] <= array[pivot] && i < fim)
      i++;
      while(array[j] > array[pivot])
      j--;
      if(i < j){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;
    QuickSort(array, inicio, j-1);
    QuickSort(array, j+1, fim);
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar Números Aleatórios */

void Random(int *ptr, int dim)
{
     int i;
     clock_t seed;
     seed = clock();
     srand(seed);
     for (i = 0; i < dim; i++)
         *(ptr + i)= rand() % (99999 + 1 - 0) + 0; /* [0, 99999] */
     return;
}

/*
  Como restringir o intervalo gerado pela função rand:
  rand() % (maior_valor + 1 - menor_valor) + menor_valor;
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Exibir Elementos de um Array */

void Visualizar(int *ptr, int dim){
    int i;
    for(i=0; i<=dim-1; i++){
        printf("Array[%d]=%d\n", i,*(ptr+i));
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Menu do Programa */

int main(void){

  setlocale(LC_ALL,"Portuguese");

  int optA, optB, array[MAX], dim;
  char ch;

  do{
    system(CLEAR);
    printf("\n ###### Trabalho pratico de programação 02 ######\n");
    printf("\nInsira a dimensão do array: (MIN = 1, MAX = 1000)\n");
    scanf("%d", &dim);
  }while(dim < 1 || dim > MAX);

  do{
    system(CLEAR);
    printf("\nSeu array tem tamanho %d.\n", dim);
    printf("\nDigite [1] para gerar valores aleatórios para o array.");
    printf("\nDigite [2] para sair.\n\n");
    scanf("%d", &optA);
  } while (optA < 1 || optA > 2);

  switch(optA){
    case 1:
      do{
        printf("\nO seu array é:\n\n");
        Random(array, dim);
        Visualizar(array, dim);
        printf("\n\n\n");
        printf("Digite [1] para organizar o array utilizando Quick Sort.\n");
        printf("Digite [2] para Organizar o array utilizando Merge Sort.\n");
        printf("Digite [3] para sair.\n\n");
        scanf("%d", &optB);
      }while(optB < 1 || optB > 3);

      switch(optB){
        case 1:
          QuickSort(array, 0, dim-1);
          printf("\nO array foi organizado: \n\n");
          Visualizar(array, dim);
          printf("\nPressione ENTER para sair.\n\n");
          getchar();
          getchar();
          return 0;

        case 2:
          MergeSort(array, 0, dim-1);
          printf("\nO array foi organizado: \n\n");
          Visualizar(array, dim);
          printf("\nPressione ENTER para sair.\n\n");
          getchar();
          getchar();
          return 0;

        case 3:
          return (0);
      }

    case 2:
      return 0;
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
