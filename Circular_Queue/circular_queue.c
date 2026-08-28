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

    if ((*rear + 1) % MAX == *front) {
        printf("Queue is full");
        return;
    }

    printf("Enter Element: ");
    scanf("%d", &x);

    if (*front == -1)
        *front = 0;

    *rear = (*rear + 1) % MAX;
    QUEUE[*rear] = x;
}

void delete(int *front, int *rear) {
    int value;

    if (*front == -1) {
        printf("Queue Empty");
        return;
    }

    value = QUEUE[*front];

    if (*front == *rear)
        *front = *rear = -1;
    else
        *front = (*front + 1) % MAX;

    printf("The deleted element is: %d", value);
}

void display(int front, int rear) {
    if (front == -1) {
        printf("Queue Empty");
        return;
    }

    printf("Printing Queue:\n");

    int i = front;
    while (1) {
        printf("\t%d", QUEUE[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}