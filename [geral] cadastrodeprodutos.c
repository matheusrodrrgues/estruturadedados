#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct produto{
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

int main(){
    Produto *produtos = NULL;
    int num_produtos = 0;
    char opcao[10];

    do {
        printf("Digite a opcao (adicionar, listar, sair): ");
        scanf("%s", opcao);

        if (strcmp(opcao, "adicionar") == 0) {
            produtos = realloc(produtos, (num_produtos + 1) * sizeof(Produto));
            if (produtos == NULL) {
                printf("Erro ao alocar memoria.\n");
                return 1;
            }

            printf("Digite o nome do produto: ");
            scanf("%s", produtos[num_produtos].nome);
            printf("Digite a descricao do produto: ");
            scanf("%s", produtos[num_produtos].descricao);
            printf("Digite o preco do produto: ");
            scanf("%f", &produtos[num_produtos].preco);
            printf("Digite a quantidade do produto: ");
            scanf("%d", &produtos[num_produtos].quantidade);

            num_produtos++;
        } else if (strcmp(opcao, "listar") == 0) {
            for (int i = 0; i < num_produtos; i++) {
                printf("Produto %d:\n", i + 1);
                printf("Nome: %s\n", produtos[i].nome);
                printf("Descricao: %s\n", produtos[i].descricao);
                printf("Preco: %.2f\n", produtos[i].preco);
                printf("Quantidade: %d\n", produtos[i].quantidade);
            }
        }
    } while (strcmp(opcao, "sair") != 0);

    if (num_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("Total de produtos cadastrados: %d\n", num_produtos);
    }
    free(produtos);
    return 0;
}