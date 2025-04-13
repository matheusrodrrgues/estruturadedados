#include <Stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, n, m, **matriz1, **matriz2, **resultado;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &n, &m);
    matriz1 = (int **)malloc(n * sizeof(int *));
    matriz2 = (int **)malloc(n * sizeof(int *));
    resultado = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++){
        matriz1[i] = (int *)malloc(m * sizeof(int));
        matriz2[i] = (int *)malloc(m * sizeof(int));
        resultado[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Digite os elementos da primeira matriz:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("Digite os elementos da segunda matriz:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("Resultado da soma das matrizes:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++){
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);
    return 0;
}