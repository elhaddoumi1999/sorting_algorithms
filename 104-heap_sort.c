#include "sort.h"
/**
 *swap - swaps two int
 *@a:firstint
 *@b:second int
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
/**
 *heapify - finds largest among root, right and left
 *@array:array to sort
 *@n:int
 *@i:int
 *@size:size
 */
void heapify(int *array, int n, int i, int size)
{
	int largest = i, left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}
/**
 *heap_sort - sorts an array using heap sort algorithm
 *@array:array to sort
 *@size:size of the array
 *Description:implements swift-down algorithm
 *Return:void
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	size = (int)size;
	tmp = size;
	/*Build max heap*/
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, tmp);
	/*heap sort*/
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, tmp);
		heapify(array, i, 0, tmp);
	}
}
