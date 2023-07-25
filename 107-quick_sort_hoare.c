#include "sort.h"
/**
*swap - This is the postions of two ele in an array
*@array: An array
*@item1: An array element
*@item2: An array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *hoare_partition - The hoare implementation
 *@array: array
 *@first: The 1st array el
 *@last: The last array ele
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int recent = first - 1, finder = last + 1;
	int pvot = array[last];

	while (1)
	{

		do {
			recent++;
		} while (array[recent] < pvot);
		do {
			finder--;
		} while (array[finder] > pvot);
		if (recent >= finder)
			return (recent);
		swap(array, recent, finder);
		print_array(array, size);
	}
}
/**
 *qs - The qick sort algorithm implementation
 *@array: An array
 *@first: the 1st array ele
 *@last: An array elem
 *@size: The size array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - this organizes the place for the algorthhm
 *@array: An array
 *@size: the size of an array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
