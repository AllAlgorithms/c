/* 
*   Author: Phyllipe Bezerra (https://github.com/pmba)
*/

#ifndef UNION_FIND
#define UNION_FIND

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct union_find {
    int size;
    int* parent;
} UnionFind;

UnionFind* createUnionFind(int size);

bool sameSet(UnionFind* uf, int a, int b);

int getRoot(UnionFind* uf, int i);

void merge(UnionFind* uf, int a, int b);

void printUnionFind(UnionFind* uf);

#endif // UNION_FIND