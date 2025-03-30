#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Test {
    int num;
    struct Node *proximo;
} Test;

Test* inicio(Test* head, int num){
    Test* novo = (Test*)malloc(sizeof(Test)); // alocação de memoria
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return head;
    }
    novo->num = num; // atribui o valor a nova estrutura
    novo->proximo = head; // aponta para o proximo elemento

    return novo; // retorna o novo elemento

    void printlista (Teste* head) {
        Test* atual = head;
        while (atual != NULL){
            printf("%d ", atual->num); // imprime o valor do elemento atual
            atual = atual->proximo; // avança para o proximo elemento
        }
    }
    
}