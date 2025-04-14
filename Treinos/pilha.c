#include<stdio.h>
#include<stdlib.h>

#define TAMANHO_PILHA 20

typedef struct{
    int vetor[TAMANHO_PILHA];
    int topo;
} Pilha;

void empilha(int valor, Pilha *pilha){
    if (pilha->topo == TAMANHO_PILHA) {
        pilha->vetor[pilha->topo] = valor; // Adiciona o valor no topo da pilha
        pilha->topo++; // Atualiza o topo da pilha
    }
    else {
        printf("Pilha cheia\n");
    }
}
void desempilha(Pilha *pilha){
    if (pilha->topo == 0) {
        printf("Pilha vazia\n");
    } else {
        pilha->topo--; // Remove o valor do topo da pilha
        printf("Valor desempilhado: %d\n", pilha->vetor[pilha->topo]);
    }
}

int isCheia(Pilha *pilha){
    if (pilha->topo == TAMANHO_PILHA) {
        printf("Pilha cheia\n");
        return 1;
    } else {
        printf("Pilha não cheia\n");
    }
}

int isVazia(Pilha *pilha){
    if (pilha->topo == 0) {
        printf("Pilha vazia\n");
        return 1;
    } else {
        printf("Pilha não vazia\n");
    }
}

void imprimer(Pilha *pilha){
    int i;
    if (pilha->topo == 0) {
        printf("Pilha vazia\n");
    } else {
        for (i = pilha->topo - 1; i >= 0; i--) {
            printf("%d ", pilha->vetor[i]);
        }
        printf("\n");
    }
}

int main(){
    Pilha p;
    p.topo = 0;

    // empilhando
    empilha(5, &p);
    empilha(10, &p);
    empilha(15, &p);
    empilha(20, &p);
    empilha(25, &p);

    printf("Topo da pilha: %d\n", p.topo);

    return 0;
}