#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>


/* Nome: Paulo Henrique    T:N Circular   
*/

typedef struct Carta {
    int valor;
    struct Carta *prox;
}card;
 
typedef struct {
    card *ini;
    card *fim;
    int tam;
}Lista;
 
void start_lc(Lista *l) {
    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;
}

//insert begining
void inserir_no_inicio (Lista *l, int num){
    card *novo = malloc(sizeof(card));

    if(novo){
        novo->valor = num;
        novo->prox = l-> ini;
        l->ini = novo;
        if(l->fim==NULL)
            l->fim = novo;
            l->fim->prox = l->ini;
            l->tam++;
    }
    else
        printf("Erro locate memory");
}
//insert no fim

void inserir_no_fim(Lista *l,int num){
    card *novo = malloc(sizeof(card));

    if(novo){
        novo->valor=num;
        //é o primeiro valor inserido?
        if(l->ini==NULL){
            l->ini=novo;
            l->fim=novo;
            l->fim->proximo=l->ini;
        }
        else{
            l->fim->prox=novo;
            l->fim = novo;
            novo->prox = l->ini;
        }
        l->tam++;
    }
    else
        printf("Erro locate memory");
}
//no "meio"
void inserir_ordenado(Lista *l,int num){
    card *aux, *novo=malloc(sizeof(card));
    if(novo){
        novo->valor=num;
        if(l->ini==NULL){
            inserir_no_inicio(l, num);
        }
        else if(novo->valor < l->ini->valor){   //menor elemento da lista
            inserir_no_inicio(l, num);
        }
        else{
            aux=l->ini;
            while(aux->prox != l->ini && novo->valor > aux->prox->valor)
                aux = aux->prox;
                if(aux->prox == l->ini)
                inserir_no_fim(l, num);
                else{
                    novo-> prox = aux->prox;
                    aux-> prox = novo;
                    l->tam++;
                }
        }
    }
}

//imprimir

void imprimir(Lista l){
    Carta *card = l.ini;
    printf("\n\tLista tam %d: ", l.tam);
    if(card){
        do{
            printf("%d ", card->valor);
            card = card->prox;
        }while(no != l.ini);
        printf("\nInicio: %d\n", card->valor);
    }
    printf("\n\n");
}

int main(){

int user;
Lista l;
start_lc(&l);

 scanf("%d", &user);

    imprimir(&l);

}
    


