#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Organize the elements in an array into a binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, wide;

	left = 2 * root + 1;
	right = 2 * root + 2;
	wide = root;

	if (left < base && array[left] > array[wide])
		wide = left;
	if (right < base && array[right] > array[wide])
		wide = right;

	if (wide != root)
	{
		swap_ints(array + root, array + wide);
		print_array(array, size);
		max_heapify(array, size, base, wide);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 *      Prints the array after each swap of two elements during sorting.
 */

void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0);
	}
}
