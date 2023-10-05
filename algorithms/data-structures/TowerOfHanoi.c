#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int capacity;
    int top;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // Stack is empty
}

// Function to move a disk from one peg to another and print the step
void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from, to);
}

// Function to solve Tower of Hanoi iteratively
void towerOfHanoiIterative(int n, struct Stack* source, struct Stack* auxiliary, struct Stack* destination) {
    // Calculate the total number of moves required
    int total_moves = (1 << n) - 1;

    // Determine the direction of movement based on whether n is even or odd
    char from_peg = 'A', to_peg = 'C', aux_peg = 'B';
    if (n % 2 == 0) {
        to_peg = 'B';
        aux_peg = 'C';
    }

    for (int move = 1; move <= total_moves; ++move) {
        if (move % 3 == 1) {
            moveDisk(from_peg, to_peg, pop(source));
        } else if (move % 3 == 2) {
            moveDisk(from_peg, aux_peg, pop(auxiliary));
        } else {
            moveDisk(aux_peg, to_peg, pop(destination));
        }
    }
}

int main() {
    int n = 4; // Number of disks

    // Create stacks for the source, auxiliary, and destination pegs
    struct Stack* source = createStack(n);
    struct Stack* auxiliary = createStack(n);
    struct Stack* destination = createStack(n);

    // Initialize the source peg with disks
    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    // Solve the Tower of Hanoi problem iteratively
    towerOfHanoiIterative(n, source, auxiliary, destination);

    // Free memory for the stacks
    free(source->array);
    free(source);
    free(auxiliary->array);
    free(auxiliary);
    free(destination->array);
    free(destination);

    return 0;
}

