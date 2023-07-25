#include "sort.h"
#include <stdio.h>

/**
 * swap - The utility function to swap to ints
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - This is the main function to heapify the maximum Heap.
 * The function perceives that everything under the given
 * root (elem at indx idx)
 * @array: array
 * @size: The size of the array for print
 * @idx: the indx
 * @n: The size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;		 /* Initialize largest as root*/
	int left = 2 * idx + 1;	 /* left = (idx << 1) + 1*/
	int right = 2 * idx + 2; /* right = (idx + 1) << 1*/

	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * See if right child of the root is in existing
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int m;
	/**
	 * This Starts from bottom and right internal mode and heapify are all
     * internal modes in bottom up way
	 */
	if (array == NULL || size < 2)
		return;

	for (m = (size - 2) / 2; m >= 0; --m)
		maxHeapify(array, size, m, size);

	/**
	* Repeat the following steps and while the heap size is greater than one.
    * The last elem in maximum heap will be the minimum element
	*/
	for (m = (size - 1); m > 0; --m)
	{
		/**
		* The largest item in Heap is being kept at the root.
		*/
		swap(&array[0], &array[m]);
		print_array(array, size);

		/* Lastly, heapify the root of the tree.*/
		maxHeapify(array, size, 0, m);
	}
}
