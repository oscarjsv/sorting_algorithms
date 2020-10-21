#include "sort.h"
/**
 * bubble_sort - sorting algorithm
 * @array: array of numbers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size == 0)
		return;
	for (i = size; i > 0; i--)
	{
		for (j = 0;  j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
