#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QUEBRA "\n\n\n"
#define OPCOES "[1]-Intersec��o entre A e B \n[2]-Uni�o entre A e B \n[3]-Diferen�a A menos B \n[4]-Diferen�a B menos A \n[5]Verificar se um elemento arbitr�rio pertence ao conjunto \n[6]Verificar se h� elemtos repetidos em A ou B \n[7]Eliminar elementos repitidos de um conjunto \n[8]Verificar se um conjunto � vazio\n[9]Determinar a quantidade de elementos do conjunto\n[10]Visualizar em qualquer momeno os conjuntos envolvidos A e B e os conjuntos resultantes \n\nEscolha uma opera��o:"
void Aleatorio();
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
void Visualizar();

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    int x, y;
    do{
    system("cls");
    printf(" ####### Trabalho pr�tico de programa��o 1 - ATP 2 #######");
    puts(QUEBRA);
    printf("Como deseja gerar os conjuntos A e B?\n\n");
    printf("[1]-Gerar randomicamente \n[2]-Introduzir os valores\n[3]-Sair");
    puts(QUEBRA);
    printf("Escolha uma opera��o: ");
    scanf("%d", &x);
    }while(x>=1 && x<=3);

    switch(x){
    case 1: do{system("cls");puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 2: do{system("cls");puts(OPCOES);scanf("%d", &y);}while(y<1 || y>10);break;
    case 3: return 0;
    }
    switch(y){

    }
    return 0;
}
