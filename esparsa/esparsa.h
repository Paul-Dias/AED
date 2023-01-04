#include <stdio.h>
#include <stdlib.h>

#define ERROR_ID -1

typedef struct Coluna coluna;

struct Coluna
{
    int valor;
    int nColuna;
    coluna *proxCol;
};

typedef struct
{
    int idLinha;
    int colunasOcupadas;
    coluna *colunas;
} linha;

typedef struct
{
    int qtdLinhas;
    int qtdColunas;
    linha **linhas;
} matriz;

typedef void *Matriz;
Matriz criarMatriz(int qtdLinhas, int qtdColunas);
int insereNaMatriz(Matriz Mat, int valor, int linha, int coluna);
int retiraDaMatriz(Matriz Mat, int linhaID, int colunaID);
void imprimeMatriz(Matriz Mat);
void freeMatriz(Matriz Mat);