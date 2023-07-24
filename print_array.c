#include <stdlib.h>
#include <stdio.h>

/**
* print_array - output an array of int
*
* @array: An array to be outpu
* @size: The number of elem in an array
*/
void print_array(const int *array, size_t size)
{
size_t m;
m = 0;
while (array && m < size)
{
if (m > 0)
printf(", ");
printf("%d", array[m]);
++m;
}
printf("\n");
}
