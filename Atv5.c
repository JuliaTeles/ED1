#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 100

int pilha[TAMANHO];
int topo1 = -1; // Topo da primeira pilha
int topo2 = TAMANHO; // Topo da segunda pilha

bool pilha1_vazia() {
    return topo1 == -1;
}

bool pilha2_vazia() {
    return topo2 == TAMANHO;
}

bool pilhas_cheias() {
    return topo1 + 1 == topo2;
}

void empilhar(int valor) {
    if (pilhas_cheias()) {
        printf("Erro: Pilhas cheias.\n");
        return;
    }

    if (topo1 + 1 < topo2) {
        pilha[++topo1] = valor; // Empilhar na primeira pilha
    } else {
        pilha[--topo2] = valor; // Empilhar na segunda pilha
    }
}

int desempilhar1() {
    if (pilha1_vazia()) {
        printf("Erro: Pilha 1 vazia.\n");
        return -1;
    }

    return pilha[topo1--]; // Desempilhar da primeira pilha
}

int desempilhar2() {
    if (pilha2_vazia()) {
        printf("Erro: Pilha 2 vazia.\n");
        return -1;
    }

    return pilha[topo2++]; // Desempilhar da segunda pilha
}

int main() {
    // Teste das operações
    empilhar(1);
    empilhar(2);
    empilhar(3);
    empilhar(4);
    empilhar(5);

    printf("Desempilhando pilha 1:\n");
    while (!pilha1_vazia()) {
        printf("%d ", desempilhar1());
    }
    printf("\n");

    printf("Desempilhando pilha 2:\n");
    while (!pilha2_vazia()) {
        printf("%d ", desempilhar2());
    }
    printf("\n");

    return 0;
}
