#include <stdbool.h>
#include <stdio.h>

struct no {
  int info;
  int prox;
};

struct lista {
  struct no A[50];
  int inicio;
  int dispo;
};

void inicializar(struct lista *L) {
  for (int i = 0; i < 50 - 1; i++) {
    L->A[i].prox = i + 1;
  }
  L->A[50 - 1].prox = -1;
  L->inicio = -1;
  L->dispo = 0;
}

int obterNo(struct lista *L) {
  int resultado = L->dispo;
  if (L->dispo != -1) {
    L->dispo = L->A[L->dispo].prox;
  }
  return resultado;
}

bool inserir(struct lista *L, struct no *reg) {
  if (L->dispo == -1)
    return false;
  int ant = -1;
  int i = L->inicio;
  int ch = reg->info;
  while ((i != -1) && (L->A[i].info < ch)) {
    ant = i;
    i = L->A[i].prox;
  }
  if (i != -1 && L->A[i].info == ch) {
    return false;
  }
  i = obterNo(L);
  L->A[i].info = reg->info;
  if (ant == -1) {
    L->A[i].prox = L->inicio;
    L->inicio = i;
  } else {
    L->A[i].prox = L->A[ant].prox;
    L->A[ant].prox = i;
  }
  return true;
}

void imprimir(struct lista *L) {
  for (int i = 0; i < 50; i++) {
    if (L->A[i].prox != -1) {
      printf("%d | ", L->A[i].info);
    }
  }
  printf("\n");
}

void devolverNo(struct lista *L, int j) {
  L->A[j].prox = L->dispo;
  L->dispo = j;
}

void excluir(struct lista *L, int ch) {
  int ant = -1;
  int i = L->inicio;
  while ((i != -1) && (L->A[i].info < ch)) {
    ant = i;
    i = L->A[i].prox;
  }
  if ((i == -1) || (L->A[i].info != ch)) {
    printf("Elemento não encontrado para exclusão\n");
    return;
  }
  if (ant == -1) {
    L->inicio = L->A[i].prox;
  } else {
    L->A[ant].prox = L->A[i].prox;
  }
  devolverNo(L, i);
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
    struct no novo;
    novo.info = i;
    inserir(&listi, &novo);
  }

  imprimir(&listi);
  funcao(&listi, 5, 10);
  imprimir(&listi);

  return 0;
}
