/* 
 * Trabalho Prático de Programação 05 - ATP II
 * Rafael Bassi Rosseto // 191251968
 * Vinicius Polachini Mayer Freitas de Jesus // 191251852
 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct polinomio{

    int coef;
    int expo;
    struct polinomio *next, *prev;

}poli;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void criarPolinomio(poli *inicio, poli *fim){

    int coef, expo;
    poli *node, *ptr;
    int vefificador = 1;

    do{
        printf("\nNovo termo para o polinomio:");
        printf("\nIntroduza o coeficiente que acompanha x: ");
        scanf("%d", &coef);
        printf("\nIntroduza o expoente que acompanha %dx: ", coef);
        scanf("%d", &expo);

        node = (poli*)malloc(sizeof(poli));
        node->coef = coef;
        node->expo = expo;

        if(inicio == NULL && fim == NULL){    // lista vazia, inserir primeiro elemento
            inicio = &node;
            fim = &node;
            inicio->prev = NULL;
            inicio->next = NULL;
        }
        else if(expo > inicio->expo){           // inserir elemento no inicio da lista
            inicio->prev = node;
            node->next = inicio->next;
            node->prev = NULL;
            inicio = &node;
        }
        else if(expo < fim->expo){              // inserir elemento no fim da lista
            fim->next = node;
            node->prev = fim->prev;
            node->next = NULL;
            fim = &node;
        }
        else{                                   // buscar posição apropriada para o elemento
            ptr = inicio;
            while(expo > ptr->next->expo){
                ptr = ptr->next;
            }
            ptr->next = &node;
            node->prev = ptr;
            ptr->next->prev = node;
            node->next = ptr->next;
        }

        printf("\nDeseja adicionar outro termo no polinomio? ([1]Sim / [0]Não) ");
        scanf("%d", &vefificador);

    }while(vefificador);

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void imprimirPolinomio(poli *inicio){

    poli *ptr;
    ptr = inicio;

    printf("f(x) = ");
    do{
        printf("%dx^%d + ", ptr->coef, ptr->expo);
        ptr = ptr->next;
    }while(ptr->next != NULL);

    printf("%dx^%d", ptr->coef, ptr->expo);

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main(void){

    system(CLEAR);

    poli *Fx_inicio = NULL, *Fx_fim = NULL, *Gx_inicio = NULL, *Gx_fim = NULL;

    criarPolinomio(Fx_inicio, Fx_fim);
    imprimirPolinomio(Fx_inicio);

    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
