#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    // Print array elements using array notation
    printf("Array elements using array notation:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Print array elements using pointer notation
    printf("Array elements using pointer notation:\n");
    int *ptr = numbers;
    for (int i = 0; i < length; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Modify array elements using pointers
    printf("Array elements after modification:\n");
    for (int i = 0; i < length; i++) {
        *(ptr + i) = *(ptr + i) * 2;
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
