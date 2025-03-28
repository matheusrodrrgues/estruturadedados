#include <stdio.h>

int main(){
    int vetor[5], menor;
    int i;

    for(i = 0; i < 5; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &vetor[i]);
    }
    menor = vetor[0];
    for(i = 1; i < 5; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }
    printf("O menor número é: %d\n", menor);
    return 0;

}