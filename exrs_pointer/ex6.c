#include<stdio.h>
#include<stdlib.h>
int soma (int a ,int b );

int main(){
    int a, b,result;
    printf("digite n1:");
    scanf("%i",&a);

    printf("digite n2:");
    scanf("%i",&b);

    result=soma(a,b);

    printf("\nsoma do dobro: %i",result);
    return 0;
}

int soma(int a, int b){
    int result;
    a=a*2;
    b=b*2;
    printf("\nn1: %i",a);
    printf("\nn2: %i",b);
    result = a+b;
    return (result);
}