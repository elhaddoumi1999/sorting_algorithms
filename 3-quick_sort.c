#include "sort.h"
/**
 *partition - partitions an array, using last elwment as pivot
 *@array:array to sort
 *@low:lowest array index
 *@high:highest array index
 *Return:index of pivot
 */
int partition(int *array, int low, int high)
{
	int i, j, pivot, tmp;
	static int size, k;

	if (k == 0)
	{
		size = high + 1;
		k++;
	}
	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}
/**
 *qs_recursive - quicksort recursive function
 *@array:array to sort
 *@low:lowest index
 *@high:highest index
 *Return:void
 */
void qs_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		qs_recursive(array, low, pivot - 1);
		qs_recursive(array, pivot + 1, high);
	}
}
/**
 *quick_sort - sorts an array using quick sort algorithm
 *Implements the Namuto partition scheme
 *@array:array to sort
 *@size:size of array
 *Return:void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	qs_recursive(array, 0, size - 1);
}
