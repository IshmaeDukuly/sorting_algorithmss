#include "sort.h"

/**
*swap - The swap positions
*@array: An array
*@item1: array ele
*@item2: An array ele
*/
void swap(int *array, int item1, int item2)
{

int tmp;

tmp = array[item1];
array[item1] = array[item2];
array[item2] = tmp;
}
/**
* shell_sort - this is function that sorts an array of integers
* orderly using the Shell sort algorithm Method,
* @size: size of the array
* @array: The list numbers
*/
void shell_sort(int *array, size_t size)
{
size_t gp = 1, m, indx = 0;

if (array == NULL || size < 2)
return;
while (gp < size / 3)
gp = 3 * gp + 1;
while (gp >= 1)
{
for (m = gp; m < size; m++)
for (indx = m; indx >= gp &&
(array[indx] < array[indx - gp]); indx -= gp)
swap(array, indx, indx - gp);
print_array(array, size);
gp /= 3;
}
}
