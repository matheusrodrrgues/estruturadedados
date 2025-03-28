# include <stdio.h>
# include <stdlib.h>
main(){
    
    int a, i, *p;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    p = (int*) malloc(n*sizeof(int));

    if(!p)
        printf("\n\nErro! Memória Insuficiente!\n");
    else
    {
        for(i = 0; i < n; i++)
            p[i] = i*i; //p é um vetor com n posições

    }
}