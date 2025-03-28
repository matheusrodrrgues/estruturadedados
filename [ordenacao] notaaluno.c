// Exercicio desenvolvido para estudos
// Matheus Silva Rodrigues


#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1, nota2, nota3;
} Aluno;

int main() {
    int numalunos, i;
    float media;

    Aluno *aluno; // Ponteiro para armazenar os alunos

    printf("Informe o numero de alunos\n");
    scanf("%d", &numalunos);

    // Aloca memória para o array de alunos
    aluno = (Aluno *) malloc(numalunos * sizeof(Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1; // Retorna um código de erro
    }
    for (i = 0; i < numalunos; i++){
        printf("\nDigite o nome do aluno %d: ", i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &aluno[i].matricula);
        printf("Digite a nota 1 do aluno %d: ", i+1);
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2 do aluno %d: ", i+1);
        scanf("%f", &aluno[i].nota2);
        printf("Digite a nota 3 do aluno %d: ", i+1);
        scanf("%f", &aluno[i].nota3);
    }
    media = 0;
    if (numalunos > 0) {
        for (i = 0; i < numalunos; i++){
            media += (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3;
        }
        media /= numalunos;
    } else {
        printf("Nenhum aluno cadastrado.\n");
    }

    // printando alunos
    printf("Alunos:\n");
    for (i = 0; i < numalunos; i++){
        printf("Nome: %s\n", aluno[i].nome);
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Nota 1: %.2f\n", aluno[i].nota1);
        printf("Nota 2: %.2f\n", aluno[i].nota2);
        printf("Nota 3: %.2f\n", aluno[i].nota3);
        printf("Media: %.2f\n", (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3);
        if (media > 7) {
            printf("Aprovado\n");
        } else (media >= 5) {
            printf("Reprovado\n");
        } 
        printf("Media geral: %.2f\n", media);
        printf("\n");

    }
    free(aluno); // Libera a memória alocada
    return 0;
}