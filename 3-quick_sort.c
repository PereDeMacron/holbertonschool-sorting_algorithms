#include "sort.h"
/**
 * quick_sort - sorts an array of integers
 * description: sorts an array in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 1)
		return;

	quicksort(array, 0, size - 1, size);
}
/**
 * quicksort - sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: array to sort
 * @min: first of array
 * @max: last of array
 * @size: size of array
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int part;

	if (min < max)
	{

		part = partition(array, min, max, size);

		quicksort(array, min, part - 1, size);
		quicksort(array, part + 1, max, size);
	}
}
/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: array to sort
 * @min: first of array
 * @max: last of array
 * @size: size of array
 *
 * Return: pivot or new pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i = min, j = min, pivot;

	pivot = array[max];

	while (j <= max)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;
		}
		j++;
	}
	_swap(array, i, max, size);

	return (i);
}
/**
 * _swap - swaps two values in an array
 *
 * @array: array to sort
 * @i: min value
 * @j: second value
 * @size: size of data
 *
 */
void _swap(int *array, int i, int j, size_t size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
