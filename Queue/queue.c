#include <stdio.h>

#define MAX 5

int QUEUE[MAX];

void insert(int *front, int *rear);
void delete(int *front, int *rear);
void display(int front, int rear);

int main() {
    int choice;
    int FRONT = -1, REAR = -1;

    printf("Menu:\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&FRONT, &REAR);
                break;
            case 2:
                delete(&FRONT, &REAR);
                break;
            case 3:
                display(FRONT, REAR);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void insert(int *front, int *rear) {
    int x;

    if (*rear == MAX - 1) {
        printf("Queue is full");
        return;
    }

    if (*front == -1)
        *front = 0;

    printf("Enter Element: ");
    scanf("%d", &x);

    (*rear)++;
    QUEUE[*rear] = x;
}

void delete(int *front, int *rear) {
    int value;

    if (*front == -1 || *front > *rear) {
        printf("Queue Empty");
        return;
    }

    value = QUEUE[*front];
    (*front)++;

    printf("The deleted element is: %d", value);
}

void display(int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue Empty");
        return;
    }

    printf("Printing Queue:\n");

    for (int i = front; i <= rear; i++)
        printf("\t%d", QUEUE[i]);
}