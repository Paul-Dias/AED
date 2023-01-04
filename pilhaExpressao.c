#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  float Valor;
}TipoItem;

typedef  struct Noh{
  TipoItem item;
  struct Noh *prox;
}TipoNoh;

typedef TipoNoh *PNoh;

typedef struct{
  PNoh topo;
}PilhaDinamica;

void inicializaPilha(PilhaDinamica *pilha){
  pilha->topo = NULL;
}

int pilhaVazia(PilhaDinamica pilha){
  return pilha.topo == NULL;
}

int imprimePilha(PilhaDinamica Pilha){
  PNoh ptrAux;
  ptrAux = Pilha.topo;
  while(ptrAux!=NULL){
    printf("%.2f",ptrAux->item.Valor);
    ptrAux = ptrAux->prox;
  }
}

void empilha(PilhaDinamica *Pilha, float Valor){
  PNoh novo;
  
  novo = (PNoh) malloc(sizeof(TipoNoh));
  if(novo != NULL){
    novo->item.Valor = Valor; 
    if(pilhaVazia(*Pilha)){
      novo->prox = NULL;
      Pilha->topo = novo;
    }else{
      novo->prox = Pilha->topo;
      Pilha->topo = novo;
    }
  }
}

float desempilha(PilhaDinamica *Pilha){
  PNoh Aux = Pilha->topo;
  float Valor = Aux->item.Valor;
  Pilha->topo = Pilha->topo->prox;
  free(Aux);
  return Valor;
}

float resolveProblema(char *Expressao, PilhaDinamica *Pilha){
  int cont, Valor, n1, n2;
  for(cont = 0; cont < strlen(Expressao); cont++){
    switch (Expressao[cont]){
      case '+': 
        n1 = desempilha(Pilha);
        n2 = desempilha(Pilha);
        empilha(Pilha, n1+n2);
        break;
      case '-':
        n1 = desempilha(Pilha);
        n2 = desempilha(Pilha);
        empilha(Pilha, n1-n2);
        break;
      case'*':
        n1 = desempilha(Pilha);
        n2 = desempilha(Pilha);
        empilha(Pilha, n1*n2);
        break;
      case'/':
        n1 = desempilha(Pilha);
        n2 = desempilha(Pilha);
        empilha(Pilha, n1/n2);
        break;
      default:
        Valor = (int)Expressao[cont]-'0';
        empilha(Pilha, (float)Valor);
    }
  }
  return 0;
}

void entrada(char *Expressao){
  char copia[100];
  printf("Escreva a expressão\n");
  
  fgets(Expressao, sizeof(copia), stdin);
  Expressao[strlen(Expressao) - 1] = '\0';
}

int main(void) {
  PilhaDinamica Pilha;
  TipoItem item;
  float Resultado;
  char Expressao[100];

  entrada(&Expressao);
  inicializaPilha(&Pilha);
  Resultado = resolveProblema(Expressao, &Pilha);
  imprimePilha(Pilha);
  
  return 0;
}
