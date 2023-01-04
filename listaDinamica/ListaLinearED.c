#include "ListaLinearED.h"

int listaVaziaLLED(ListaLinearED *lista)
{
    return lista->ultimo == 0;
}

void inicializaListaLLED(ListaLinearED *lista)
{
    lista->inicioLista = NULL;
    lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED *lista)
{
    TipoNoh *ptrAux1, *ptrAux2;
    if (!listaVaziaLLED(lista))
    {
        ptrAux1 = lista->inicioLista;
        ptrAux2 = ptrAux1->prox;
        while (ptrAux1->prox != NULL)
        {
            free(ptrAux1);
            ptrAux1 = ptrAux2;
            ptrAux2 = ptrAux1->prox;
        }
        free(ptrAux1);
    }
    lista->inicioLista = NULL;
    lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item)
{
    int i;
    printf("\nRa: %i", item.RA);
    printf("\nNome: %s", item.nome);
    for (i = 0; i < 3; i++)
    {
        printf("\nNota %i: %.1f", i + 1, item.notas[i]);
    }
    printf("\nFrequencia: %i\n", item.freq);
}

void imprimeListaLLED(ListaLinearED *lista)
{
    TipoNoh *ptrAux;
    if (!listaVaziaLLED(lista))
    {
        ptrAux = lista->inicioLista;
        while (ptrAux != NULL)
        {
            imprimeItemLLED(ptrAux->item);
            ptrAux = ptrAux->prox;
        }
    }
}

int insereNoFinalLLED(ListaLinearED *lista, TipoItem item)
{
    TipoNoh *novoNoh, *ptrAux;
    novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
    if (novoNoh != NULL)
    {
        ptrAux = lista->inicioLista;
        if (!listaVaziaLLED(lista))
        {
            while (ptrAux->prox != NULL)
                ptrAux = ptrAux->prox;
            ptrAux->prox = novoNoh;
        }
        else
        {
            lista->inicioLista = novoNoh;
        }
        novoNoh->item = item;
        novoNoh->prox = NULL;
        lista->ultimo++;
        return 1;
    }
    return 0;
}

int insereNoInicioLLED(ListaLinearED *lista, TipoItem item)
{
    TipoNoh *novoNoh;
    novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));
    if (novoNoh != NULL)
    {
        novoNoh->item = item;
        novoNoh->prox = lista->inicioLista;
        lista->inicioLista = novoNoh;
        lista->ultimo++;
        return 1;
    }
    return 0;
}

int removeDoFinalLLED(ListaLinearED *lista, TipoItem *item)
{
    TipoNoh *ptrAux1, *ptrAux2;
    if (!listaVaziaLLED(lista))
    {
        ptrAux1 = lista->inicioLista;
        ptrAux2 = ptrAux1->prox;
        if (ptrAux2 == NULL)
        {
            lista->inicioLista = NULL;
            *item = ptrAux1->item;
            free(ptrAux1);
        }
        else
        {
            while (ptrAux2->prox != NULL)
            {
                ptrAux1 = ptrAux2;
                ptrAux2 = ptrAux2->prox;
            }
            ptrAux1->prox = NULL;
            *item = ptrAux2->item;
            free(ptrAux2);
        }
        lista->ultimo--;
        return 1;
    }
    return 0;
}

int removeDoInicioLLED(ListaLinearED *lista, TipoItem *item)
{
    TipoNoh *ptrAux;
    if (!listaVaziaLLED(lista))
    {
        ptrAux = lista->inicioLista;
        *item = ptrAux->item;
        lista->inicioLista = ptrAux->prox;
        free(ptrAux);
        lista->ultimo--;
        return 1;
    }
    return 0;
}

int buscaItemNaListaLLED(ListaLinearED *lista, int info, TipoItem *item, int *pos)
{
    TipoNoh *ptrAux;
    int cont = 1;
    if (!listaVaziaLLED(lista))
    {
        ptrAux = lista->inicioLista;
        while (ptrAux != NULL)
        {
            if (verificaIgualdade(ptrAux->item, info))
            {
                *item = ptrAux->item;
                *pos = cont;
                return 1;
            }
            cont++;
            ptrAux = ptrAux->prox;
        }
    }
    return 0;
}

int verificaIgualdade(TipoItem item, int info)
{
    if (item.RA == info)
        return 1;
    return 0;
}

int InsereNaPosicao(ListaLinearED *lista, TipoItem item, int posicao)
{
    TipoNoh *novoNoh, *ptrAux;
    int cont = 1;
    if (posicao > lista->ultimo + 1)
    {
        return 0;
    }
    else
    {
        if (posicao == 1)
        {
            return insereNoInicioLLED(lista, item);
        }
    }

    ptrAux = lista->inicioLista;
    novoNoh = (TipoNoh *)malloc(sizeof(TipoNoh));

    novoNoh->item = item;

    if (novoNoh != NULL)
    {
        while (cont != posicao - 1)
        {
            ptrAux = ptrAux->prox;
            cont++;
        }

        novoNoh->prox = ptrAux->prox; //
        ptrAux->prox = novoNoh;
        free(ptrAux);
        return 1;
        lista->ultimo++;
    }
    return 0;
}

int RetiraDaPosicao(ListaLinearED *lista, TipoItem *item, int posicao)
{
    TipoNoh *ptrAux, *ptrAux2;
    int cont = 0;
    ptrAux = lista->inicioLista;

    if (posicao > lista->ultimo + 1)
    {
        return 0;
    }
    else if (posicao == lista->ultimo)
    {
        removeDoFinalLLED(lista, item);
    }
    else
    {
        if (!listaVaziaLLED(lista))
        {
            while (ptrAux->prox != NULL)
            {
                cont++;
                ptrAux = ptrAux->prox;
                if (cont == posicao - 1)
                {
                    ptrAux2 = ptrAux->prox;
                    ptrAux->prox = ptrAux2->prox;
                    free(ptrAux2);
                    lista->ultimo--;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int RetiraEspecifico(ListaLinearED *lista, int especifico, TipoItem *item, int pos)
{
    TipoNoh *ptrAux, *remove = NULL;
    if (!listaVaziaLLED(lista))
    {
        ptrAux = lista->inicioLista;
        while (ptrAux != NULL)
        {
            if (verificaIgualdade(ptrAux->item, especifico))
            {
                RetiraDaPosicao(lista, item, pos);
            }

            ptrAux = ptrAux->prox;
        }

        return 1;
    }
}
