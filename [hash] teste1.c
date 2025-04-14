#include<stdio.h>
#include<stdlib.h>

// estrutura tabela hash
// descobrindo o tamanho da tabela é 2x o tamanho da tabela, que neste caso é 15
// 2*15 = 30, escolhendo o primo mais próximo dá 31
// o tamanho da tabela é 31

#define TAM 31

void inicializaTabela(int t[]) {
    int i;
    for (i = 0; i < TAM; i++) {
        t[i] = -1; // Inicializando a tabela com -1
    }
}

int funcaoHash(int chave) {
    return chave % TAM; // Função hash simples (módulo)
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor); // Calcula o índice da tabela hash
    while(t[id] != 0){
        id = funcaoHash(id + 1); // Probing linear
    }
    t[id] = valor; // Insere o valor na tabela
}

int buscar(int t[], int chave){
    int id = funcaoHash(chave); // Calcula o índice da tabela hash
    while(t[id] != 0){
        if(t[id] == chave) 
            return t[id]; // Retorna o índice se a chave for 
        else
            id = funcaoHash(id + 1); // Probing linear
    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        if(t[i] != -1){
            printf("t[%d] = %d\n", i, t[i]); // Imprime os valores da tabela hash
        }
    }
}

int main(){
    int opcao, tabela[TAM]; // Definindo a tabela hash
    inicializaTabela(tabela); // Inicializando a tabela hash
    
    do {
        printf("Escolha uma opção:\n");
        printf("1. Inicializar tabela\n");
        printf("2. Inserir valor\n");
        printf("3. Buscar valor\n");
        printf("4. Imprimir tabela\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inicializaTabela(tabela); // Inicializa a tabela hash
                printf("Tabela inicializada.\n");
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                int valor;
                scanf("%d", &valor);
                inserir(tabela, valor); // Insere o valor na tabela hash
                printf("Valor %d inserido.\n", valor);
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                int chave;
                scanf("%d", &chave);
                int resultado = buscar(tabela, chave); // Busca o valor na tabela hash
                if(resultado != -1){
                    printf("Valor %d encontrado na tabela.\n", resultado);
                } else {
                    printf("Valor %d não encontrado.\n", chave);
                }
                break;
            case 4:
                imprimir(tabela); // Imprime os valores da tabela hash
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    while(opcao != 5); // Continua até que o usuário escolha sair
    return 0;
}