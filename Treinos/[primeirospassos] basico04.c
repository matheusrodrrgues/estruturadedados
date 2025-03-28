#include <stdio.h>
#include <stdlib.h>

int main(){
    float idade, altura, idioma;
    printf("Digite a idade: ");
    scanf("%f", &idade);
    printf("Digite a altura: ");
    scanf("%f", &altura);
    printf("Digite o idioma: ");
    scanf("%f", &idioma);
    if (idade >= 24 && altura >= 1.70 && idioma >= 2){
        printf("Apto para a vaga\n");
    } else {
        printf("Nao apto para a vaga\n");
    }
}