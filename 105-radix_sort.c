#include "sort.h"
#include <stdio.h>
/**
* getMax - The utility function to get maximum value in array
* @arr: An array
* @n: The size of the array
* Return: Always return the array
*/
int getMax(int *arr, int n)
{
	int m, max = arr[0];

	for (m = 1; m < n; m++)
		if (arr[m] > max)
			max = arr[m];
	return (max);
}

/**
* countSort - The function to count the sort of an array
* @arr: An array
* @n: The size of the array
* @exp: The exponentt is 10^m
* @output: The array to save the temporary vals
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int m;
	int count[10] = {0};

	/* Store count of the occurrences in count[] */
	for (m = 0; m < (int)n; m++)
		count[(arr[m] / exp) % 10]++;

	/*
	* Change count[m] so that count[m] now contains actual
    * position of this digit in output[]
	*/
	for (m = 1; m < 10; m++)
		count[m] += count[m - 1];

	/* Build the output array */
	for (m = n - 1; m >= 0; m--)
	{
		output[count[(arr[m] / exp) % 10] - 1] = arr[m];
		count[(arr[m] / exp) % 10]--;
	}

	/*
	* Copy the output array to an array, so that array
	*/
	for (m = 0; m < (int)n; m++)
		arr[m] = output[m];
	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know the number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (array == NULL || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	/*
	* counting the sort for every digit. exponet is 10^m
	*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
