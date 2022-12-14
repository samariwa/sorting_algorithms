#include "sort.h"
void dividev2(int *array, size_t size, size_t lower_bound, size_t upper_bound);

/**
 * merge_sortv2 - the main function for this mdule thst calls the divide func
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 *
 * Return: nothing
 */
void merge_sortv2(int *array, size_t size)
{
	size_t lower_bound = 0, upper_bound = size - 1;

	dividev2(array, size, lower_bound, upper_bound);
}

/**
 * mergev2 - function that merges the sorted array chunks
 * @array: the array being sorted
 * @size: the size of the array
 * @lower_bound: the index of the first value of the array
 * @mid: the index of the value dividing the array in halves
 * @upper_bound: the index of the last value of the array
 *
 * Return: nothing
 */
void mergev2(int *array, size_t size, size_t lower_bound,
		size_t mid, size_t upper_bound)
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
				printf(", ");
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
			if (l != j)
				printf(", ");
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
				printf(", ");
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
				printf(", ");
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
			if (l != j)
				printf(", ");
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
				printf(", ");
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
			if (l != i)
                                printf(", ");
		}
		printf("\n");
		printf("[right]: ");
		for (l = 0; l <= j; l++)
		{
			printf("%d", array[l]);
			if (l != j)
                        	printf(", ");
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
				if (l != j)
					printf(", ");
			}
		}
		printf("\n");
	}

	for (k = lower_bound; k <= upper_bound; k++)
		array[k] = sorted_array[k];

	free(sorted_array);
}

/**
 * divide - function that divides the array into cunks for sorting
 * @array: the array to be sorted
 * @size: the size of the array
 * @lower_boud: the index of the first value of a chunk
 * @upper_bound: the index of the last value of a chunk
 *
 * Return: nothing
 */
void divide(int *array, size_t size, size_t lower_bound, size_t upper_bound)
{
	size_t mid;

	if (lower_bound < upper_bound)
	{
		mid = (upper_bound + lower_bound) / 2;

		dividev2(array, size, lower_bound, mid);
		dividev2(array, size, mid + 1, upper_bound);
		mergev2(array, size, lower_bound, mid, upper_bound);
	}
}
