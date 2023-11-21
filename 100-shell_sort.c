#include "sort.h"
/**
 *swap - swaps two int
 *@a: first int
 *@b: second int
 *Return:void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 *shell_sort - sorts an array using shell algorithm
 *@array:array to sort
 *@size:size of array
 *Return:void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, intv;

	if (array == NULL || size < 2)
		return;
	/*knuth interval sequence*/
	for (intv = 1; intv < (size / 3);)
		intv = intv * 3 + 1;
	for (; intv >= 1; intv /= 3)
	{
		for (i = intv; i < size; i++)
		{
			j = i;
			while (j >= intv && array[j - intv] > array[j])
			{
				swap(array + j, array + (j - intv));
				j -= intv;
			}
		}
		print_array(array, size);
	}
}
