/*
* Author :  Satyajit Ghana (satyajit_ghana) https://github.com/satyajitghana
* Stack : An attempt to implementing a generic data type stack in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define ds(s) printf("\nDEBUG--*"#s " : %s*\n", s);
#define dc(c) printf("\nDEBUG--%"#c " : %c%\n", c);
#define di(i) printf("\nDEBUG--#"#i " : %d#\n", i);

Stack* newStack(int max_size) {
    Stack* mystack = malloc(sizeof *mystack);
    init_stack(mystack, max_size);
    return mystack;
}

void init_stack(Stack* mystack, int max_size) {
    mystack -> top = -1;
    mystack -> data = NULL;
    mystack -> MAX = max_size;
    mystack -> push = push;
    mystack -> pop = pop;
    mystack -> display = display;
    mystack -> peek = peek;
    mystack -> isEmpty = isEmpty;
}

void push(Stack* mystack, void* data) {

    if (mystack -> top >= mystack -> MAX) {
        printf("\n*Stack Overflow Detected !*\n");
        return;
    }

    /* This code sucks, you know it and i know it.
     * Move on and call me an idiot later */
    mystack -> data = realloc(mystack -> data, (mystack -> top + 2) * sizeof *(mystack -> data));    
    if (mystack -> data != NULL) {
        (mystack -> data)[(++mystack -> top)] = data;
    } else {
        printf("\n*cannot allocate memory !*\n");
    }
}

void display(Stack* mystack) {
    for (int i = mystack -> top  ; i >= 0 ; i--) {
        printf("%s ", *(char**)(mystack->data + i));
    }
}

void* pop(Stack* mystack) {
    if (mystack -> top < 0) {
        printf("\n*Stack Underflow detected !*\n");
        return NULL;
    }

    mystack -> top--;
    /* Resize the data array as the elements are removed */
    mystack -> data = realloc(mystack -> data, (mystack -> top + 2) * sizeof *(mystack-> data));

    return (mystack -> data)[(mystack -> top)+1];
}

void* peek(Stack* mystack) {
    return (mystack -> data)[mystack -> top];
}

bool isEmpty(Stack* mystack) {
    if (mystack -> top < 0)
        return true;
    return false;
}
