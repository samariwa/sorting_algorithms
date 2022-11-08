#include "sort.h"
void divide(int *array, size_t size, size_t lower_bound, size_t upper_bound);

/**
 *
 */
void merge_sort(int *array, size_t size)
{
	size_t lower_bound = 0, upper_bound = size - 1;
	divide(array, size, lower_bound, upper_bound);
}

/**
 *
 */
void merge(int *array, size_t size, size_t lower_bound, size_t mid, size_t upper_bound)
{
	size_t i = lower_bound, j = mid + 1, k = lower_bound, l;
	int *sorted_array = malloc(sizeof(int) * size);
	
	while (i <= mid && j <= upper_bound)
	{
		printf("Merging...\n");
		printf("[left]: ");
		for (l = 0; l <= i; l++)
		{
			printf("%d", array[l]);
			if (l != i)
			{
				printf(", ");
			}
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
			if (l != j)
			{
				printf(", ");
			}
		}
		printf("\n");
		if (array[i] < array[j])
		{
			sorted_array[k] = array[i];
			i++;
		}
		else
		{
			sorted_array[k] = array[j];
			j++;
		}
		printf("[Done]: ");
		for (l = 0; l <= k; l++)
		{
			printf("%d", sorted_array[l]);
			if (l != k)
			{
				printf(", ");
			}
		}
		printf("\n");
		k++;
	}

	if (i > mid)
	{
		printf("Merging...\n");
		printf("[left]: ");
		for (l = 0; l <= i; l++)
		{
			printf("%d", array[l]);
			if (l != i)
			{
				printf(", ");
			}
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
			if (l != j)
			{
				printf(", ");
			}
		}
		printf("\n");
		while (j <= upper_bound)
		{
			sorted_array[k] = array[j];
			j++;
			k++;
		}
		printf("[Done]: ");
		for (l = 0; l <= k; l++)
		{
			printf("%d", sorted_array[l]);
			if (l != k)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
	else
	{
		printf("Merging...\n");
		printf("[left]: ");
		for (l = 0; l <= i; l++)
		{
			printf("%d", array[l]);
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
		}
		printf("\n");
		while (i <= mid)
		{
			sorted_array[k] = array[i];
			i++;
			k++;
		}
		printf("[Done]: ");
		for (l = 0; l <= k; l++)
		{
			printf("%d", sorted_array[l]);
			if (l != k)
			{
				printf(", ");
			}
		}
		printf("\n");
	}

	for (k = lower_bound; k <= upper_bound; k++)
	{
		array[k] = sorted_array[k];
	}

	free(sorted_array);
}

/**
 *
 */
void divide(int *array, size_t size, size_t lower_bound, size_t upper_bound)
{
	size_t mid;

	if (lower_bound < upper_bound)
	{
		mid = (upper_bound + lower_bound) / 2;

		divide(array, size, lower_bound, mid);
		divide(array, size, mid + 1, upper_bound);
		merge(array, size, lower_bound, mid, upper_bound);
	}
}
