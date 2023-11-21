#include "sort.h"

/**
 *swap - swaps two integers in an array
 *@a:first int
 *@b:second int
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
 *bubble_sort - sorts a list using the bubble sort algorithm
 *@array:pointer to array
 *@size:size of array
 *Return:void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	unsigned int  test = 0;

	len = size;
	if (array == NULL || size < 2)
		return;
	while (test == 0)
	{
		test = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				test = 0;
			}
		}
/*decrementing len coz every time a value is pushed to end, the */
/*values are sorted at the end, reducing length we need to sort*/
		len--;
	}
}
