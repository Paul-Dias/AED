#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

int main()
{
  Matriz matriz = NULL;
  int linha = 0;
  int colunas = 0;
  int op = 0;

  do
  {
    printf("\nMenu:");
    printf("\n1 - Cria Matriz");
    printf("\n2 - Insere na Matriz");
    printf("\n3 - Retira da Matriz");
    printf("\n4 - Imprime Matriz");
    printf("\n5 - Sair");
    printf("\nOpção: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:

      if (matriz != NULL)
      {
        printf("A Matriz ja foi criada\n");
        printf("Pressione Enter");
        getchar();
        break;
      }

      printf("Informe as dimensoes da matriz:\n");
      printf("Numero de linhas: ");
      scanf("%d", &linha);
      printf("Numero de colunas: ");
      scanf("%d", &colunas);
      matriz = criarMatriz(linha, colunas);

      if (matriz != NULL)
        printf("\nMatriz criada com sucesso!\n");
      else
        printf("\nFalha ao criar matriz\n");
      break;

    case 2:

      if (matriz == NULL)
      {
        printf("A Matriz ainda nao foi criada!\nPressione Enter");
        getchar();
        break;
      }
      int elemento, linha, col;

      printf("Numero a ser adicionado: ");
      scanf("%d", &elemento);
      printf("Linha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &col);

      if (insereNaMatriz(matriz, elemento, linha, col))
        printf("Numero inserido na matriz\n");
      break;

    case 3:

      if (matriz == NULL)
      {
        printf("A Matriz ainda nao foi criada\n");
        break;
      }

      printf("Linha: ");
      scanf("%d", &linha);
      printf("Coluna: ");
      scanf("%d", &col);

      if (retiraDaMatriz(matriz, linha, col))
        printf("Numero removido com sucesso!\n");
      break;

    case 4:
      if (matriz == NULL)
      {
        printf("A Matriz ainda nao foi criada\n");
        break;
      }

      imprimeMatriz(matriz);
      break;

    case 5:
      printf("\nFim\n\n");
      freeMatriz(matriz);
      break;

    default:
      printf("\nOpcao invalida, tente novamente!\n");
      break;
    }

  } while (op != 5);

  return 0;
}