/* 
*   Author: Phyllipe Bezerra (https://github.com/pmba)
*/

#include <stdio.h>
#include "union_find.h"

int main()
{
    


    return 0;
}

UnionFind* createUnionFind(int size) {
    UnionFind* uf = malloc(sizeof(UnionFind));

    uf->size = size;
    uf->parent = malloc(size * sizeof(int));

    int i;

    for (i = 0; i < size; ++i) {
        uf->parent = -1;
    }

    return uf;
}

bool sameSet(UnionFind* uf, int a, int b) {
    return getRoot(uf, a) == getRoot(uf, b);
}

int getRoot(UnionFind* uf, int i) {
    if (uf->parent[i] < 0) return i;

    return getRoot(uf, uf->parent[i]);
}