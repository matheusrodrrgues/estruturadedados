#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch, *ptr;

    // Lê a string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove o '\n' do final da string

    // Lê o caractere
    printf("Digite um caractere: ");
    scanf(" %c", &ch);

    // Substitui todas as ocorrências do caractere por '*'
    for (ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == ch) {
            *ptr = '*';
        }
    }

    // Imprime a nova string
    printf("Nova string: %s\n", str);

    return 0;
}