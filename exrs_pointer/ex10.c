#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5];
    int l, j;

    for (l = 0; l < 5; l++)
    {
        printf("vetor [%d]: ", l + 1);
        scanf("%d", &vet[l]);
    }
    for (j = 0; j < 5; j++)
    {
        printf("%d ", *(vet + j) * 2);
    }
}
