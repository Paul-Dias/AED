#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

Matriz criarMatriz(int qtdLinhas, int qtdColunas)
{

    matriz *mat = (matriz *)malloc(sizeof(matriz));

    mat->qtdLinhas = qtdLinhas;
    mat->qtdColunas = qtdColunas;

    mat->linhas = (linha **)malloc(qtdLinhas * sizeof(linha *));

    for (int i = 0; i < qtdLinhas; i++)
    {
        mat->linhas[i] = (linha *)malloc(sizeof(linha));
        mat->linhas[i]->colunas = NULL;
        mat->linhas[i]->idLinha = i + 1;
        mat->linhas[i]->colunasOcupadas = 0;
    }

    return mat;
}

int insereNaMatriz(Matriz Mat, int valor, int linhaInserir, int colunaInserir)
{
    if (Mat == NULL)
    {
        printf("Erro ao inserir\n");
        return 0;
    }

    matriz *mat = (matriz *)Mat;

    if (linhaInserir > mat->qtdLinhas || linhaInserir < 1 || colunaInserir > mat->qtdColunas || colunaInserir < 1)
    {
        printf("\nFalha na insercao do valor %d. A matriz possui apenas %d linhas e %d colunas!\n", valor, mat->qtdLinhas, mat->qtdColunas);
        return 0;
    }

    linha *Pposicao = mat->linhas[linhaInserir - 1];
    coluna *primeiraColuna = Pposicao->colunas;

    if (primeiraColuna == NULL) // Insercao na linha vazia
    {
        coluna *novaColuna = (coluna *)malloc(sizeof(coluna));
        novaColuna->valor = valor;
        novaColuna->nColuna = colunaInserir;
        novaColuna->proxCol = NULL;
        Pposicao->colunas = novaColuna;
        Pposicao->colunasOcupadas++;
        return 1;
    }

    else
    {
        coluna *colunaAtual = primeiraColuna;
        if (colunaAtual->nColuna > colunaInserir) // Insercao no inicio
        {
            coluna *novaColuna = (coluna *)malloc(sizeof(coluna));
            novaColuna->valor = valor;
            novaColuna->nColuna = colunaInserir;
            novaColuna->proxCol = colunaAtual;
            Pposicao->colunas = novaColuna;
            Pposicao->colunasOcupadas++;
            return 1;
        }
        // inserção
        while (colunaAtual != NULL)
        {

            // fim
            if (colunaAtual->proxCol == NULL)
            {
                coluna *novaColuna = (coluna *)malloc(sizeof(coluna));
                novaColuna->valor = valor;
                novaColuna->nColuna = colunaInserir;
                novaColuna->proxCol = NULL;
                colunaAtual->proxCol = novaColuna;
                Pposicao->colunasOcupadas++;
                return 1;
            }

            // meio
            if (colunaAtual->nColuna < colunaInserir && colunaAtual->proxCol->nColuna > colunaInserir)
            {
                coluna *novaColuna = (coluna *)malloc(sizeof(coluna));
                novaColuna->valor = valor;
                novaColuna->nColuna = colunaInserir;
                novaColuna->proxCol = colunaAtual->proxCol;
                colunaAtual->proxCol = novaColuna;
                Pposicao->colunasOcupadas++;
                return 1;
            }

            colunaAtual = colunaAtual->proxCol;
        }
    }
}

int retiraDaMatriz(Matriz Mat, int linhaID, int colunaID)
{

    if (Mat == NULL)
    {
        printf("Erro ao remover numero\n");
        return 0;
    }

    matriz *mat = (matriz *)Mat;

    if (linhaID > mat->qtdLinhas || linhaID < 1 || colunaID > mat->qtdColunas || colunaID < 1)
    {
        printf("\nErro ao remover. A matriz possui apenas %d linhas e %d colunas!\n", mat->qtdLinhas, mat->qtdColunas);
        return 0;
    }

    linha *linhaRemover = mat->linhas[linhaID - 1];
    coluna *primeiraColuna = linhaRemover->colunas;

    coluna *colunaAtual = primeiraColuna;
    coluna *colunaAnterior = primeiraColuna;

    while (colunaAtual != NULL)
    {

        if (colunaAtual->nColuna == colunaID)
        {

            if (linhaRemover->colunasOcupadas == 1 || colunaID == 1)
                linhaRemover->colunas = colunaAtual->proxCol;
            else
                colunaAnterior->proxCol = colunaAtual->proxCol;

            linhaRemover->colunasOcupadas--;
            free(colunaAtual);
            return 1;
        }

        colunaAnterior = colunaAtual;
        colunaAtual = colunaAtual->proxCol;
    }

    printf("Coluna vazia\n");
    return 0;
}

void imprimeMatriz(Matriz Mat)
{

    if (Mat == NULL)
    {
        printf("Erro matriz invalida\n");
        return;
    }
    matriz *mat = (matriz *)Mat;

    for (int i = 0; i < mat->qtdLinhas; i++)
    {
        linha *linhaAtual = mat->linhas[i];
        coluna *colunaAtual = linhaAtual->colunas;

        int cont = 1;

        while (cont <= mat->qtdColunas)
        {
            if (colunaAtual != NULL)
            {
                if (colunaAtual->nColuna == cont)
                {
                    printf("%d ", colunaAtual->valor);
                    colunaAtual = colunaAtual->proxCol;
                }
                else
                {
                    printf("0 ");
                }
            }
            else
            {
                printf("0 ");
            }
            cont++;
            if (colunaAtual == NULL && cont == mat->qtdColunas)
            {
                printf("0 ");
                break;
            }
        }
        printf("\n");
    }
}

void freeMatriz(Matriz Mat)
{

    if (Mat == NULL)
        return;
    matriz *mat = (matriz *)Mat;
    for (int i = 0; i < mat->qtdLinhas; i++)
    {
        coluna *colunaAtual = mat->linhas[i]->colunas;
        coluna *prox;

        while (colunaAtual != NULL)
        {
            prox = colunaAtual->proxCol;
            free(colunaAtual);
            colunaAtual = prox;
        }

        free(mat->linhas[i]);
    }
    free(mat->linhas);
    free(mat);
}
