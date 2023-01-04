#include <stdio.h>
#include <stdlib.h>

int frac(float, int *, float *);

int main()
{
    float num, fraci;
    int inteiro;
    printf("digite um numero: ");
    scanf("%f", &num);

    frac(num, &inteiro, &fraci);

    printf("%d \n",inteiro);
    printf("%f",fraci);
    return 0;
}

int frac(float num, int *inteiro, float *fraci)
{
    *inteiro=num;  
    *fraci= num - *inteiro;
}