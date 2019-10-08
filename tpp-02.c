/* TPP-02 ATP II */
/* Rafael Bassi Rosseto // 191251968 */
/* Vinicius Polachini */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Bibliotecas */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max 10

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
     srand((unsigned) seed);
     for (i = 0; i < dim; i++)
         *(ptr + i)= rand();
     return;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Exibir Elementos de um Array */

void Visualizar(int *ptr, int dim){
    int i;
    for(i=0; i<=dim-1; i++){
        printf("[%d]=%d\n", i,*(ptr+i));
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Menu do Programa */

int main(void){
  int optA, optB, array[max];

  do{
    system("clear");
    printf("\n ###### Trabalho pratico de programação 02 ######\n");
    printf("\nDigite [1] para gerar um array de tamanho 10");
    printf("\nDigite [2] para sair\n\n");
    scanf("%d", &optA);
  } while ((!optA) || (!optB));

  switch(optA){
    case 1:
      system("clear");
      printf("\nO seu array é:\n\n");
      Random(array, max);
      Visualizar(array, max);
      printf("\n\n\n");
      printf("Digite [1] para organizar o array utilizando Quick Sort");
      printf("\nDigite [2] para Organizar o array utilizando Merge Sort\n\n");
      scanf("%d", &optB);

      switch(optB){
        case 1:
          QuickSort(array, 0, max-1);
          printf("\nO array foi organizado: \n");
          Visualizar(array, max);
          printf("\nPressione ENTER para sair...\n");
          getchar();
          return 0;

        case 2:
          MergeSort(array, 0, max-1);
          printf("\nO array foi organizado: \n");
          Visualizar(array, max);
          printf("\nPressione ENTER para sair...\n");
          getchar();
          return 0;
      }
  case 2:
  getchar();
  return 0;
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
