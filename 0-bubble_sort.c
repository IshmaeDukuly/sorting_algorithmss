#include "sort.h"
/**
 * bubble_sort - This is the sorting of
 * array elements from the minimum to the maximum val
 * @array: array
 * @size: The size of an array
 */
void bubble_sort(int *array, size_t size)
{

	size_t im, indx, tmp = 0;

	if (size < 2)
		return;
	for (m = 0; m < size; m++)
		for (indx = 0; indx < size; indx++)
		{
			if (array[indx] > array[indx + 1] && array[indx + 1])
			{
			tmp = array[indx];
			array[indx] = array[indx + 1];
			array[indx + 1] = tmp;
			print_array(array, size);
			}
		}
}
