#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @f: The first integer to be swapped.
 * @l: The second integer to be swapped.
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
 *                   using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t q, k;

	if (array == NULL || size < 2)
		return;

	for (q = 0; q < size - 1; q++)
	{
		min = array + q;
		for (k = q + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + q) != min)
		{
			swap_ints(array + q, min);
			print_array(array, size);
		}
	}
}
