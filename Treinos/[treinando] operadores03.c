#include <stdio.h>
    void main(){
        int notas[5][5];
        int i, j, maior, menor, media, superiora7;
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                printf("Digite a nota do aluno %d na prova %d: ", i+1, j+1);
                scanf("%d", &notas[i][j]);
            }
        }
        menor = notas[0][0];
        maior = notas[0][0];
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(notas[i][j] < menor){
                    menor = notas[i][j];
                }
                if(notas[i][j] > maior){
                    maior = notas[i][j];
                }
            }
        }
        media = 0;
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                media += notas[i][j];
            }
        }
        media /= 25;
        superiora7 = 0;
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(notas[i][j] >= 7){
                    superiora7++;
                }
            }
        }
        printf("O menor número é: %d\n", menor);
        printf("O maior número é: %d\n", maior);
        printf("A média das notas é: %d\n", media);
        printf("O número de notas acima ou igual a  7 é: %d\n", superiora7);

    }