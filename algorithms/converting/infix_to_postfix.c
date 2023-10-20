#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for a stack
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/');
}

// Function to convert infix to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int length = strlen(infix);
    int j = 0;

    for (int i = 0; i < length; i++) {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(&operatorStack, symbol);
        } else if (symbol == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            // Pop the corresponding '('
            if (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] == '(') {
                pop(&operatorStack);
            }
        } else if (isOperator(symbol)) {
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.data[operatorStack.top]) >= getPrecedence(symbol)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, symbol);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}
