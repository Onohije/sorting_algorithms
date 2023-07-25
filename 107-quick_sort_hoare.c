#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme to recursively
 *               sort the elements in the array in ascending order.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int pivot_index;

	if (right - left > 0)
	{
		pivot_index = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, pivot_index - 1);
		hoare_sort(array, size, pivot_index, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme to sort the array
 * in ascending order. Prints the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
