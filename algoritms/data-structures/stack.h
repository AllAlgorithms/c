/*
* Author :  Satyajit Ghana (satyajit_ghana) https://github.com/satyajitghana
* Stack : An attempt to implementing a generic data type stack in C
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

/* Why not use a Vector and delete first element, anyways
 * it adds elements to the end of the list, using Vectors method
 * there will be no size limitations */

struct Stack {
    int top;
    void **data;
    int MAX;
    void (*push)(struct Stack*, void*);
    void* (*pop)(struct Stack*);
    void (*display)(struct Stack*);
    void* (*peek)(struct Stack*);
    bool (*isEmpty)(struct Stack*);
};

typedef struct Stack Stack;

/* Initialize the Stack */
Stack* newStack(int);
void init_stack(Stack*, int);

/* Stack Operations */
void push(Stack*, void *);
void* pop(Stack*);
void display(Stack*);
void* peek(Stack*);
bool isEmpty(Stack*);

#endif
