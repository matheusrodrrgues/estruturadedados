#include <stdio.h>

int main(){
    int vetora[10], vetorb[10], vetorc[10];
    int i;
    for(i = 0; i < 10; i++){
        printf("Digite o valor %d do vetor A: ", i+1);
        scanf("%d", &vetora[i]);
    }
    for(i = 0; i < 10; i++){
        printf("Digite o valor %d do vetor B: ", i+1);
        scanf("%d", &vetorb[i]);
    }
    for(i = 0; i < 10; i++){
        vetorc[i] = vetora[i] + vetorb[i];
    }
    for(i = 0; i < 10; i++){
        printf("O valor %d do vetor C eh: %d\n", i+1, vetorc[i]);
    }
}