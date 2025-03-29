// Exercicio desenvolvido para estudos
// Matheus Silva Rodrigues.

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char nome[52];
    int id;
    float salario;
} Funcionario;

int main(){
    int id, i, num;
    float salario, media;
    Funcionario *funcionario; // Ponteiro para armazenar os funcionarios

    funcionario = (Funcionario *) malloc(num * sizeof(Funcionario));
    if (funcionario == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1; // Retorna um código de erro
    }
    printf("Informe o numero de funcionarios\n");
    scanf("%d", &num);


    for (i = 0; i < num; i++){
        printf("\nDigite o nome do funcionario %d: ", i+1);
        scanf("%s", funcionario[i].nome);
        printf("Digite o id do funcionario %d: ", i+1);
        scanf("%d", &funcionario[i].id);
        printf("Digite o salario do funcionario %d: ", i+1);
        scanf("%f", &funcionario[i].salario);
        printf("Funcionario %d cadastrado com sucesso!\n", i+1);
    }
    while (1){
        printf("Digite o id do funcionário que deseja buscar (ou -1 para sair): ");
        scanf("%d", &id);
        if (id == -1) {
            break; // Sai do loop se o id for -1
        }
        for (i = 0; i < num; i++){
            if (funcionario[i].id == id) {
                printf("Funcionario encontrado:\n");
                printf("Nome: %s\n", funcionario[i].nome);
                printf("ID: %d\n", funcionario[i].id);
                printf("Salario: %.2f\n", funcionario[i].salario);
                break; // Sai do loop se o funcionario for encontrado
            }
        }
    }
}
