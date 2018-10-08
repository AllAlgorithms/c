/*
* Author :  Satyajit Ghana (satyajit_ghana) https://github.com/satyajitghana
* Vector : An attempt to implementing Vectors in C
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* The Vector structure */
struct Vector {
    int     length;
    void    **data;
    void    (*print)(struct Vector*);
    void    (*add)(struct Vector*, void *);
    void    (*remove)(struct Vector*, int);
    int     (*comparator)(const void *, const void *);
    int     (*comparator_r)(const void *, const void *);
    void    (*sort)(struct Vector*, bool);
    int     (*search)(struct Vector*, void*, int (*)(const void*, const void*));
    void    (*printOne)(void* data);
};

typedef struct Vector Vector;

/* Generic methods */
Vector* newVector(void (*)(Vector*),
        int (*)(const void *, const void *),
        int (*)(const void *, const void *));
Vector* newMinimalVector(int (*comparator)(const void*, const void*),
        void (*printOne)(void*));
void add(Vector *, void *);
void init(Vector *, void (*)(Vector *),
        int (*)(const void *, const void *),
        int (*)(const void *, const void *));
void del(Vector*, int);
void sort(Vector*, bool descending);
void print_vector(Vector* list);

/* DataType specific methods */
void*   new_int(int);
void*   new_double(double);
void*   new_string(char*);
void    print_int(Vector *);
void    print_string(Vector *);
void    print_one_string(void* str);

/* Comparator methods */
int     int_compare(const void *, const void *);
int     int_compare_r(const void *, const void *);
int     string_compare(const void *, const void *);
int     string_compare_r(const void *, const void *);

/* Sorting Methods */
void insertion_sort(void** arr, size_t length, size_t ele_size, int (*comparator)(const void* data1, const void* data2));

/* Searching Algorithms */
int linear_search_vector(Vector*, void* param, int (*comparator)(const void*, const void*));

#endif
