#include <stdio.h>
#include <stdlib.h>

/*
//Escreva um programa que contenha duas vari ´aveis inteiras. Leia essas vari ´aveis do
//teclado. Em seguida, compare seus enderec¸os e exiba o conte´udo do maior enderec¸o.

*/


int main(){
    int n1, n2, *ptrN1, *ptrN2;

    ptrN1=&n1;
    ptrN1=&n2;

    printf("digite n1:");
    scanf("%i",&n1);

    printf("digite n2:");
    scanf("%i",&n2);

    if(*ptrN1<*ptrN2){
        printf("esse e o maior%i",*ptrN2);
    }else
    printf("esse e o maior%i",*ptrN1);

    
}