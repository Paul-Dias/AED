#include "FilaD.h"
#include <time.h>

void imprimeMenu();
void leDadosItem(TipoItem *);

int main()
{
    TipoFila fila;
    TipoItem item;
    int op = 0, i;

    inicializaFila(&fila);

    while (op != 4)
    {
        imprimeMenu();
        printf("\nOpcao: ");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            leDadosItem(&item);
            if (insereNaFila(&fila, item))
                printf("\n\nItem inserido com sucesso!\n");
            else
                printf("\nErro! Não foi possível inserir o item!\n");
            break;
        case 2:
            if (retiraDaFila(&fila, &item))
            {
                printf("\nItem retirado com sucesso!");
                printf("\nItem: %i %s\n", item.senha, item.nome);
            }
            else
            {
                printf("\nErro! Não foi possível retirar da fila!\n");
            }
            break;
        case 3:
            if (!filaVazia(&fila))
            {

                imprimeFila(&fila, item);
            }
            else
            {
                printf("\nFila Vazia!\n");
            }
            break;
        case 4:
            destroiFila(&fila);
            printf("\nAté logo!\n");
            break;
        default:
            break;
        }
    }

    return 0;
}

void imprimeMenu()
{
    printf("\nMenu");
    printf("\n1 - Insere na fila");
    printf("\n2 - Retira da fila");
    printf("\n3 - Imprime fila");
    printf("\n4 - Sair");
}

void leDadosItem(TipoItem *item)
{
    printf("\nDados do Item");
    printf("\nSua senha eh Senha: ");
    srand(time(NULL));
    printf("%d", item->senha = rand() % 101);
    getchar();
    printf("\nNome: ");
    fgets(item->nome, sizeof(item->nome), stdin);
    item->nome[strlen(item->nome) - 1] = '\0';
    printf("Prioridade na fila:");
    printf("%d", item->prioridade = rand() % 11);
}