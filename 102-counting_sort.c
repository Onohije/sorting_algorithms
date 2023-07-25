#include "sort.h"

/**
 * get_max - Find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer value found in the array.
 */

int get_max(int *array, int size)
{
	int max, j;


	for (max = array[0], j = 1; j < size; j++)
	{
	if (array[j] > max)
	max = array[j];
	}


	return (max);
}


/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: The counting_sort function implements the counting sort
 *                algorithm to sort the array 'array' in ascending order.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted_array, max, j;


	if (array == NULL || size < 2)
	return;


	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
	free(sorted_array);
	return;
	}


	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
	count[array[j]] += 1;
	for (j = 0; j < (max + 1); j++)
	count[j] += count[j - 1];
	print_array(count, max + 1);


	for (j = 0; j < (int)size; j++)
	{
	sorted_array[count[array[j]] - 1] = array[j];
	count[array[j]] -= 1;
	}


	for (j = 0; j < (int)size; j++)
	array[j] = sorted_array[j];

	free(sorted_array);
	free(count);
}
