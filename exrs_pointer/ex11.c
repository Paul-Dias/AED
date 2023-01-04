#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5]={1,2,3,4,5};
    int l, j;

    for (j = 0; j < 5; j++)
    {
        if(*(vet + j)%2==0)
        printf("%d ,%p \n",*(vet + j), (vet + j));
    }
}
