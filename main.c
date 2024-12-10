#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
    printf("Element %d pushed to the stack\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    int choice, value;

    initializeStack(&stack);

    do {
        printf("\nMenu:\n");
        printf("1. Push element to stack\n");
        printf("2. Pop element from stack\n");
        printf("3. View top element of stack\n");
        printf("4. Print all stack elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                printStack(&stack);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
