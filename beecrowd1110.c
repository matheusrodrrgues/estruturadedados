#include <stdio.h>
#include <stdlib.h>

typedef struct card {
    int num;
    int dado;
    struct card *next;
} card;

void inserircarta(card **head, int num, int dado) {
    card *new_card = (card *)malloc(sizeof(card));
    new_card->num = num;
    new_card->dado = dado;
    new_card->next = NULL;

    if (*head == NULL) {
        *head = new_card;
    } else {
        card *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_card;
    }
}