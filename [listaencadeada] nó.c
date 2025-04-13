#include<stdio.h>
#include<stdlib.h>

// lista encadeadas

typedef struct no{
    int valor;
    struct no *proximo; // ponteiro para o próximo nó
}No;

void inserirnoproximo (No **lista, int num){ // função para inserir um nó na lista encadeada
    No *novo = (No*)malloc(sizeof(No)); // aloca memória para o novo nó
    if (novo){ // verifica se a alocação foi bem-sucedida
        novo->valor = num; // atribui o valor ao novo nó
        novo->proximo = *lista; // aponta o próximo nó para o nó atual
        *lista = novo; // atualiza o ponteiro da lista para o novo nó
        printf("Valor %d inserido na lista\n", num);
    }
    else
        printf("Erro ao alocar memoria\n"); // imprime mensagem de erro se a alocação falhar
}

void inserirnofim (No **lista, int num){
    No *aux, *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = num; // atribui o valor ao novo nó
        novo->proximo = NULL; // o próximo nó é nulo, pois é o último nó da lista
        
        if (*lista == NULL) { // se a lista estiver vazia, o novo nó se torna o primeiro nó
            *lista = novo;
        } else {
           aux = *lista; // ponteiro auxiliar para percorrer a lista
            while (aux->proximo != NULL) { // percorre a lista até o último nó
                aux = aux->proximo;
            }
            aux->proximo = novo; // adiciona o novo nó ao final da lista
            printf("Valor %d inserido no final da lista\n", num);
        }
    }   
    else
        printf("Erro ao alocar memoria\n"); // imprime mensagem de erro se a alocação falhar
}
void inserirnomeio (No **lista, int num, int ant){
    No *aux, *novo = (No*)malloc(sizeof(No)); // aloca memória para o novo nó

    if (novo){
        novo->valor = num; // atribui o valor ao novo nó
        if (*lista == NULL){
            novo->proximo = NULL; // se a lista estiver vazia, o próximo nó é nulo
            *lista = novo; // o novo nó se torna o primeiro nó da lista
        }
        else {
            aux = *lista; // ponteiro auxiliar para percorrer a lista
            while (aux->valor != ant && aux->proximo != NULL) { // percorre a lista até encontrar o nó anterior
                aux = aux->proximo;
            novo->proximo = aux->proximo; // o próximo nó do novo nó é o próximo nó do nó atual
            aux->proximo = novo; // o próximo nó do nó atual é o novo nó
            }
        }
    }
    else {
        printf("Erro ao alocar memoria\n"); // imprime mensagem de erro se a alocação falhar

    }
}

void imprimir(No *no){
    printf("Lista: ");
    while (no != NULL) { // percorre a lista até o final
        printf("%d ", no->valor); // imprime o valor do nó atual
        no = no->proximo; // avança para o próximo nó
    }
    printf("\n"); // imprime nova linha após imprimir todos os valores da lista

}

int main(){
    int opcao;
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir no meio\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao); // lê a opção do usuário
        switch (opcao) { // verifica a opção escolhida
            case 1: {
                int num;
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &num); // lê o valor a ser inserido
                inserirnoproximo(&lista, num); // chama a função para inserir no início
                break;
            }
            case 2: {
                int num;
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &num); // lê o valor a ser inserido
                inserirnofim(&lista, num); // chama a função para inserir no final
                break;
            }
            case 3: {
                int num, ant;
                printf("Digite o valor a ser inserido e o valor do nó anterior: ");
                scanf("%d %d", &num, &ant); // lê o valor a ser inserido e o nó anterior
                inserirnomeio(&lista, num, ant); // chama a função para inserir no meio
                break;
            }
            case 4:
                imprimir(lista); // chama a função para imprimir a lista
                break;
            case 5:
                printf("Saindo...\n"); // imprime mensagem de saída
                break;
        default:
            printf("Opcao invalida! Tente novamente.\n"); // imprime mensagem de erro se a opção for inválida
            break;
        
    return 0;
}