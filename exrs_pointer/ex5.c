#include <stdio.h>
#include <stdlib.h>
/*Fac¸a um programa que leia dois valores inteiros e chame uma func¸ ˜ao que receba estes
2 valores de entrada e retorne o maior valor na primeira vari ´avel e o menor valor na
segunda vari ´avel. Escreva o conte´udo das 2 vari ´aveis na tela.*/

void maiorRecebe (int* ,int* );

int main(){

    int a, b;

    printf("digite n1:");
    scanf("%i",&a);

    printf("digite n2:");
    scanf("%i",&b);

    maiorRecebe (&a,&b);

    printf("\nn1: %i",b);
    printf("\nn2: %i",a);
    return 0;
}


void maiorRecebe(int *num1, int *num2){
int aux;
if(*num2>*num1)
{
    aux=*num1;
    *num1=*num2;
    *num2=aux;
}
else
    aux=*num2;
    *num2=*num1;
    *num1=aux;

}