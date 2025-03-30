#include<Stdio.h>
#include<Stdlib.h>
#include<string.h>

typedef struct BandaLarga{
    char nome[50];
    int velocidade;
    struct BandaLarga *proximo;
} BandaLarga;

BandaLarga* inicio(BandaLarga* head, char nome[], int velocidade){
    BandaLarga* novo = (BandaLarga*)malloc(sizeof(BandaLarga));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return head;
    }
    strcpy(novo->nome, nome);
    novo->velocidade = velocidade;
    novo->proximo = head;
    return novo;
}

void printlista (BandaLarga* head){
    BandaLarga* atual = head;
    while (atual != NULL){
        printf("Nome: %s, Velocidade: %d\n", atual->nome, atual->velocidade);
        atual = atual->proximo;
    }
}

int main(){
    BandaLarga* lista = NULL;
    int i;

    for (i = 0; i < 3; i++){
        BandaLarga* novo = (BandaLarga*)malloc(sizeof(BandaLarga));
        if (novo == NULL) {
            printf("Erro ao alocar memoria\n");
            return 1;
        }
        printf("Digite o nome da operadora: ");
        scanf("%s", novo->nome);
        printf("Digite a velocidade: ");
        scanf("%d", &novo->velocidade);
        novo->proximo = lista;
        lista = novo;
    }

    printf("Elementos da lista:\n");
    printlista(lista);

    BandaLarga* atual = lista;
    while (atual != NULL) {
        BandaLarga* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    return 0;
}