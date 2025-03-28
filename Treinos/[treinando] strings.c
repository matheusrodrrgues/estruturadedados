#include <stdio.h>

void main(){
    char email[100], alias[100];
    int i = 0;

    printf("Digite o email: ");
    fgets(email, 100, stdin);

    while (email[i] != '@'){
        alias[i] = email[i];
        i++;
    } 
    alias[i] = '\0';
    printf("O alias do email eh: %s\n", alias);
}