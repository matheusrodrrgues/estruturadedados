#include <stdio.h>
#include <stdlib.h>

typedef struct card {
    int num;
    struct card *next;
} card;

void inserircarta(card **head, int num) {
    card *new_card = (card *)malloc(sizeof(card));
    new_card->num = num;
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

void retirarcarta(card **head) {
    if (*head == NULL) return;

    card *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void simulateDiscard(int n) {
    card *head = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        inserircarta(&head, i);
    }

    printf("Discarded cards:");
    int first = 1;

    while (head != NULL && head->next != NULL) {
        if (!first) {
            printf(", ");
        }
        printf("%d", head->num);
        first = 0;

        retirarcarta(&head);

        if (head != NULL) {
            card *temp = head;
            retirarcarta(&head);
            inserircarta(&head, temp->num);
            free(temp);
        }
    }

    printf("\nRemaining card: %d\n", head->num);
    free(head);
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        simulateDiscard(n);
    }
    return 0;
}



