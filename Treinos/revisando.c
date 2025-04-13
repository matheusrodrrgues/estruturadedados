#include<stdio.h>

typedef struct Carro {
    int chassi;
    char modelo[20];
    char cor[20];
    int ano;
    float preco;
}Carro;

struct Carro carro[5];

int main(){
    int i;
    printf("Informações do carro: ");
    for (i = 0; i < 5; i++){
        printf("\nCarro %d\n", i+1);
        printf("Chassi: ");
        scanf("%d", carro[i].chassi);
        printf("Modelo: ");
        scanf("%s", carro[i].modelo);
        printf("Cor: ");
        scanf("%s", carro[i].cor);
        printf("Ano: ");
        scanf("%d", carro[i].ano);
        printf("Preço: ");
        scanf("%f", carro[i].preco);
    }
    printf("\n\nCarros cadastrados:\n");
    for (i = 0; i < 5; i++){
        printf("\nCarro %d\n", i+1);
        printf("Chassi: %d\n", carro[i].chassi);
        printf("Modelo: %s\n", carro[i].modelo);
        printf("Cor: %s\n", carro[i].cor);
        printf("Ano: %d\n", carro[i].ano);
        printf("Preço: %.2f\n", carro[i].preco);
    }

}

    