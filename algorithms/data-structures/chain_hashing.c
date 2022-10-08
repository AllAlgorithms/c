#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;
    return ptr;
}

// hash function. I took the size of the hashtable as 10.
int hash(int number)
{
    return number % TABLE_SIZE;
}

void fill_hashtable(struct node *hashtable[], int array[], int size)
{

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    struct node *temp;

    for (int i = 0; i < size; i++)
    {
        if (hashtable[hash(array[i])] != NULL)
        {
            temp = hashtable[hash(array[i])];
            hashtable[hash(array[i])] = createnode(array[i]);
            hashtable[hash(array[i])]->next = temp;
        }
        else
        {
            hashtable[hash(array[i])] = createnode(array[i]);
        }
    }
}

int search_hashtable(struct node *hashtable[], int key)
{
    // we can search for the given key in the linked list with it's head at this index.
    int index = hash(key);

    // head of the chain to be traversed
    struct node *ptr = hashtable[index];

    // traverse the chain
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

int main()
{
    // example to demonstrate working
    int arr[] = {5, 3, 1, 33, 45, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // declare and fill hash table (with size 10 in this case)
    struct node *hashtable[TABLE_SIZE];
    fill_hashtable(hashtable, arr, size);

    // searching for an element in the hashtable
    int found = search_hashtable(hashtable, 40);
    if (found == 1)
    {
        printf("Element found!");
    }
    else
    {
        printf("Element not found.");
    }
    /* The point of hashing is to search for elements in O(1) time.
     * we can also make hash - maps with hashing; even python's dictionaries are a type of hashtable.

     * Now, this way of hashing makes it so that we can access items from the table pretty quickly, but its not the best.
     * if there are a lot of elements in the input array and only a 10 index hash table, accessing elements in the table will no longer be O(1).
     * This is because we will have to search the entire linked list in the worst case. This is a drawback of this type of hashing.

     * however, this hashtable doesnt waste much space, and allows flexibility in the number of elements that can be entered into it.
    */
    return 0;
}
