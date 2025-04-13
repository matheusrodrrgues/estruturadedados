#include <Stdio.h>
#include <stdlib.h>


//* Exemplo de alocação de memória dinâmica usando malloc e free
//* O código aloca memória para um vetor de inteiros, atribui um valor a ele e imprime o valor e o endereço de memória. Em seguida, libera a memória alocada.


/*  int main(){
    int *p = malloc(10 * sizeof(int)); // Aloca memória para 10 inteiros
    if (p == NULL) {
        printf("Erro ao alocar memoria\n"); // Verifica se a alocação foi bem-sucedida
        return 1;
    }
    *p = 15000;
    printf("Valor: %d\n", *p);
    printf("Endereco: %p\n", (void*)p);

    free(p); // Libera a memória alocada

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso

}
*/
int main(){
    int *p = calloc(10, sizeof(int)); // Aloca memória para 10 inteiros e inicializa com zero
        if (p == NULL) {
        printf("Erro ao alocar memoria\n"); 
        return 1;
    }
    int i;
    for (i = 0; i < 10; i++){
        printf("Digite o valor para o elemento %d: ", i+1);
        scanf("%d", &p[i]); // Lê o valor do elemento
    }
    for (i = 0; i < 10; i++){
        printf("Elemento %d: %d\n", i+1, p[i]); // Imprime o valor do elemento
    }
    printf("Valor: %d\n", *p);
    printf("Endereco: %p\n", (void*)p);

    free(p);

    return 0; 

}
