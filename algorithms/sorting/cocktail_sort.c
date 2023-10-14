#include <stdio.h>

void swap(int *x, int *y);
/**
 * cocktail_sort - cocktail sort algorithm
 * @array: array that will be sorted
 * @size: size of the array
 */
void cocktail_sort(int *array, size_t size)
{
	size_t i, j, k, sorted;

	if (size < 2 || !size || !array)
		return;
	for (i = 0; i < size; i++)
	{
		sorted = 1;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				sorted = 0;
			}
		}

		for (k = j - 1; k > 0; k--)
		{
			if (array[k] < array[k - 1])
			{
				swap(&array[k], &array[k - 1]);
				sorted = 0;
			}
		}
		if (sorted)
			return;
	}
}

/**
 * swap - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

int main()
{
	int arr[] = {3, 8, 1, 4, 3, 9, 0, -1};
	cocktail_sort(arr, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
