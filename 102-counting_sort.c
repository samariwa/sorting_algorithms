#include "sort.h"


void counting_sort(int *array, size_t size)
{
	size_t i;
	int k = 0;
	int *count_array;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}

	count_array = malloc(sizeof(int) * k);
	/** if (count_array == NULL)
	{
		
	} */

	for (i = 0; i < (size_t)k; i++)
	{
		count_array[i] = 0;
	}


	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}

	for (i = 1; i <= (size_t)k; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	for (i = 0; i < (size_t)k; i++)
	{
		printf("%d\n", count_array[i]);
	}

}
