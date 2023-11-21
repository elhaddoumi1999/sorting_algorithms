#include "sort.h"
/**
 *swap - swaps two int
 *@a:first integer
 *@b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 *bitonic_merge - sorts a bitonic sequence
 *@array:array
 *@size:size of array
 *@start:starting index of sequence
 *@seq:size of sequence to sort
 *@flow:direction to sort in
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 1 && array[i] > array[i + jump])
			    || (flow == 0 && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
/**
 *bitonic_seq - converts an array of integers into a bitonic seq
 *@array:array of int
 *@size: size of array
 *@start:starting index of bitonic sequence being built
 *@seq:size of the seq block
 *@flow:direction to sort the bitonic sequence
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int flow)
{
	size_t cut = seq / 2;
	char *str;

	str = (flow == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 1);
		bitonic_seq(array, size, start + cut, cut, 0);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}
/**
 *bitonic_sort - sorts an array using bitonic sort algorithm
 *@array: array of integers
 *@size:size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq(array, size, 0, size, 1);
}
