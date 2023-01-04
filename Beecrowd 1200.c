#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura da arvore
struct Arv
{
    int dado;
    struct Arv *ArvEsq;
    struct Arv *ArvDir;
};

typedef struct Arv TArv;

typedef TArv *PArv;

int arvoVazia(PArv arvore)
{
    return arvore == NULL;
}

PArv inicializar()
{
    return NULL;
}

// inserir

PArv inserir(PArv ArvBN, int numero)
{
    PArv novoItem;

    if (ArvBN == NULL)
    {
        novoItem = (PArv)malloc(sizeof(TArv));
        novoItem->dado = numero;
        novoItem->ArvDir = NULL;
        novoItem->ArvEsq = NULL;

        return novoItem;
    }
    if (numero < ArvBN->dado)
    {

        ArvBN->ArvEsq = inserir(ArvBN->ArvEsq, numero);
    }
    else if (numero > ArvBN->dado)
    {
        ArvBN->ArvDir = inserir(ArvBN->ArvDir, numero);
    }

    return ArvBN;
}

// pre--------------------------------
void imprimePreOrdem(PArv arvore)
{
    if (!arvoVazia(arvore))
    {

        printf("%c ", arvore->dado);
        imprimePreOrdem(arvore->ArvEsq);
        imprimePreOrdem(arvore->ArvDir);
    }
}

// em ordem------------------------------

void imprimeEmOrdem(PArv arvore)
{
    if (!arvoVazia(arvore))
    {
        imprimeEmOrdem(arvore->ArvEsq);
        printf("%c ", arvore->dado);
        imprimeEmOrdem(arvore->ArvDir);
    }
}

// pos ordem ----------------------

void imprimePosOrdem(PArv arvore)
{
    if (!arvoVazia(arvore))
    {
        imprimePosOrdem(arvore->ArvEsq);
        imprimePosOrdem(arvore->ArvDir);
        printf("%c ", arvore->dado);
    }
}

PArv busca(PArv arvore, char valor)
{
    if (arvore != NULL)
    {
        if (arvore->dado == valor)
        {
            return arvore;
        }
        else
        {
            if (valor > arvore->dado)
            {
                return busca(arvore->ArvDir, valor);
            }
            else
                return busca(arvore->ArvEsq, valor);
        }
    }
    return NULL;
}

PArv freeArv(PArv arvore)
{
    if (!arvoVazia(arvore))
    {
        arvore->ArvEsq = freeArv(arvore->ArvEsq);
        arvore->ArvDir = freeArv(arvore->ArvDir);
        free(arvore);
    }
    return NULL;
}

int main()
{
    char item;
    char opcao[10];
    PArv arvore, buscar;

    arvore = inicializar();
    while ((scanf("%s", opcao) != EOF))
    {

        if (strcmp("I", opcao) == 0)
        {
            scanf(" %c", &item);
            arvore = inserir(arvore, item);
        }
        else if ((strcmp("P", opcao) == 0))
        {
            scanf(" %c", &item);
            buscar = busca(arvore, item);
            if (buscar)
            {
                printf("%c existe\n", item);
            }
            else
            {
                printf("%c nao existe\n", item);
            }
        }
        else
        {
            if (strcmp(opcao, "INFIXA") == 0)
            {
                imprimeEmOrdem(arvore);
                printf("\n");
            }
            else if (strcmp(opcao, "PREFIXA") == 0)
            {
                imprimePreOrdem(arvore);
                printf("\n");
            }
            else if (strcmp(opcao, "POSFIXA") == 0)
            {
                imprimePosOrdem(arvore);
                printf("\n");
            }
        }
    }
    freeArv(arvore);
    return 0;
}
