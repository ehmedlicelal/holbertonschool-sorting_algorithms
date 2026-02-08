#include "sort.h"

/**
 * swaper - swap to integers
 * @first: one int
 * @second: two int
 * @size: the size of array for printing func
 * @array: the array for printing func
 */
void swaper(int *array, size_t size, int *first, int *second)
{
	if (*first != *second)
	{
		*first = *first + *second;
		*second = *first - *second;
		*first = *first - *second;
		print_array((const int *)array, size);
	}
}

/**
 * partition - function that part an array
 * @array: the array
 * @low: the bottom of the index
 * @high: the top of it
 * @size: the size of array
 * Return: the index
 */
int partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot, i, j;

	pivot = array[high];

	for (j = low, i = j; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swaper(array, size, &array[j], &array[i++]);
		}
	}
	swaper(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * sort_quick - pastitions
 * @array: the array
 * @size: the size of the array
 * @high: the high
 * @low: the low
 */
void sort_quick(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t partitions;

		partitions = partition(array, size, low, high);

		sort_quick(array, size, low, partitions - 1);
		sort_quick(array, size, partitions + 1, high);
	}
}
/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the Quick sort algorithm
 * @array: the array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	sort_quick(array, size, 0, size - 1);
}
