/*Escreva uma func¸ ˜ao que receba um array de inteiros V e os enderec¸os de duas vari ´aveis
inteiras, min e max, e armazene nessas vari ´aveis o valor m´ınimo e m´aximo do array.
Escreva tamb´em uma func¸ ˜ao main que use essa func¸ ˜ao.
*/

#include <stdio.h>
#include<stdlib.h>
void minmax(int *v, int n, int *min, int *max);

int main()
{
    //definindo tamanho do vetor.
    int n, *vet, min, max,i;
    printf("digite o tamanho do array: ");
    scanf("%d", &n);
    vet = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Digite os elementos do vetor: ");
        scanf("%d", &vet[i]);
    }

    minmax(vet, n, &min, &max); //endereços

    printf("Min: %d. Max: %d.\n", min, max);
    free(vet);
    return 0;
}

void minmax(int *v, int n, int *min, int *max)
{
    int i;
    *min = v[0];
    *max = v[0];
    for (i = 0; i < n; i++)
    {
        if (v[i] > *max)
        {
            *max = v[i];
        }
        else if (v[i] < *min)
        {
            *min = v[i];
        }
    }
}