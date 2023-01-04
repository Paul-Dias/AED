#include <stdio.h>
#include <stdlib.h>

//intelicode
/*
Fac¸a um programa que leia 2 valores inteiros e chame uma func¸ ˜ao que receba estas
2 vari ´aveis e troque o seu conte´udo, ou seja, esta func¸ ˜ao ´e chamada passando duas
vari ´aveis A e B por exemplo e, ap´os a execuc¸ ˜ao da func¸ ˜ao, A conter´a o valor de B e B
ter ´a o valor de A*/

void trocaDeConteudo (int* ,int* );

int main(){

    int a, b;


    printf("digite n1:");
    scanf("%i",&a);

    printf("digite n2:");
    scanf("%i",&b);

    trocaDeConteudo (&a,&b);

    printf("\nn1: %i",a);
    printf("\nn2: %i",b);
    return 0;
}


void trocaDeConteudo(int *num1, int *num2){
int aux;

aux=*num1;
*num1=*num2;
*num2=aux;

}