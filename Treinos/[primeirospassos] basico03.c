#include <stdio.h>

int main() {
    char nome[50];
    float idade, peso, doar;
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite a idade: ");
    scanf("%f", &idade);
    printf("Digite o peso: ");
    scanf("%f", &peso);
    
    if (idade >= 18 && idade <= 65) {
        if (peso >= 50) {
            printf("Pode doar sangue\n");
        } else {
            printf("Nao pode doar sangue\n");
        }
        return 0;
    }
}