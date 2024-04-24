#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct registro {
  char chave;
};

struct elemento {
  struct registro reg;
  struct elemento *prox;
};
typedef struct elemento *pont;

struct pilha {
  pont topo;
};

void inicializar(struct pilha *p) { p->topo = NULL; }

bool inserir(struct pilha *p, struct registro reg) {
  pont novo = (pont)malloc(sizeof(struct elemento));
  novo->reg = reg;
  novo->prox = p->topo;
  p->topo = novo;
  return true;
}

void imprimir(struct pilha *p) {
  pont atual = p->topo;
  while (atual != NULL) {
    printf("%c ", atual->reg.chave);
    atual = atual->prox;
  }
  printf("\n");
}

void pertencer(struct pilha *p) {
  int aux = 0;
  pont atual = p->topo;
  char antes[50];
  while (atual != NULL && atual->reg.chave != 'C') {
    antes[aux] = atual->reg.chave;
    aux++;
    atual = atual->prox;
  }

  if (atual == NULL){
    printf("Não tem C");
  }
  else{
    atual = atual->prox;
    for(int i = 0; i <aux; i++){
      if(antes[i] != atual->reg.chave){
        printf("não é otto - %c", antes[i]);
        exit(0);
      }
      atual = atual->prox;
    }
    printf(" é otto");
  }
  
}

int main(void) {
  struct pilha pilhinha;
  inicializar(&pilhinha);
  struct registro reg1 = {'a'};
  struct registro reg4 = {'b'};
  struct registro reg2 = {'C'};
  struct registro reg3 = {'a'};
  inserir(&pilhinha, reg1);
  inserir(&pilhinha, reg4);
  inserir(&pilhinha, reg2);
  inserir(&pilhinha, reg3);
  imprimir(&pilhinha);
  pertencer(&pilhinha);
  return 0;
}
