/* 
*   Author: Phyllipe Bezerra (https://github.com/pmba)
*/

#include <stdio.h>
#include "union_find.h"

int main()
{
    UnionFind* uf = createUnionFind(5);

    printUnionFind(uf);

    merge(uf, 0, 2);
    merge(uf, 1, 3);
    merge(uf, 0, 4);

    printUnionFind(uf);

    return 0;
}

UnionFind* createUnionFind(int size) {
    UnionFind* uf = malloc(sizeof(UnionFind));

    uf->size = size;
    uf->parent = malloc(size * sizeof(int));

    int i;

    for (i = 0; i < size; ++i) {
        uf->parent[i] = -1;
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

void merge(UnionFind* uf, int a, int b) {
    a = getRoot(uf, a);
    b = getRoot(uf, b);

    if (a == b) return;

    if (uf->parent[a] < uf->parent[b]) {
        int aux = uf->parent[a];

        uf->parent[a] = uf->parent[b];
        uf->parent[b] = aux;
    }

    uf->parent[b] += uf->parent[a];
    uf->parent[a] = b;
}

void printUnionFind(UnionFind* uf) {
    int i;

    for (i = 0; i < uf->size; ++i) {
        printf("%d ", uf->parent[i]);
    }

    printf("\n");
}