#include <stdio.h>
#include <stdlib.h>
// #include<conio.h> //caso ocorrer erro ao usar getch

int main()
{
    float vetor[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    int i;
    for(i = 0; i < 10; i++){
        printf("Endereco do vetor[%i]: %p \n ",i, vetor + i); // %p específico para posição do ponteiro
       // printf("Endereco: %p\tConteudo: %d\n", vetor + i, *(vetor + i); e conteudo
    }
    printf("press algo para sair");
    getch();
    return 0;
}
    

