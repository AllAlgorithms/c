#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

void swap(int *a, int *b);
void heapify(int *heap, int size, int i);
void build_heap(int *heap, int size);
void heapsort(int *heap, int size);

int main() {
    int heap[MAX_HEAP_SIZE], size;

    printf("Enter the number of elements (max %d): ", MAX_HEAP_SIZE);
    scanf("%d", &size);

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &heap[i]);
    }

    heapsort(heap, size);

    printf("The sorted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *heap, int size, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left child index
    int r = 2 * i + 2; // right child index

    if (l < size && heap[l] > heap[largest]) {
        largest = l;
    }

    if (r < size && heap[r] > heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, size, largest);
    }
}

void build_heap(int *heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

void heapsort(int *heap, int size) {
    build_heap(heap, size);

    for (int i = size - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}
