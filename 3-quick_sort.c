#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final index of the pivot element after the partitioning process.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: pointer to the array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: The lomuto_sort function implements the quicksort
 *              algorithm using the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pivot_index;

	if (right - left > 0)
	{
		pivot_index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pivot_index - 1);
		lomuto_sort(array, size, pivot_index + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: pointer to an array of integers.
 * @size: The number of elements in the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
