#include<stdio.h>
#include<stdlib.h>

int main(void){
    int x, y, aux;
    scanf("%d %d", &x, &y);
    aux = x;
    x = y;
    y = aux;
    printf("%d %d\n", x, y);
    return 0;
}