#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array of integers to sort.
 * @size: The number of elements in the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t q, j;

	if (array == NULL || size < 2)
		return;
	/*Loop through the array, starting from the first element*/
	for (q = 0; q < size - 1; q++)
	{
		min = array + q;
		for (j = q + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + q) != min)
		{
			swap_ints(array + q, min);
			print_array(array, size);
		}
	}
}
