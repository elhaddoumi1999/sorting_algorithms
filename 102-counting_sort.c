#include "sort.h"
/**
 *counting_sort - sorts an array using counting sort algorithm
 *@array:array to sort
 *@size:size of array
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count, i, max;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
		return;
	/*initialize count array with zeroes*/
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/*store the count of each element*/
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]]++;
	}
	/*store the cumulative count of each array*/
	for (i = 0; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/*Find the index of each element of the original array*/
	/*in count array ,place elements in output array*/
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/*copy sorted array to original*/
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
