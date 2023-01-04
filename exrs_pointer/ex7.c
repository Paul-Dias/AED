#include <stdio.h>
#include <stdlib.h>

int soma (int* ,int*);

int main(){
    int a, b;
    printf("digite n1:");
    scanf("%i",&a);

    printf("digite n2:");
    scanf("%i",&b);

    printf("\nn1: %i",a);
    printf("\nn2: %i",b);

    soma (&a,&b);

    printf("\nn1: %i",a);

    
    return 0;
}

int soma(int *num1, int *num2){
    *num1= *num1 + *num2;
}