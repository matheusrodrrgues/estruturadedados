#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do aluno
typedef struct aluno {
    char nome[50];
    int matricula;
    float nota;
    struct aluno *proximo;
} Aluno;

// Estrutura da pilha
typedef struct {
    Aluno *topo;
} Pilha;

// Inicializa a pilha
void iniciar(Pilha *p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

// Empilha um novo aluno
void empilhar(Pilha *p, char nome[], int matricula, float nota) {
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->nota = nota;

    novo->proximo = p->topo;
    p->topo = novo;

    printf("Aluno %s (matricula %d) empilhado com nota %.2f.\n", nome, matricula, nota);
}

// Desempilha (remove) o aluno do topo
void desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia, nenhum aluno para remover.\n");
        return;
    }

    Aluno *removido = p->topo;
    p->topo = removido->proximo;

    printf("Aluno removido: %s (matricula %d), nota %.2f\n", removido->nome, removido->matricula, removido->nota);
    free(removido);
}

// Mostra todos os alunos da pilha
void mostrar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    Aluno *aux = p->topo;
    printf("Alunos na pilha:\n");
    while (aux != NULL) {
        printf("Nome: %s, Matricula: %d, Nota: %.2f\n", aux->nome, aux->matricula, aux->nota);
        aux = aux->proximo;
    }
}

int main() {
    Pilha pilha;
    iniciar(&pilha);

    empilhar(&pilha, "Ana", 101, 8.5);
    empilhar(&pilha, "Bruno", 102, 7.8);
    empilhar(&pilha, "Carla", 103, 9.2);

    mostrar(&pilha);

    desempilhar(&pilha);
    mostrar(&pilha);

    return 0;
}
