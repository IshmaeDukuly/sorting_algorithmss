#include "sort.h"
/**
* selection_sort - function that sorts an array of integers
* orderly using the sort algorithm method
* @size: An array size
* @array: The numbers
*/
void selection_sort(int *array, size_t size)
{
size_t m, indx;
int tmp, swap, flag = 0;

if (array == NULL)
return;
for (m = 0; m < size; m++)
{
tmp = m;
flag = 0;
for (indx = m + 1; indx < size; indx++)
{
if (array[tmp] > array[indx])
{
tmp = indx;
flag += 1;
}
}
swap = array[m];
array[m] = array[tmp];
array[tmp] = swap;
if (flag != 0)
print_array(array, size);
}
}
