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

        printf("%i ", arvore->dado);
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
        printf("%i ", arvore->dado);
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
        printf("%i ", arvore->dado);
    }
}

// buscar elemento
PArv busca(PArv arvore, int valor)
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

// remover elemento

PArv remover(PArv raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL; // n tem nada (1)
    }
    else
    { // procura o nó a remover
        if (raiz->dado == chave)
        {
            // remove nós folhas (nós sem filhos)
            if (raiz->ArvEsq == NULL && raiz->ArvDir == NULL) // okay  (2)
            {
                free(raiz);
                return NULL;
            }
            else
            {
                // apenas 1 filho
                if (raiz->ArvEsq == NULL || raiz->ArvDir == NULL) //(3)
                {
                    PArv aux;
                    if (raiz->ArvEsq != NULL)
                        aux = raiz->ArvEsq;
                    else
                        aux = raiz->ArvDir;
                    free(raiz);
                    return aux;
                }
                else // dois filhos (nesse else aqui) (4)
                {
                    PArv aux1, aux2;
                    aux1 = raiz;
                    aux2 = raiz->ArvEsq;
                    while (aux2->ArvDir != NULL)
                    {
                        aux1 = aux2;
                        aux2 = aux2->ArvDir;
                    }
                    raiz->dado = aux2->dado;

                    if (aux1 == raiz)
                    {
                        aux1->ArvEsq = aux2->ArvEsq;
                    }
                    else
                    {
                        aux1->ArvDir = aux2->ArvEsq;
                    }

                    free(aux2);
                }
                return raiz;
            }
        }
        else // vai andando
        {
            if (chave < raiz->dado)
            {
                raiz->ArvEsq = remover(raiz->ArvEsq, chave);
            }
            else
            {
                raiz->ArvDir = remover(raiz->ArvDir, chave);
            }
            return raiz;
        }
    }
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
    int item;
    char opcao[10];
    PArv arvore;

    arvore = inicializar();
    while (scanf("%s", opcao) != EOF)
    {

        if (strcmp(opcao, "I") == 0)
        {
            scanf("%i", &item);
            arvore = inserir(arvore, item);
        }
        else if (strcmp(opcao, "P") == 0)
        {
            scanf("%i", &item);

            if (busca(arvore, item))
            {
                printf("%d existe\n", item);
            }
            else
            {
                printf("%d nao existe\n", item);
            }
        }
        else if (strcmp(opcao, "R") == 0)
        {
            scanf("%i", &item);

            arvore = remover(arvore, item);
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
