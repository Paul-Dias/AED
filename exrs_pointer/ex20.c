#include <stdlib.h>
#include <stdio.h>

int negativos(float *vet, int N);

int main()
{
    int N , i,ngt;

    printf("Digite o tamanho do array:\n");
    scanf("%d", &N);

    float vet[N];
    
    for (i = 0; i < N; i++)
    {
        printf("Digite um numero: ");
        scanf("%f", &vet[i]);
    }

    ngt=negativos(vet, N);
    
    printf("numeros negativos no vetor: %d",ngt);
}
int negativos(float *vet, int N)
{
    int i;
    int qnt=0;
    for (i = 0; i < N; i++)
    {
        if (vet[i] < 0)
        {
            qnt++;         
        }    
    }
    return qnt;
}
