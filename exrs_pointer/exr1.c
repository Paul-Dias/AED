#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in-
teiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de  ́

cada variavel usando os ponteiros. Imprima os valores das vari  ́ aveis antes e ap  ́ os a  ́
modificac ̧ao.  ̃*/

int main(){
    int n;
    char c;
    float r;

    int *ptrN;
    char *ptrC;
    float *ptrR;

    ptrN= &n;
    ptrC= &c;
    ptrR= &r;

    printf("digite um inteiro (n):");
    scanf("%i",ptrN);


    getchar();
    printf("\ndigite o char:");
    scanf("%c", ptrC);


    printf("digite o real:");
    scanf("%f", ptrR);

    printf("antes");
    printf("\nReal r: %f",*ptrR);
    printf("\nChar c : %c",*ptrC);
    printf("\ninteiro n: %i",*ptrN);

    *ptrR=7;
    *ptrN=9;
    *ptrC='p';
    
    printf("\nmudado");
    printf("\nReal r: %f",*ptrR);
    printf("\nChar c : %c",*ptrC);
    printf("\ninteiro n: %i",*ptrN);


    return 0;
}
