#include <stdlib.h>
#include <stdio.h>

int raizes(float A, float B, float C, float *X1, float *X2);

int main()
{
    float A,B,C,X1,X2;
    int raiz;

    printf("digite o valor de A(AX^2):");
    scanf("%f", &A);

    printf("digite o valor de B(Bx):");
    scanf("%f", &B);

    printf("digite o valor de C(C):");
    scanf("%f", &C);

    raiz=raizes(A,B,C, &X1,&X2);
    
    printf("%d",raiz);
}

int raizes(float A, float B, float C, float *X1, float *X2)
{
    float delt,raiz;

    delt = B * B - 4 * A * C;

    if (delt < 0)
    {
        return 0;
    }
        *X1 = (-B - delt) / 2 * A;
        *X2 = (-B + delt) / 2 * A;

    if (delt == 0)
    {
        return 1;
    }
    else if (delt >= 0)
    {      
        return 2;
    }  
}