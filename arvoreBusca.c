#include <stdio.h>
#include <stdlib.h>

// estrutura da arvore
struct Arv
{
    int dado;
    struct Arv *ArvEsq;
    struct Arv *ArvDir;
};

typedef struct Arv TArv;

typedef TArv *PArv;

PArv inicializar()
{
    return NULL;
}

int arvoVazia(PArv arvore)
{
    return arvore == NULL;
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

        printf(" %i", arvore->dado);
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
        printf(" %i", arvore->dado);
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
        printf(" %i", arvore->dado);
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
    int nums, item;
    PArv arvore;
    char n_casos[100];
    system("chcp 65001");
    arvore = inicializar();
    printf("Digite a quantidade de números a serem lidos:");
    scanf("%i", &nums);

    for (int j = 0; j < nums; j++)
    {
        scanf("%i", &item);
        arvore = inserir(arvore, item);
        n_casos[j] = item;
    }

    printf("Arvore: \n");
    for (int i = 0; i < nums; i++)
    {
        printf("%i ", n_casos[i]);
    }

    printf("\nPre.:");
    imprimePreOrdem(arvore);
    printf("\nIn..:");
    imprimeEmOrdem(arvore);
    printf("\nPost:");
    imprimePosOrdem(arvore);
    freeArv(arvore);
    printf("\n");
    printf("\n");

    return 0;
}
