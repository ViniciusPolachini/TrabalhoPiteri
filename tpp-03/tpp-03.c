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
            if (j == ordem) j = 0;
            if (i < 0) i = ordem - 1;
        }

        if (matriz[i][j]){
            j -= 2;
            i++;
            continue;
        }

        else matriz[i][j] = num++;

        j++; i--;
    }

    imprime_matriz(&matriz[0][0], ordem);

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

    imprime_matriz(&matriz[0][0], ordem);

}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar matriz mágica de ordem par */

void matriz_par(int ordem){
     int matriz[ordem][ordem],aux=(ordem*ordem)/4, aux2=ordem/2, aux3, i, j, num=1;
    
     for(i = 0; i < ordem; i++){
        for (j = 0; j < ordem; j++){
            matriz[i][j] = 0;
        }
    }

    i=0; j=ordem/4;
    
    while(num<=aux){
        matriz[i][j]=num;
        num++;
        if(i-1>=0 && j+1<aux2){
            if(matriz[i-1][j+1]==0){
                i--;
                j++;
            }
            else{
                i++;
            }
        }
        else if(i-1>=0){
            if(matriz[i-1][0]==0){
                j=0;
                i--;
            }
            else{
                i++;
            }
        }
        else if(j+1<aux2){
            if(matriz[aux2-1][j+1]==0){
                j++;
                i=aux2-1;
            }
            else{
                i++;
            }
        }
        else{
            if(matriz[aux2-1][0]==0){
                j=0;
                i=aux2-1;
            }
            else{
                i++;
            }
        }
    }

    aux+=(ordem*ordem)/4; i=ordem/2; j+=aux2;

    while(num<=aux){
        matriz[i][j]=num;
        num++;
        if(i-1>=aux2 && j+1<ordem){
            if(matriz[i-1][j+1]==0){
                i--;
                j++;
            }
            else{
                i++;
            }
        }
        else if(i-1>=aux2){
            if(matriz[i-1][aux2]==0){
                j=aux2;
                i--;
            }
            else{
                i++;
            }
        }
        else if(j+1<ordem){
            if(matriz[ordem-1][j+1]==0){
                j++;
                i=ordem-1;
            }
            else{
                i++;
            }
        }
        else{
            if(matriz[ordem-1][aux2]==0){
                j=aux2;
                i=ordem-1;
            }
            else{
                i++;
            }
        }
    }

    aux+=(ordem*ordem)/4; i=0;

    while(num<=aux){
        matriz[i][j]=num;
        num++;
        if(i-1>=0 && j+1<ordem){
            if(matriz[i-1][j+1]==0){
                i--;
                j++;
            }
            else{
                i++;
            }
        }
        else if(i-1>=0){
            if(matriz[i-1][aux2]==0){
                j=aux2;
                i--;
            }
            else{
                i++;
            }
        } 
        else if(j+1<ordem){
            if(matriz[aux2-1][j+1]==0){
                j++;
                i=aux2-1;
            }
            else{
                i++;
            }
        }
        else{
                if(matriz[aux2-1][aux2]==0){
                    j=aux2;
                    i=aux2-1;
            }
            else{
                i++;
            }
        }
    }

    aux+=(ordem*ordem)/4; i=ordem/2; j=ordem/4;

    while(num<=aux){
        matriz[i][j]=num;
        num++;
        if(i-1>=aux2 && j+1<aux2){
            if(matriz[i-1][j+1]==0){
                i--;
                j++;
            }
            else{
                i++;
            }
        }
        else if(i-1>=aux2){
            if(matriz[i-1][0]==0){
                j=0;
                i--;
            }
            else{
                i++;
            }
        }
        else if(j+1<aux2){
            if(matriz[ordem-1][j+1]==0){
                j++;
                i=ordem-1;
            }
            else{
                i++;
            }
        }
        else{
                if(matriz[ordem-1][0]==0){
                    j=0;
                    i=ordem-1;
            }
            else{
                i++;
            }
        }
    }

    for(i=0; i<aux2; i++)
        for(j=0; j<aux2/2; j++){
            aux3=matriz[i][j];
            matriz[i][j]=matriz[i+aux2][j];
            matriz[i+aux2][j]=aux3;
        }

    aux3=matriz[(aux2/2)][(aux2/2)];
    matriz[(aux2/2)][(aux2/2)]=matriz[(aux2/2)+aux2][(aux2/2)];
    matriz[(aux2/2)+aux2][(aux2/2)]=aux3;

    imprime_matriz(&matriz[0][0], ordem);
}



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Imprimir Matriz */

void imprime_matriz(int *matriz, int ordem){

    printf("\n\nMatriz magica de ordem = %d:\n\n", ordem);
    for (int i = 0; i < ordem; i++){
        for (int j = 0; j < ordem; j++){
            printf("%5d ", *(matriz + i*ordem + j));
        }
        printf("\n");
    }
    printf("\n\nSoma de cada linha/coluna = %d\n\n", ordem * (ordem * ordem + 1) / 2);
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Menu do Programa */

int main(void){

    setlocale(LC_ALL,"Portuguese");

    unsigned int ordem;
    char ch;

    do{
        system(CLEAR);
        printf("\n ###### Trabalho pratico de programação 03 ######\n");
        printf("\nInsira a ordem da matriz mágica à ser gerada:\n");
        scanf("%d", &ordem);
    }while(ordem < 3 || ordem > 14);

    if(ordem % 2 != 0){
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

    
    else{
        matriz_par(ordem);
        printf("\nPressione ENTER para sair.");
        getchar();
        getchar();
    }

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
