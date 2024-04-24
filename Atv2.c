#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct registro {
  int info;
};

struct no {
  struct registro reg;
  struct no *prox;
};

struct lista {
  struct no *inicio;
};

void inicializar(struct lista *L) { L->inicio = NULL; }

struct no *buscar(struct lista *L, int ch, struct no **ant) {
  *ant = NULL;
  struct no *atual = L->inicio;
  while ((atual != NULL) && (atual->reg.info < ch)) {
    *ant = atual;
    atual = atual->prox;
  }
  if ((atual != NULL) && (atual->reg.info == ch)) {
    return atual;
  }
  return NULL;
}

bool inserir(struct lista *L, struct registro reg) {
  int ch = reg.info;
  struct no *ant, *i;
  i = buscar(L, ch, &ant);
  if (i != NULL)
    return false;
  i = (struct no *)malloc(sizeof(struct no));
  i->reg = reg;
  if (ant == NULL) {
    i->prox = L->inicio;
    L->inicio = i;
  } else {
    i->prox = ant->prox;
    ant->prox = i;
  }
  return true;
}

void imprimir(struct lista *L) {
  struct no *end = L->inicio;
  while (end != NULL) {
    printf("%d |", end->reg.info);
    end = end->prox;
  }
  printf("\n");
}

void excluir(struct lista *L, int ch) {
  struct no *ant, *i;
  i = buscar(L, ch, &ant);
  if (i == NULL)
    printf("Deu boi \n");
  if (ant == NULL)
    L->inicio = i->prox;
  else
    ant->prox = i->prox;
  free(i);
  printf("Deu bom \n");
}

void funcao(struct lista *L, int Vi, int Vf) {
  if (Vi > Vf) {
    printf("Numeros invalidos \n");
    return;
  }

  for (int i = Vi; i <= Vf; i++) {
    excluir(L, i);
  }
}

int main(void) {

  struct lista listi;
  inicializar(&listi);

  for (int i = 0; i < 50; i++) {
    struct registro new_reg;
    new_reg.info = i;
    inserir(&listi, new_reg);
  }
  imprimir(&listi);
  funcao(&listi, 5, 10);
  imprimir(&listi);

  return 0;
}
