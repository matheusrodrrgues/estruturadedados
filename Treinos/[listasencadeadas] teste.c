// Crie um programa em C que implemente uma lista encadeada simples de números inteiros. O programa deve:

#include <Stdio.h>
#include <stdlib.h>

typedef struct simples {
    int valor;
    struct simples *proximo;
} Num;

void adicionar (Num **inicio, int valor) { // Adiciona um novo elemento à lista encadeada
    Num *novo= (Num*)malloc(sizeof(Num)); // Aloca memória para um novo nó
    if (novo == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memoria\n"); // Se não, imprime mensagem de erro
        return 1;
    }
    novo->valor = valor; // Atribui o valor ao novo nó
    novo->proximo = NULL; //    Inicializa o ponteiro proximo como NULL
    if (*inicio == NULL) { // Verifica se a lista está vazia
        *inicio = novo; // Se sim, o novo nó se torna o início da lista
    } else {
        Num *temp = *inicio; // Se não, percorre a lista até o final
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void imprimir(Num *inicio) { // Imprime os elementos da lista encadeada
    Num *temp = inicio; // Inicializa um ponteiro temporário para percorrer a lista
    while (temp != NULL) { // Enquanto o ponteiro não for NULL
        printf("%d ", temp->valor); // Imprime o valor do nó atual
        temp = temp->proximo; // Avança para o próximo nó
    }
    printf("\n"); // Imprime uma nova linha após imprimir todos os elementos
}

int main(){
    Num *inicio = NULL; // Inicializa o ponteiro para o início da lista como NULL
    int valor, i;
    for (i = 0; i < 3; i++) { // Loop para adicionar 10 elementos à lista
        printf("Digite o valor para o elemento %d: ", i+1); // Solicita ao usuário um valor
        scanf("%d", &valor); // Lê o valor do usuário
        adicionar(&inicio, valor); // Adiciona o valor à lista encadeada
    }
    printf("Elementos da lista encadeada: "); // Imprime mensagem antes de imprimir os elementos
    imprimir(inicio); // Chama a função para imprimir os elementos da lista encadeada

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}