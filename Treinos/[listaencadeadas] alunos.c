// Crie um programa em C que implemente uma lista encadeada de alunos, onde cada aluno tem:
// nome (string de até 50 caracteres)
// matrícula (inteiro)
// média final (float)

#include<Stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno{
    char nome[50]; // string para armazenar o nome do aluno
    int matricula; // inteiro para armazenar a matrícula do aluno
    float media_final; // float para armazenar a média final do aluno
    struct aluno *proximo; // ponteiro para o próximo aluno na lista encadeada
}Aluno;

void inserirfinal(Aluno **lista, int num, char nome[], float media_final) {
    Aluno *aux, *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo) {
        novo->matricula = num;
        strcpy(novo->nome, nome); // Copia o nome para o campo da estrutura
        novo->media_final = media_final; // Armazena a média final
        novo->proximo = NULL; // O próximo nó é nulo, pois é o último nó da lista

        if (*lista == NULL) { // Se a lista estiver vazia, o novo nó se torna o primeiro nó
            *lista = novo;
        } else {
            aux = *lista; // Ponteiro auxiliar para percorrer a lista
            while (aux->proximo != NULL) { // Percorre a lista até o último nó
                aux = aux->proximo;
            }
            aux->proximo = novo; // Adiciona o novo nó ao final da lista
        }
        printf("Aluno %s (matrícula %d) inserido no final da lista com média %.2f\n", nome, num, media_final);
    } else {
        printf("Erro ao alocar memória\n"); // Imprime mensagem de erro se a alocação falhar
    }
}

void removeraluno(Aluno **lista, int num, char nome[], float media_final) {
    if (*lista == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia. Nenhum aluno para remover.\n");
        return;
    }
    Aluno *aux = *lista, *anterior = NULL;

    // Busca o nó com a matrícula fornecida
    while (aux != NULL && aux->matricula != num) {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux == NULL) { // Se não encontrou o aluno
        printf("Aluno com matrícula %d não encontrado.\n", num);
        return;
    }

    // Remove o nó
    if (anterior == NULL) { // Caso o nó a ser removido seja o primeiro
        *lista = aux->proximo;
    } else { // Caso o nó a ser removido esteja no meio ou no final
        anterior->proximo = aux->proximo;
    }

    printf("Aluno com matrícula %d removido.\n", num);
    free(aux); // Libera a memória do nó removido
}
void imprimir (Aluno **lista, int num, char nome[], float media_final) {
    Aluno *aux = *lista; // Ponteiro auxiliar para percorrer a lista
    if (aux == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }
    printf("Lista de alunos:\n");
    while (aux != NULL) { // Percorre a lista até o final
        printf("Nome: %s, Matrícula: %d, Média Final: %.2f\n", aux->nome, aux->matricula, aux->media_final);
        aux = aux->proximo; // Avança para o próximo nó
    }
    printf("Fim da lista.\n");

}

void buscaraluno (Aluno **lista, int num, char nome[], float media_final){
    Aluno *aux = *lista; // Ponteiro auxiliar para percorrer a lista
    if (aux == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }
    printf("Lista de alunos:\n");
    while (aux != NULL) { // Percorre a lista até o final
        if (aux->matricula == num) { // Se encontrar o aluno com a matrícula fornecida
            printf("Nome: %s, Matrícula: %d, Média Final: %.2f\n", aux->nome, aux->matricula, aux->media_final);
            return;
        }
        aux = aux->proximo; // Avança para o próximo nó
    }
    printf("Aluno com matrícula %d não encontrado.\n", num); // Se não encontrar o aluno
    printf("Fim da lista.\n");

}


int main() {
    Aluno *lista = NULL; // Inicializa a lista como vazia
    int opcao, num;
    char nome[50];
    float media_final;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Inserir aluno no final\n");
        printf("2. Remover aluno\n");
        printf("3. Imprimir lista de alunos\n");
        printf("4. Buscar aluno\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &num);
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite a média final do aluno: ");
                scanf("%f", &media_final);
                inserirfinal(&lista, num, nome, media_final); // Chama a função para inserir o aluno no final da lista
                break;
            case 2:
                printf("Digite a matrícula do aluno a ser removido: ");
                scanf("%d", &num);
                removeraluno(&lista, num, nome, media_final); // Chama a função para remover o aluno
                break;
            case 3:
                imprimir(&lista, num, nome, media_final); // Chama a função para imprimir a lista de alunos
                break;
            case 4:
                printf("Digite a matrícula do aluno a ser buscado: ");
                scanf("%d", &num);
                buscaraluno(&lista, num, nome, media_final); // Chama a função para buscar o aluno
                break;
            case 5:
                printf("Saindo...\n"); // Mensagem de saída
                break;
            default:
                printf("Opção inválida. Tente novamente.\n"); // Mensagem de erro se a opção for inválida
        }
    } while (opcao != 5); // Continua até que o usuário escolha sair

    return 0; // Retorna 0 ao sistema operacional
}