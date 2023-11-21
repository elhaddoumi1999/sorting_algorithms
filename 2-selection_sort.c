#include "sort.h"

/**
 *selection_sort - sorts an array using selection sort algorithm
 *Description:creates a sublist of sorted no. that is empty at the
 *beginning
 *@array:array to sort
 *@size: size of array
 *Return:void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
		{
			tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
