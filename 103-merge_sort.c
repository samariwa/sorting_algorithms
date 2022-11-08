#include <stdio.h>
#include <stdlib.h>

/**
 * print_sub_arrays - prints the parts of the array currently
 * being worked on
 * @array: the original array
 * @start: the start index
 * @mid: the mid index
 * @end: the end index (inclusive)
 */
void print_sub_arrays(int *array, int start, int mid, int end)
{
	int k, j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = start; k < mid; k++)
		printf("%d ", array[k]);
	printf("\n");
	printf("[right]: ");
	for (k = j; k < end; k++)
		printf("%d ", array[k]);
	printf("\n");
}

/**
 * copy_merged - copies the merged sub_arrays into the original
 * Also prints the sorted (& merged) sub-array, temp
 * @array: the original
 * @temp: the  sorted array of merged sub-arrays
 * @start: the beginning of first (left) sub-array
 * @index: the last index in temp (inclusive)
 */
void copy_merged(int *array, int *temp, int start, int index)
{
	int k;

	printf("[Done]: ");
	for (k = start; k < index; k++)
	{
		array[k] = temp[k];
		if (k < index - 1)
			printf("%d, ", array[k]);
		else
			printf("%d", array[k]); /* last element */
	}
	printf("\n");
}

/**
 * merge - merges two sorted sub-arrays
 * Description: Left source half is A[ iBegin:iMiddle-1]
 * Right source half is A[iMiddle:iEnd-1 ] &
 * Result is B[ iBegin:iEnd-1 ]
 * @array: holds the sorted elements
 * @temp: holds the sorted elements
 * @iBegin: 0th index
 * @iMiddle: the middle index
 * @iEnd: last index in array
 * Return: Nothing
 */
void merge(int *array, int iBegin, int iMiddle, int iEnd, int *temp)
{
	int i = iBegin, j = iMiddle, k, h;

	/* While there are elements in the left or right runs... */
	print_sub_arrays(array, iBegin, iMiddle, iEnd);
	for (k = iBegin; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head. */
		if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
		{
			temp[k] = array[i];
			i = i + 1;
		}
		else
		{
			temp[k] = array[j];
			j = j + 1;
		}
	}
	/* print sorted & merged sub_array (B) */
	printf("[Done]: ");
	for (h = iBegin; h < k; h++)
	{
		if (h < k - 1)
			printf("%d, ", temp[h]);
		else
			printf("%d", temp[h]); /* last element */
	}
	printf("\n");
}

/**
 * actual_merge_sort - does the actual merge sorting
 * Description: Split A[] into 2 runs, sort both runs into B[],
 * merge both runs from B[] to A[]
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set)
 * @array: the array to be sorted
 * @temp: the array to be sorted
 * @iBegin: the 0th index of (sub)array
 * @iEnd: the last (exclusive) index of the (sub)array
 * Return: Nothing
 */
void actual_merge_sort(int *temp, int iBegin, int iEnd, int *array)
{
	int iMiddle;

	if (iEnd - iBegin <= 1) /* if run size == 1 */
		return; /* sorted */
	/* split the run longer than 1 item into halves */
	iMiddle = (iEnd + iBegin) / 2; /* iMiddle = mid point */
	/* recursively sort both runs from array into temp */
	actual_merge_sort(array, iBegin, iMiddle, temp); /*sort the left run*/
	actual_merge_sort(array, iMiddle, iEnd, temp); /*sort the right run*/
	/* merge the resulting runs from array temp into array*/
	merge(temp, iBegin, iMiddle, iEnd, array);
}

/**
 * merge_sort - sorts elements aof an array using Merge Sort algorithm
 * Description:
 * @array: the array to sort
 * @size: number of elements in the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp, i;

	/* allocate memory to temporary working array */
	temp = malloc(sizeof(int) * (int)size);
	/* check that malloc succeeds */
	if (temp == NULL)
		return; /* malloc failure */
	/* copy elements of array into temp -> one time copy */
	for (i = 0; i < (int)size; i++)
		temp[i] = array[i];
	/* sort elements from temp int array */
	actual_merge_sort(temp, 0, (int)size, array);
	/* free temp once done */
	free(temp);
}

