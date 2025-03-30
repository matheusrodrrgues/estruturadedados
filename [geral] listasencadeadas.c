#include <stdio.h>
#include <stdlib.h>

typedef struct Test {
    int num;
    struct Test* proximo;
} Test;

Test* inicio(Test* head, int num) {
    Test* novo = (Test*)malloc(sizeof(Test));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return head;
    }
    novo->num = num;
    novo->proximo = head;
    return novo;
}

void printlista(Test* head) {
    Test* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->num);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    Test* lista = NULL;

    lista = inicio(lista, 10);
    lista = inicio(lista, 20);
    lista = inicio(lista, 30);

    printf("Elementos da lista:\n");
    printlista(lista);

    return 0;
}