#include <stdio.h>

int main(){
    int contador, soma = 0;
    float idade, matricula;
    for (contador = 0; contador < 10; contador++){
        printf("Digite a idade: ");
        scanf("%f", &idade);
        printf("Digite a matricula: ");
        scanf("%f", &matricula);

        soma += contador;
        printf("Soma: %d\n", (int)soma);
    }


}