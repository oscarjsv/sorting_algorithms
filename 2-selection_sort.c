#include "sort.h"
/**
 * selection_sort - selection
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{

	size_t i, j, selected, temp_min, idx_min, temp;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		selected = temp_min = array[i];
		idx_min = 0;
		for (j = i + 1; j < size; j++)
		{
			if (selected > (size_t)array[j])
			{
				if ((size_t)array[j] < selected)
				{
					if ((size_t)array[j] < temp_min)
					{
						temp_min = array[j];
						idx_min = j;
					}
				}
				selected = array[j];
			}
		}

		if (selected != (size_t)array[i])
		{
			/*swapp*/
			temp = array[idx_min];
			array[idx_min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}

	}
}
