#include "sort.h"
#include <stdio.h>
/**
*_calloc - this is the calloc function
*@nmemb: This is numbre of elemeents
*@size: The bit size of each elemeens
*Return: pointer to the memory assig
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int m = 0;
char *p;

if (nmemb == 0 || size == 0)
return ('\0');
p = malloc(nmemb * size);
if (p == NULL)
return ('\0');
for (m = 0; m < (nmemb * size); m++)
p[m] = '\0';
return (p);
}
/**
* counting_sort - this is the counts_sort
* @array: An array to be sorted
* @size: An array size
*/
void counting_sort(int *array, size_t size)
{
int indx, maximun = 0, *counts = '\0', *tmp = '\0';
size_t m;

if (array == NULL || size < 2)
return;
/* find maximun number */
for (m = 0; m < size; m++)
if (array[m] > maximun)
maximun = array[m];
counts = _calloc(maximun + 1, sizeof(int));
tmp = _calloc(size + 1, sizeof(int));
/* count the array elements */
for (m = 0; m < size; m++)
counts[array[m]]++;
/* get the accumulative values */
for (indx = 1; indx <= maximun; indx++)
counts[indx] += counts[indx - 1];
print_array(counts, maximun + 1);
/* get the new array sorted */
for (m = 0; m < size; ++m)
{
tmp[counts[array[m]] - 1] = array[m];
counts[array[m]]--;
}
/* replace all the old array to new array sorted */
for (m = 0; m < size; m++)
array[m] = tmp[m];
free(tmp);
free(counts);

}
