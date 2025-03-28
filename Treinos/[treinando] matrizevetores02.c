#include <stdio.h>

int main(){
    int i;
    int vet[10];
    int k[20], l;

    for (i = 0; i < 10; i++){
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vet[i]);
    }
    for (l = 0; l < 5; l++){
        printf("Digite o %do valor: ", l+1);
        scanf("%d", &k[l]);
    }
    printf("O 8o valor eh: %d\n", vet[7]);
    printf("O 16o valor eh: %d\n", k[5+vet[7]]);
    return 0;}