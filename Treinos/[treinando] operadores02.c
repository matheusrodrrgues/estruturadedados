#include <stdio.h>
    void main(){
        int matriza[4][4];
        int i, j, maior, menor;
        printf("Digite os valores da matriz A:\n");
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                printf("Digite o valor da posicao [%d][%d]: ", i, j);
                scanf("%d", &matriza[i][j]);
            }
        }
        menor = matriza[0][0];
        maior = matriza[0][0];
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                if(matriza[i][j] < menor){
                    menor = matriza[i][j];
                }
                if(matriza[i][j] > maior){
                    maior = matriza[i][j];
                }
            }
        }
        printf("O menor número é: %d\n", menor);
        printf("O maior número é: %d\n", maior);
    
        
    }