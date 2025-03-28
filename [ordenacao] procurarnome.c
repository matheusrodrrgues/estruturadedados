// Exercicio desenvolvido para estudos
// Matheus Silva Rodrigues


/*#include<stdio.h>
#include<stdlib.h>

int main(){
    char nomes[50];
    int i;
    int n;
    char **v;

    printf("Informe a quantidade de nomes que deseja armazenar: ");
    scanf("%d", &n);
    getchar(); // Limpa o buffer do teclado após ler um inteiro

    v = (char **) malloc(n * sizeof(char *)); // Alocando memória para n ponteiros de char
    if (v == NULL) { // Verificando se a alocação foi bem-sucedida
        printf("Erro ao alocar memória.\n");
        return 1; // Saindo do programa com erro
    }

    for (i = 0; i < n; i++){
        printf("Informe o nome %d: ", i + 1);
        fgets(nomes, sizeof(nomes), stdin); // Lê uma linha de texto
        nomes[strcspn(nomes, "\n")] = '\0'; // Remove o caractere de nova linha
        v[i] = (char *) malloc((strlen(nomes) + 1) * sizeof(char)); // Alocando memória para cada nome
        if (v[i] == NULL) { // Verificando se a alocação foi bem-sucedida
            printf("Erro ao alocar memória.\n");
            return 1; // Saindo do programa com erro
        }
        strcpy(v[i], nomes); // Copiando o nome para a memória alocada
    }
    printf("Os nomes informados foram:\n");
    for (i = 0; i < n; i++){
        printf("%s\n", v[i]);
    }

    printf("\n");
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_nomes(char **v, int n) {
    int i, j;
    char *temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(v[i], v[j]) > 0) { // Compara as strings
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int i, n;
    char **v;

    printf("Informe a quantidade de nomes que deseja armazenar: ");
    scanf("%d", &n);
    getchar(); // Remove o '\n' do buffer após scanf

    if (n <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    v = (char **) malloc(n * sizeof(char *)); // Aloca espaço para os ponteiros de nomes
    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        char buffer[100]; // Buffer temporário para armazenar o nome antes da alocação exata

        printf("Informe o nome %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o '\n' lido pelo fgets

        v[i] = (char *) malloc((strlen(buffer) + 1) * sizeof(char)); // Aloca memória exata para o nome
        if (v[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }
        strcpy(v[i], buffer); // Copia o nome para a memória alocada
    }

    ordenar_nomes(v, n); // Chama a função de ordenação

    printf("\nOs nomes ordenados são:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", v[i]);
        free(v[i]); // Libera a memória de cada nome
    }
    
    free(v); // Libera a memória do vetor de ponteiros

    return 0;
}
