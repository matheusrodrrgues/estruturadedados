#include <stdio.h>

int main(){
    float peso, altura, imc;
    printf("Digite o peso: ");
    scanf("%f", &peso);
    printf("Digite a altura: ");
    scanf("%f", &altura);
    imc = peso / (altura * altura);

    switch (imc < 18.5 ? 1 : (imc < 25 ? 2 : (imc < 30 ? 3 : (imc < 35 ? 4 : (imc < 40 ? 5 : 6))))) {

        case 1:
            printf("Abaixo do peso\n");
            break;
        case 2:
            printf("Peso normal\n");
            break;
        case 3:
            printf("Sobrepeso\n");
            break;
        case 4:
            printf("Obesidade grau 1\n");
            break;
        case 5:
            printf("Obesidade grau 2\n");
            break;
        case 6:
            printf("Obesidade grau 3\n");
            break;
    }
}