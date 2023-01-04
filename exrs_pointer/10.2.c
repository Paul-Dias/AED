#include <stdio.h>
#include <stdlib.h>

void imprimir(int vet[], int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("%d ", *(vet+ i)*2);
    printf("\n");
}

int main(){

    int vet[5];
    int i;
    for (i = 0; i < 5; i++)   /*Este laco faz o scan de cada elemento do vetor*/
    {
         printf("\ndigite 5 vezes:");
       scanf("%d", &vet[i]);
    }

    imprimir(vet, 5);

    return 0;
}