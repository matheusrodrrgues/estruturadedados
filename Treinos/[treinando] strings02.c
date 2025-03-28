#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[351]; // 350 caracteres + 1 para o terminador nulo
    int i, palavras = 0;
    int dentro_palavra = 0;

    printf("Digite uma frase (max 350 caracteres): ");
    fgets(frase, sizeof(frase), stdin);

    // Remover o caractere de nova linha, se presente
    frase[strcspn(frase, "\n")] = '\0';

    for (i = 0; frase[i] != '\0'; i++) {
        if (isspace(frase[i])) {
            dentro_palavra = 0;
        } else if (!dentro_palavra) {
            dentro_palavra = 1;
            palavras++;
        }
    }

    printf("Numero de palavras: %d\n", palavras);

    return 0;
}