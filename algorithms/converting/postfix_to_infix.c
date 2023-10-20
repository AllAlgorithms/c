#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for a stack
struct Stack {
    char data[MAX_SIZE][MAX_SIZE]; // Use a 2D array to store operands and operators
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
void push(struct Stack* stack, char item[], int isOperator) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    
    if (isOperator) {
        // Enclose operators in parentheses for proper infix expression
        sprintf(stack->data[++stack->top], "(%s)", item);
    } else {
        strcpy(stack->data[++stack->top], item);
    }
}

// Function to pop an element from the stack
void pop(struct Stack* stack, char result[]) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    strcpy(result, stack->data[stack->top--]);
}

// Function to convert postfix to infix expression
void postfixToInfix(char postfix[], char infix[]) {
    struct Stack operandStack;
    initialize(&operandStack);

    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            char operand[2];
            operand[0] = symbol;
            operand[1] = '\0';
            push(&operandStack, operand, 0); // 0 indicates it's an operand
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            char operand1[MAX_SIZE], operand2[MAX_SIZE];
            pop(&operandStack, operand1);
            pop(&operandStack, operand2);

            char expression[MAX_SIZE];
            sprintf(expression, "%s %c %s", operand2, symbol, operand1);

            push(&operandStack, expression, 1); // 1 indicates it's an operator
        }
    }

    // The final result is at the top of the stack
    pop(&operandStack, infix);
}

int main() {
    char postfix[MAX_SIZE], infix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix, infix);

    printf("The infix expression is: %s\n", infix);

    return 0;
}
