#include <stdio.h>

#define MAX 5

int STACK[MAX];

void push(int *top);
void pop(int *top);
void peek(int top);
void display(int top);

int main() {
    int choice;
    int TOP = -1;

    printf("Menu:\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&TOP);
                break;
            case 2:
                pop(&TOP);
                break;
            case 3:
                peek(TOP);
                break;
            case 4:
                display(TOP);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void push(int *top) {
    int x;

    if (*top == MAX - 1) {
        printf("Stack Overflow");
        return;
    }

    printf("Enter Element: ");
    scanf("%d", &x);
     (*top)++;
    STACK[*top] = x;
}

void pop(int *top) {
    int value;

    if (*top < 0) {
        printf("Stack Underflow");
        return;
    }

    value = STACK[*top];
     (*top)--;

    printf("The popped element is: %d", value);
}

void peek(int top) {
    if (top < 0) {
        printf("Stack Empty");
        return;
    }

    printf("The top element is: %d", STACK[top]);
}

void display(int top) {
    if (top < 0) {
        printf("Stack Empty");
        return;
    }

    printf("Printing Stack:\n");

    for (int i = top; i >= 0; i--)
        printf("\t%d", STACK[i]);
}