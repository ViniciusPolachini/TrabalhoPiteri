/* TPP-03 ATP II */
/* Rafael Bassi Rosseto // 191251968 */
/* Vinicius Polachini Mayer Freitas de Jesus // 191251852 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Bibliotecas */

#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Definir limpeza de tela para Windows e Linux */

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar matriz mágica de ordem ímpar */

void matriz_impar(int ordem){

    int matriz[ordem][ordem], i, j, num;

    for(i = 0; i < ordem; i++){
        for (j = 0; j < ordem; j++){
            matriz[i][j] = 0;
        }
    }

    i = ordem / 2;
    j = ordem - 1;

    for (num = 1; num <= ordem * ordem;){
        if (i == -1 && j == ordem){
            j = ordem - 2;
            i = 0;
        }

        else{
            if (j == ordem)
                j = 0;

            if (i < 0)
                i = ordem - 1;
        }

        if (matriz[i][j]){
            j -= 2;
            i++;
            continue;
        }

        else matriz[i][j] = num++;

        j++; i--;
    }

    printf("\n\nMatriz magica de ordem =%d:\n\n", ordem);
    for (i = 0; i < ordem; i++){
        for (j = 0; j < ordem; j++){
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSoma de cada linha/coluna = %d\n\n", ordem * (ordem * ordem + 1) / 2);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar matriz mágica de ordem multipla de 4 */

void matriz_mult_4(int ordem){

    int matriz[ordem][ordem], i, j;

    for(i = 0; i < ordem; i++){
        for (j = 0; j < ordem; j++){
            matriz[i][j] = (ordem*i) + j + 1;
        }
    }

    for (i = 0; i < ordem / 4; i++){
        for (j = 0; j < ordem / 4; j++){
            matriz[i][j] = (ordem * ordem + 1) - matriz[i][j];
        }
    }

    for (i = 0; i< ordem / 4; i++){
        for (j = 3* (ordem / 4); j < ordem; j++){
            matriz[i][j] = (ordem * ordem + 1) - matriz[i][j];
        }
    }

    for (i = 3 * ordem / 4; i < ordem; i++){
        for (j = 0; j < ordem / 4; j++){
            matriz[i][j] = (ordem * ordem + 1) - matriz[i][j];
        }
    }

    for (i = 3 * ordem / 4; i < ordem; i++){
        for (j = 3 * ordem / 4; j < ordem; j++){
            matriz[i][j] = (ordem * ordem + 1) - matriz[i][j];
        }
    }

    for (i = ordem / 4; i < 3 * ordem / 4; i++){
        for (j = ordem / 4; j < 3 * ordem / 4; j++){
            matriz[i][j] = (ordem * ordem + 1) - matriz[i][j];
        }
    }

    printf("\n\nMatriz magica de ordem =%d:\n\n", ordem);
    for (i = 0; i < ordem; i++){
        for (j = 0; j < ordem; j++){
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSoma de cada linha/coluna = %d\n\n", ordem * (ordem * ordem + 1) / 2);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar matriz mágica de ordem par */

void matriz_par(int ordem){
    /*função*/
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Menu do Programa */

int main (void){

    setlocale(LC_ALL,"Portuguese");

    unsigned int ordem;

    do{
        system(CLEAR);
        printf("\n ###### Trabalho pratico de programação 03 ######\n");
        printf("\nInsira a ordem da matriz mágica à ser gerada:\n");
        scanf("%d", &ordem);
    }while(ordem < 1 || ordem > 32);

    if(ordem % 2 != 0){
        system(CLEAR);
        matriz_impar(ordem);
        printf("\nPressione ENTER para sair.");
        getchar();
        getchar();
    }

    else if(ordem % 4 == 0){
        matriz_mult_4(ordem);
        printf("\nPressione ENTER para sair.");
        getchar();
        getchar();
    }

    /*
    else{
        matriz_par(ordem);
        printf("\nPressione ENTER para sair.");
        getchar();
        getchar();
    }
    */

    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
