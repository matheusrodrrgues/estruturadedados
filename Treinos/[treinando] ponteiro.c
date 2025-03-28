#include <stdio.h>

void main() {
    int a = 30;
    int *p1;
    int **p2;

    p1 = &a;  // p1 aponta para a
    p2 = &p1; // p2 aponta para p1

    printf("Digite o novo valor do endereco de a: ");
    scanf("%d", p1); // p1 já é um ponteiro para a

    printf("a = %d\n", a);       // Mostra o valor de a
    printf("*p1 = %d\n", *p1);   // Mostra o valor apontado por p1 (que é a)
    printf("**p2 = %d\n", **p2); // Mostra o valor apontado por p2 (que é *p1, ou seja, a)
}