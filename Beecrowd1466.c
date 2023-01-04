#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
// estrutura da arvore

struct Arv
{
    struct Arv *ArvEsq;
    int num;
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
// inserir

PArv inserirArv(PArv arvore, int num)
{
    if (arvore == NULL)
        return NULL;
    else if (num == arvore->num)
    {
        return arvore;
    }
    else if (num < arvore->num)
    {
        if (arvore->ArvEsq == NULL)
            return arvore;
        else
            return inserirArv(arvore->ArvEsq, num);
    }
    else
    {
        if (arvore->ArvDir == NULL)
            return arvore;
        else
            return inserirArv(arvore->ArvDir, num);
    }
}

int main()
{
    PArv raiz, pai, novoItem, linhas[TAM], arvore;
    int n_Nums, n_casos, qntN, noh;
    int cont, contA = 1, contB = 1;

    scanf("%d", &n_casos);

    for (qntN = 1; qntN <= n_casos; qntN++)
    {
        for (cont = 0; cont < TAM; cont++)
            linhas[cont] = NULL;

        raiz = NULL;

        scanf("%d", &n_Nums);
        for (cont = 0; cont < n_Nums; cont++)
        {
            scanf("%d", &noh);

            novoItem = (PArv)malloc(sizeof(TArv));
            novoItem->num = noh;
            novoItem->ArvEsq = novoItem->ArvDir = NULL;

            pai = inserirArv(raiz, noh);
            if (pai == NULL)
                raiz = novoItem;
            else if (pai->num != noh)
            {
                if (noh < pai->num)
                    pai->ArvEsq = novoItem;

                else
                    pai->ArvDir = novoItem;
            }
        }

        printf("Case %d:\n", qntN);

        novoItem = raiz;
        contA = 1, contB = 1;
        linhas[0] = novoItem;
        while (novoItem != NULL)
        {
            printf("%d", novoItem->num);

            if (novoItem->ArvEsq != NULL)
            {
                linhas[contA] = novoItem->ArvEsq;
                contA++;
            }

            if (novoItem->ArvDir != NULL)
            {
                linhas[contA] = novoItem->ArvDir;
                contA++;
            }

            if (linhas[contB] != NULL)
                printf(" ");

            novoItem = linhas[contB];
            contB++;
        }
        freeArv(arvore);
        printf("\n\n");
    }

    return 0;
}
