#include <stdio.h>
#include <stdlib.h>

int ordenador(int *, int *, int *);

int main()
{
    int n1, n2, n3;

    printf("digite n1:");
    scanf("%i", &n1);

    printf("digite n2:");
    scanf("%i", &n2);

    printf("digite n3:");
    scanf("%i", &n3);

    ordenador(&n1, &n2, &n3);

    printf("\nn1: %i", n1);
    printf("\nn2: %i", n2);
    printf("\nn3: %i", n3);

    return 0;
}

int ordenador(int *num1, int *num2, int *num3)
{
    int aux;
    if (*num1 == *num2 && *num1 == *num3)
    {

        printf("retornou 1");
        return 1;
    }
    else if (*num1 >= *num2 && *num2 >= *num3)
    { // 123

     printf("123");
     return 0;
    }
    else if (*num1 >= *num2 && *num2 <= *num3)
    { // 132

         printf("123");
        aux = *num2;
        *num2 = *num3;
        *num3=aux;
  
    }
    else if (*num1 >= *num2 && *num2 >= *num3)
    {
        aux = *num2;
        *num2 = *num3;
        aux = *num3;
        return 0;
    }
    else if (*num2 >= *num3 && *num3 >= *num1)
    {
        aux = *num1;
        *num1 = *num2;
        *num2 = aux;
        return 0;
    }
    else if (*num3 >= *num1 && *num1 >= *num2)
    {
        aux = *num1;
        *num1 = *num2;
        *num2 = aux;
        return 0;
    }
    else if (*num2 >= *num1 && *num1 >= *num3)
    {

        aux = *num1;
        *num1 = *num2;
        *num2 = aux;

        return 0;
    }
}
