#include <stdio.h>

int main() {
    float notas[2][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Digite a nota do aluno %d na disciplina %d: ", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%.2f ", notas[i][j]);
        }
    }
    printf("\n");
}