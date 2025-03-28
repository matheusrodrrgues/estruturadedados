#include<stdio.h>

void calculasoma(int, int);

main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    calculasoma(num1, num2);
}
void calculasoma(int num1, int num2){
    int soma;
    soma = num1 + num2;
    printf("A soma dos numeros e: %d\n", soma);
}