/*Programs for the Data Structures are started from today.Date:-09/08/2020
Author:Alok Khulbay
purpose :Learning Data Structures.*/
#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void CreateArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int *)malloc(tSize * sizeof(int));
    // a->total_size = tSize;
    // a->used_size = uSize;
    // a->ptr = (int *)malloc(tSize * sizeof(int));
}
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter %d element:", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
void set(struct myArray *a, int index)
{
    (a->ptr)[index] = 32;
}
void get(struct myArray *a, int n)
{
    printf("The value in the array in this index is %d\n", (a->ptr)[n]);
}
int main()
{
    struct myArray marks;
    CreateArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);
    printf("We are running show now\n");
    show(&marks);
    set(&marks, 0);
    printf("We are running show now\n");
    show(&marks);
    get(&marks, 0);

    return 0;
}
