#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int valor;
    struct no *proximo;
    int topo;
} Pi;

typedef struct pilha {
    Pi *topo;
} Pilha;

void iniciar(Pi *p){
    p->topo = -1; 
}

int pilhavazia (Pi *p){
    if (p->topo == -1) {
        return 1; // Pilha vazia
    } else {
        return 0; // Pilha não vazia
    }
}

int pilhacheia(Pi *p){
    if (p->topo == MAX - 1) {
        return 1; // Pilha cheia
    } else {
        return 0; // Pilha não cheia
    }
}

void inserir (Pi *p, int valor){
    Pi *novo = malloc(sizeof(Pi));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    if (pilhacheia(p)) {
        printf("Pilha cheia\n");
    } else {
        p->topo++;
        p->valor = valor; // Adiciona o valor no topo da pilha
        printf("Valor %d inserido com sucesso!\n", valor);
    }
}

int remover(Pi *p){
    int aux;
    if (pilhavazia(p)  == 1) {
        printf("Pilha vazia\n");
    } else {
        aux = p->valor; 
        p->topo--;
        printf("Valor removido: %d\n", aux);
        return aux; 
    }
    return -1; 
}

int main(){
    Pi *p = malloc(sizeof(Pi));
    iniciar(p);
    inserir(p, 10);
    inserir(p, 20);

    int aux;
    aux = remover(p);
    printf("Valor removido: %d\n", aux);
}
