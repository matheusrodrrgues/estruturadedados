#include <stdio.h>

int main () {
    int num, contador, soma = 0;
    float media;
    printf("Digite um numero: ");
    scanf("%d", &num);
    while (num > 0) {
        soma = soma + num;
        contador = contador + 1;
        printf("Digite um numero: ");
        scanf("%d", &num);
    }
    media = soma/contador;
    printf("Media: %f\n", media);
}