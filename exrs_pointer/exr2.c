#include <stdio.h>
#include <stdlib.h>
/*screva um programa que contenha duas vari ´aveis inteiras. Compare seus enderec¸os e
exiba o maior enderec¸o.*/
int main(){
    int n1, n2, *ptrN1, *ptrN2;

    ptrN1=&n1;
    ptrN1=&n2;

    printf("digite n1:");
    scanf("%i",&n1);

    printf("digite n2:");
    scanf("%i",&n2);

    if(ptrN1<ptrN2){
        printf("esse e o maior ptr%i",ptrN2);
    }else
    printf("esse e o maior%i",ptrN1);

    
}

