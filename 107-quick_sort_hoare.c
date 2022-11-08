#include "sort.h"


/**
 * swap - swaps two elements of an array
 * @array: the array
 * @pos1: the first index (element to swap)
 * @pos2: the second index (element to swap)
 * Return: Nothing
 */
void swap(int *array, int pos1, int pos2)
{
	int temp;

	/* dont swap the same element */
	if (pos1 == pos2)
		return;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
}

/**
 * hoare_partition - partions an array using Hoare's scheme
 * Description: typically takes the first element, array[lowerbound]
 * to be the pivot element. Does NOT place the pivot element at its
 * sorted (correct) position. The pivot is therefore included in
 * first subarray (of the 2 resulting) in re-partioning
 * Required: pivot should always be the last element...
 * @array: the array to partion
 * @lowerbound: the first index in (sub)array
 * @upperbound: the last index in (sub)array
 * @size: number of elements in array
 * Return: the pivot's index after partion, which's end position
 */
int hoare_partition(int *array, int lowerbound, int upperbound, size_t size)
{
	int start = lowerbound - 1, end = upperbound + 1, pivot;

	/* swap a[lowerbound] with a[upperbound], pivot = array[upperbound] */
	swap(array, upperbound, lowerbound);
	/*print_array(array, size);*/
	pivot = array[lowerbound]; /* i.e. array[initial upperbound] */
	/*printf("pivot: [%d] -> %d\n", upperbound, pivot);*/
	while (1) /* infinitely loop */
	{
	/* advance start towards end */
		do
			start++;
		while (array[start] < pivot);
	/* advance end towords start */
		do
			end--;
		while (array[end] > pivot);
	/* if a cross (start >= end), return end */
		if (start >= end)
			return (end);
	/* if inversion, swap the elements at start & end */
		swap(array, start, end);
		/* print array after each swap */
		print_array(array, size);
	}
}

/**
 * actual_quick_sort - actually sorts the array
 * @array: the array to sort
 * @left: start index
 * @right: last(stop) index
 * @size: size of array
 * Return: Nothing
 */
void actual_quick_sort(int *array, int left, int right, size_t size)
{
	int loc;

	/* base case, array size == 0 or 1 (sorted) */
	if (left >= right)
		return; /* done with sorting */
	/* sort part of the array as partitioned */
	loc = hoare_partition(array, left, right, size);
	/*printf("loc: [%d] -> %d\n", loc, array[loc]);*/
	/* sort the left part of array: 0 - pivot/loc */
	actual_quick_sort(array, left, loc, size);
	/* sort the second partition: loc + 1, right */
	actual_quick_sort(array, loc + 1, right, size);
}

/**
 * quick_sort_hoare - sorts an array in ascending order using
 * Hoare's partition scheme'd QuickSort.
 * @array: the array to sort
 * @size: is the size of the array (number of elements)
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	int left = 0, right = (int)size - 1;

	/* sort */
	actual_quick_sort(array, left, right, size);
}
