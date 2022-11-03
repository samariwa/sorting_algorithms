#include "sort.h"


/**
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	bool to_swap = 1;

	while (to_swap)
	{
		to_swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				to_swap = true;
			}
		}
		
		for(i = 0; i < size; i++)
		{
			printf("%d", array[i]);
			if (i != size - 1)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
	
}
