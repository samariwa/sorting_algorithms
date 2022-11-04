#include "sort.h"


/**
 * selection_sort_v2 - Just another way of implementing the insertion sort
 * algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: Nothing
 */
void selection_sort_v2(int *array, size_t size)
{
	int min_value, start_value, min_index;
	size_t i, j, k;


	for (i = 0; i < size; i++)
	{
		start_value = min_value = array[i];
		min_index = i;
		for (j = i; j < size ; j++)
		{
			if (array[j] <= min_value)
			{
				min_value = array[j];
				min_index = j;
			}
			if (j == (size - 1))
			{
				array[i] = min_value;
				array[min_index] = start_value;
			}
		}

		for (k = 0; k < size; k++)
		{
			printf("%d", array[k]);
			if (k != size - 1)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
}
