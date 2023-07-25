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
 * bubble_sort - Sorts an array of integers in ascending
 *               order using the bubble sort algorithm.
 * @array: Pointer to the array of integers to sort.
 * @size: The number of elements in the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool is_swapped = false;

	if (array == NULL || size < 2)
		return;

	while (is_swapped == false)
	{
		is_swapped = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				is_swapped = false;
			}
		}
		length--;
	}
}
