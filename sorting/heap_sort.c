#include <stdio.h>
 
int main()
{
    int heap[10], n, i, j, c, root, temp;
 
    printf("\nEnter no of elements :");
    scanf("%d", &n);
    printf("\nEnter the elements : \n");
    for (i = 0; i < n; i++){
    	printf("Heap[%d] : ",i+1);
	    scanf("%d", &heap[i]);
	}
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* creating MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    for (j = n - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];    /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\nThe sorted array is : ");
    for (i = 0; i < n; i++)
       printf("\t %d", heap[i]);
    return 0;
}
