#include <stdio.h>

#define MAX 5

int QUEUE[MAX];

void insertRear(int *front, int *rear);
void deleteFront(int *front, int *rear);
void deleteRear(int *front, int *rear);
void insertFront(int *front, int *rear);
void display(int front, int rear);

int main() {
    int choice;
    int FRONT = -1, REAR = -1;

    printf("Menu:\n 1. Insert from Rear\n 2. Delete from Front\n 3. "
           "Insert from Front\n 4. Delete from Rear\n 5. Display\n 6. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRear(&FRONT, &REAR);
                break;
            case 2:
                deleteFront(&FRONT, &REAR);
                break;
            case 3:
                insertFront(&FRONT, &REAR);
                break;
            case 4:
                deleteRear(&FRONT, &REAR);
                break;
            case 5:
                display(FRONT, REAR);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void insertRear(int *front, int *rear) {
    int a;

    if (*rear == MAX - 1) {
        printf("Queue is full");
        return;
    }

    if (*front == -1)
        (*front)++;

    printf("Enter Element: ");
    scanf("%d", &a);

    QUEUE[++(*rear)] = a;
}

void deleteFront(int *front, int *rear) {
    int value;

    if (*front < 0) {
        printf("Queue Empty");
        return;
    }

    value = QUEUE[*front];

    if (*rear == *front)
        *front = *rear = -1;
    else
        (*front)++;

    printf("The deleted element from front is: %d", value);
}

void deleteRear(int *front, int *rear) {
    int value;

    if (*front < 0) {
        printf("Queue Empty");
        return;
    }

    value = QUEUE[*rear];

    if (*rear == *front)
        *front = *rear = -1;
    else
        (*rear)--;

    printf("The deleted element from rear is: %d", value);
}

void insertFront(int *front, int *rear) {
    if (*front == 0) {
        printf("Front is at the beginning - insertion not possible");
        return;
    }

    if (*front == -1) {
        (*front)++;
        (*rear)++;
    } else {
        (*front)--;
    }

    int x;
    printf("Enter Element: ");
    scanf("%d", &x);

    QUEUE[*front] = x;
}

void display(int front, int rear) {
    if (front < 0) {
        printf("Queue Empty");
        return;
    }

    printf("Printing DeQueue:\n");

    for (int i = front; i <= rear; i++)
        printf("\t%d", QUEUE[i]);
}