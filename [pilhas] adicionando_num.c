#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

void empilhar(Pilha *p, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

void desempilhar(Pilha *p) {
    if (p->topo == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
}

void imprimir(Pilha *p) {
    No *temp = p->topo;
    while (temp != NULL) {
        printf("%d\n", temp->valor);
        temp = temp->proximo;
    }
}

int main() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;

    int opcao, valor;
    do {
        printf("Escolha uma opção:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(p, valor);
                break;
            case 2:
                desempilhar(p);
                break;
            case 3:
                imprimir(p);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    free(p);
    return 0;
}