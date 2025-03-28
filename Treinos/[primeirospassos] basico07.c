#include <stdio.h>

int main(){
    float notas[5], maior;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Digite a nota do aluno %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    maior = notas[0];
    for (i = 1; i < 5; i++)
    {
        if (notas[i] > maior)
        {
            maior = notas[i];
        }
    }
    printf("A maior nota foi: %.2f\n", maior);
    return 0;
}