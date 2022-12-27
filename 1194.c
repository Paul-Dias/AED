#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

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

short Number;

int sho(char *str, int inicio, int fim, char letra)
{
    short i;
    for (i = inicio; i <= fim; ++i)
        if (str[i] == letra)
            return i;
    return -1;
}

PArv novonoh(char letra)
{
    nohArv *noh = (nohArv *)malloc(sizeof(nohArv));
    noh->letra = letra;
    noh->ArvEsq = noh->ArvDir = NULL;
    return noh;
}

nohArv *PArv(char *infixa, char *prefixa, int Inicio, int inFim)
{

    int infixaNumber;
    if (Inicio > inFim)
        return NULL;

    nohArv *noh = novonoh(prefixa[Number++]);
    if (Inicio == inFim)
        return noh;

    infixaNumber = sho(infixa, Inicio, inFim, noh->letra);
    noh->ArvEsq = PArv(infixa, prefixa, Inicio, infixaNumber - 1);
    noh->ArvDir = PArv(infixa, prefixa, infixaNumber + 1, inFim);

    return noh;
}
// imprimir
void fixa(nohArv *noh)
{
    if (noh == NULL)
        return;
    fixa(noh->ArvEsq);
    fixa(noh->ArvDir);
    printf("%c", noh->letra);
}

int main()
{
    short n_cases;
    short n_no, i;
    char prefixa[TAM];
    char infixa[TAM];
    scanf("%hu", &n_cases);

    while (n_cases--)
    {
        scanf("%hu %s %s%*c", &n_no, prefixa, infixa);
        Number = 0;
        nohArv *raiz = PArv(infixa, prefixa, 0, n_no - 1);
        fixa(raiz);
        printf("\n");
    }
}