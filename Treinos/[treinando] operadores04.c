#include<stdio.h>
#include<stdlib.h>

void somamedia(n1, n2);

main(){
    int n1, n2;
    int n = 0;
    for (n = 0; n < 2; n++){
        printf("Digite a primeira nota: ");
        scanf("%d", &n1);
        printf("Digite a segunda nota: ");
        scanf("%d", &n2);
        somamedia(n1, n2);
    }
}
void somamedia(n1, n2){
    int soma;
    float media;
    soma = n1 + n2;
    media = soma / 2;
    printf("A soma das notas e: %d\n", soma);
    printf("A media das notas e: %.2f\n", media);
}