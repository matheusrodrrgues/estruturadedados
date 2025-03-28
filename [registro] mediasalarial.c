#include <stdio.h>

typedef struct {
    int idade;
    char sexo;
    float salario[3];
} pesquisa;

int main() {
    pesquisa cidadao;
    float mediasalarial;
    float maiorsalario, menorsalario, bolsafamilia;
    int i, menos30, mais5, menor1000;

    for (i = 0; i < 3; i++) {
        printf("Digite a idade do cidadao: ");
        scanf("%d", &cidadao.idade);

        printf("Digite o sexo do cidadao (M/F): ");
        scanf(" %c", &cidadao.sexo);  

        printf("Digite o salario do cidadao: ");
        scanf("%f", &cidadao.salario[i]);
    }

    maiorsalario = cidadao.salario[0];
    menorsalario = cidadao.salario[0];

    mediasalarial = 0;
    for (i = 0; i < 3; i++) {
        if (cidadao.salario[i] > maiorsalario) {
            maiorsalario = cidadao.salario[i];
        }
        if (cidadao.salario[i] < menorsalario) {
            menorsalario = cidadao.salario[i];
        }
        mediasalarial += cidadao.salario[i];
    }
    mediasalarial /= 3;
    menos30 = cidadao.idade[0];
    menor1000 = cidadao.salario[0];
    mais5 = 0;

    for (i = 0; i < 3; i++) {
        printf("\n\nIdade: %d\nSexo: %c\nSalario: %.2f\n", cidadao.idade, cidadao.sexo, cidadao.salario[i]);
    }
    

    printf("Maior salario: %.2f\n", maiorsalario);
    printf("Menor salario: %.2f\n", menorsalario);
    printf("Media salarial: %.2f\n", mediasalarial);

    return 0;
}
