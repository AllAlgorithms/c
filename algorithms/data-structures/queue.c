/*
* Author :  Satyajit Ghana (satyajit_ghana) https://github.com/satyajitghana
* Queue : An attempt to implementing a generic data type queue in C
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define ds(s) printf("\nDEBUG--*"#s " : %s*\n", s);
#define dc(c) printf("\nDEBUG--%"#c " : %c%\n", c);
#define di(i) printf("\nDEBUG--#"#i " : %d#\n", i);

void init_queue(Queue* myqueue, int max_size) {
    myqueue -> head = myqueue -> tail = -1;
    myqueue -> data = NULL;
    myqueue -> MAX = max_size;
}

void enqueue(Queue* myqueue, void* data) {

    if (myqueue -> tail >= myqueue -> MAX) {
        printf("\n*Queue Overflow Detected !*\n");
        return;
    }

    /* This code sucks, you know it and i know it.
     * Move on and call me an idiot later */
    myqueue -> data = realloc(myqueue -> data, (myqueue -> tail + 2) * sizeof *(myqueue -> data));    
    if (myqueue -> data != NULL) {
        if (myqueue -> head == -1) {
            myqueue -> head = 0;
        }
        (myqueue -> data)[++myqueue -> tail] = data;
    } else {
        printf("\n*cannot allocate memory !*\n");
        return;
    }
}

void dequeue(Queue* myqueue) {
    if (myqueue -> head > myqueue -> tail) {
        printf("\n*Queue Underflow detected !*\n");
        return;
    }

    myqueue -> head ++;

    /* Print the removed data */
    printf("removed");
    ds((char*)(myqueue->data)[myqueue -> head - 1]);
}

void display(Queue* myqueue) {
    if (myqueue -> head > myqueue -> tail || myqueue -> head == -1) {
        printf("\nQueue is Empty\n");
        return;
    }
    for (int i = myqueue -> head  ; i <= myqueue -> tail ; i++) {
        //printf("%s\n", *(char**)((mystack->data)[i]));
        di(i);
        //ds((char*)((mystack->data)[i]));
        ds(*(char**)(myqueue->data + i))
    }
}
