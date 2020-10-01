/*
* Author :  Satyajit Ghana (satyajit_ghana) https://github.com/satyajitghana
* Queue : An attempt to implementing a generic data type queue in C
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

struct Queue {
    int head;
    int tail;
    void **data;
    int MAX;
};

typedef struct Queue Queue;

/* Initialize the Queue */
void init_queue(Queue*, int);

/* Queue Operations */
void enqueue(Queue*, void *);
void dequeue(Queue*);
void display(Queue*);

#endif
