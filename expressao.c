#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char pilha[MAX];
int topo = -1;

// estrutura da arvore
struct Arv{
  char caracter;
  struct Arv *ArvEsq;
  struct Arv *ArvDir;
};

typedef struct Arv TArv;
typedef TArv *PArv;

PArv inicializar(){
  return NULL;
}

int arvoVazia(PArv arvore){
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

void push(char caracter){
	if(topo >= MAX-1){
		printf("\nPilha cheia");
  }else{
		topo++;
		pilha[topo] = caracter;
	}
}

char pop(){
	char caracter;
	caracter = pilha[topo];
	topo--;
	return(caracter);
}

int operador(char caracter){
	if(caracter == '+' || caracter == '-' || caracter == '/' || caracter == '*' || caracter =='^')
		return 1;
	return 0;
}

int prioridade(char symbol){
	if(symbol == '^')
		return(3);
	else if(symbol == '*' || symbol == '/')
		return(2);
	else if(symbol == '+' || symbol == '-')
		return(1);
  else
		return(0);
}

void infixo_para_posfixo(char infixa[], char posfixa[]){ 
	int i = 0, j = 0;
	char caracter, aux;
	push('(');
	strcat(infixa,")");
	caracter=infixa[i];
	while(caracter != '\0'){
		if(caracter == '(')
			push(caracter);
		else if( isdigit(caracter) || isalpha(caracter)){
			posfixa[j] = caracter;
			j++;
		}
		else if(operador(caracter) == 1){
			aux=pop();
			while(operador(aux) == 1 && prioridade(aux)>= prioridade(caracter))
			{
				posfixa[j] = aux;
				j++;
				aux = pop();
			}
			push(aux);
			push(caracter);
		}
		else if(caracter == ')'){
			aux = pop();
			while(aux != '('){
				posfixa[j] = aux;
				j++;
				aux = pop();
			}
		}
		i++;
		caracter = infixa[i];
	}
	posfixa[j] = '\0';
}

PArv insere_expressao(char carac, PArv dir, PArv esq){
  PArv novoCaracter;
  novoCaracter = (PArv)malloc(sizeof(TArv));
  novoCaracter->caracter = carac;
  novoCaracter->ArvDir = dir;
  novoCaracter->ArvEsq = esq;
  return novoCaracter;
}

int altura(PArv no){
  if (no == NULL)
    return 0;
  else{
    int alturaesq = altura(no->ArvEsq);
    int alturadir = altura(no->ArvDir);
    if (alturaesq > alturadir)
      return (alturaesq + 1);
    else
      return (alturadir + 1);
  }
}

void imprime_nivel(PArv raiz, int nivel){
    if (raiz == NULL)
        return;
    if (nivel == 1)
        printf("%c", raiz->caracter);
    else if (nivel > 1) {
        imprime_nivel(raiz->ArvEsq, nivel - 1);
        imprime_nivel(raiz->ArvDir, nivel - 1);
    }
}

void imprime_expressao(PArv raiz){
    int h = altura(raiz);
    for (int i = 1; i <= h; i++){
      if(i > 1)
        printf("\n");
      printf("Nivel %d: ", i-1);
      imprime_nivel(raiz, i);
    }
}

void expressao(char infixa[]){
  PArv arvore, dir, esq;
  PArv ponteiros[MAX];
  arvore = NULL;
  int topoarv = -1;
  char posfixa[MAX];
  //puts(posfixa);
  infixo_para_posfixo(infixa, posfixa);
  for(int i = 0; i < strlen(posfixa); i++){
    if(!operador(posfixa[i])){
      topoarv++;
      ponteiros[topoarv] = insere_expressao(posfixa[i], NULL, NULL);
    }else{
      dir = ponteiros[topoarv];
      topoarv--;
      esq = ponteiros[topoarv];
      topoarv--;
      topoarv++;
      ponteiros[topoarv] = insere_expressao(posfixa[i], dir, esq);
    }
  }
  arvore = ponteiros[topoarv];
  imprime_expressao(arvore);
  freeArv(arvore);
}

int main(){
  char infixa[MAX];
  int size = 1;
  while(size > 0){
    fgets(infixa, 101, stdin);
    size = strlen(infixa);
    printf("\n");
    expressao(infixa);
    printf("\n");
  }
  return 0;
}