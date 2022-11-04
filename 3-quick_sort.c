#include "sort.h"
size_t partition(int *array, size_t lower_bound, size_t upper_bound);
void iter_sort(int *array, size_t size, size_t lower_bound, size_t upper_bound);

/**
 *
 *
 */
void quick_sort(int *array, size_t size)
{
	size_t lower_bound = 0;
	size_t upper_bound = size - 1;
	iter_sort(array, size, lower_bound, upper_bound);
}

/**
 *
 *
 */
void iter_sort(int *array, size_t size, size_t lower_bound, size_t upper_bound)
{
	if (lower_bound < upper_bound)
	{
		size_t k, location = partition(array, lower_bound, upper_bound);

		iter_sort(array, size, lower_bound, location - 1);
		iter_sort(array, size, location + 1, upper_bound);

		for(k = 0; k < size; k++)
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

/**
 *
 *
 */
size_t partition(int *array, size_t lower_bound, size_t upper_bound)
{
	size_t pivot_index = lower_bound;
	int temp;

	while (lower_bound < upper_bound)
	{
		while (array[lower_bound] <= array[pivot_index])
		{
			lower_bound++;
		}

		while (array[upper_bound] > array[pivot_index])
		{
			upper_bound--;
		}
		
		if (lower_bound < upper_bound)
		{
			temp = array[lower_bound];
			array[lower_bound] = array[upper_bound];
			array[upper_bound] = temp;
		}
	}
	temp = array[upper_bound];
	array[upper_bound] = array[pivot_index];
	array[pivot_index] = temp;

	return (upper_bound);
}
