#include <stdio.h>
#include <stdlib.h>
// #include<conio.h> //caso ocorrer erro ao usar getch

int main()
{
    float matriz[3][3];
    int l, c;

    for(l = 0 ; l < 3 ; l++)
        for(c = 0 ; c < 3 ; c++)
        {
            printf("Elemento [%d][%d]: ", l, c);
            scanf("%f", &matriz[l][c]);
        }

    // imprimindo a matriz 
    for(l = 0 ; l < 3 ; l++)
    {
        for(c = 0 ; c < 3 ; c++)
        
            printf("%p ", &matriz[l][c]);
            
        printf("\n"); 
        
    }
}