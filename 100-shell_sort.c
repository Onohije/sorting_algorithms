#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;


	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: pointer to an array of integers.
 * @size: The number of element in the array.
 *
 * Description: The shell_sort function sorts the array 'array' in
 *                ascending order using the shell sort algorithm.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, k, n;


	if (array == NULL || size < 2)
	return;

	for (gap = 1; gap < (size / 3);)
	gap = gap * 3 + 1;


	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
	{
		n = k;
		while (n >= gap && array[n - gap] > array[n])
		{
		swap_ints(array + n, array + (n - gap));
		n -= gap;
		}
	}
	print_array(array, size);
	}
}
