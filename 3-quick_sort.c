#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @array: the array
 * @pos1: the first index (element to swap)
 * @pos2: the second index (element to swap)
 * @size: size of array
 * Return: Nothing
 */
void swap(int *array, int pos1, int pos2, size_t size)
{
	int temp;

	/* dont swap the same element */
	if (pos1 == pos2)
		return;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;
    /* print array after swap */
	print_array(array, size);
}

/**
 * lomuto_partition - partions an array using Lomuto's scheme
 * Description: typically takes the last element, array[upperbound]
 * to be the pivot element. Places the pivot element at its
 * sorted (correct) position. The pivot is therefore left
 * out of the subarrays that result (in re-partioning)
 * @array: the array to partion
 * @lowerbound: the first index in (sub)array
 * @upperbound: the last index in (sub)array
 * @size: size of array
 * Return: the pivot's index after partion
 */
int lomuto_partition(int *array, int lowerbound, int upperbound, size_t size)
{
	int curr, j = lowerbound, pivot = array[upperbound];

	for (curr = j - 1; j < upperbound; j++)
	{
		/* check if array[j] <= pivot (an inversion), swap if true */
		if (array[j] <= pivot)
		{ /* increment curr, swap array[curr] with array[j] */
			curr++;
			swap(array, curr, j, size);
		}
	}
	/* correctly position pivot: swap curr & upperbound elems */
	swap(array, curr + 1, upperbound, size);
	return (curr + 1);
}

/**
 * actual_quick_sort - actually sorts the array
 * @array: the array to sort
 * @left: start index
 * @right: last(stop) index
 * @pivot: the basis of comparison/ partition
 * @size: size of array
 * Return: Nothing
 */
void actual_quick_sort(int *array, int left, int right, int pivot, size_t size)
{
	int loc;

	/* base case, array size == 0 or 1 (sorted) */
	if (left >= right)
		return; /* done with sorting */
	/* sort part of the array as partitioned */
	/*loc = partition(array, left, right, pivot, size);*/
	loc = lomuto_partition(array, left, right, size);
	/* sort the first partition */
	actual_quick_sort(array, left, loc - 1, pivot, size);
	/* sort the second partition */
	actual_quick_sort(array, loc + 1, right, loc + 1, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: pointer to the array to be sorted
 * @size: number of elements in the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int left, pivot = 0, right = ((int)size - 1);

	left = pivot;
	actual_quick_sort(array, left, right, pivot, size);
}
