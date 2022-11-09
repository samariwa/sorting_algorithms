#include "sort.h"

/**
 * print_array_ - prints an array
 * @array: the array to print
 * @start: starting (beginning) index
 * @end: ending index (inclusive)
 * Return: Nothing
 */
void print_array_(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i < end)
			printf("%d ", array[i]);
		else
			printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * swap_ - swaps two elements of an array at a given
 * comparator distance from each other (i.e. the two corresponding
 * elements of 2 halves (bitonic sequences) if the first's is > (
 * or <) the second based on desired order(ascending in former case)
 * @array: array being sorted
 * @idx_0: first sequence's element index
 * @idx_1: second sequence's element (corresponding) index
 * @order: order of sorting/swapping
 * Return: Nothing
 */
void swap_(int *array, int idx_0, int idx_1, int order)
{
	int temp;

	/* if elements are out of (desired) order */
	if (order == (array[idx_0] > array[idx_1]))
	{
		temp = array[idx_0];
		array[idx_0] = array[idx_1];
		array[idx_1] = temp;
	}
}

/**
 * merge - merges two (bitonic, currently being worked on) sequences
 * Description: recursively divides the current sequence into 2, until
 * each sequence is made up of a single element(base case), compares
 * the sequences (in swap, & swaps if out of (desired) order) and
 * merges resulting (compared & swapped) sequences into one sequence
 * @array: the array being sorted
 * @start: the starting (beginning) index
 * @size: number of elements (size) of the array
 * @order: the desired order (ascending/descending) of sorting
 * @a_sz: no of elements in original array
 * Return: Nothing (works on the array in-place)
 */
void merge(int *array, int start, int size, int order, int a_sz)
{
	int k, i;

	/* check that current sequence is of size > 1: else sorted */
	if (size > 1)
	{
		k = size / 2; /* size = size of half (sequence) */
		for (i = start; i < start + k; i++)
		{
			swap_(array, i, i + k, order);
		}
		/* merge first half - by further dividing & comparing */
		merge(array, start, k, order, a_sz);
		/* merge second half - by repeating the process */
		merge(array, start + k, k, order, a_sz);
	}

}

/**
 * actual_bitonic_sort - is the actual bitonic sort algorithm
 * recursively sorting the array (as described in bitonic_sort)
 * @array: the array to sort
 * @start:the index to start at
 * @size: no of elements in current sequence
 * @a_sz: no of elements in original array
 * @order: the sorting order (ascending/descending)
 * Return: Nothing
 */
void actual_bitonic_sort(int *array, int start, int size, int order, int a_sz)
{
	int k;
	static int twos = 0;

	/* check that the array has more than one elements (else sorted) */
	if (size > 1)
	{
		k = size / 2; /* divide the array into 2 halves */
		/* sort the first half in ascending order */
		actual_bitonic_sort(array, start, k, 1, a_sz);
		/* sort the second half in descending order */
		actual_bitonic_sort(array, start + k, k, 0, a_sz);
		/**
		 * merge the (halves) in desired (ascending) order 
		 * print starting sequences (as is) before merge
		 * & the result (merged sequence) after
		 */
		if (twos > 3)
			twos = 0;
		if (twos <= 1 || size != 2)
		{
			printf("Merging [%d/%d] (%s):\n", size, a_sz, order == 0 ? "UP" : "DOWN");
			if (order == 1) /* ascending order case */
				print_array_(array, start, size - 1);
			else /* descending order case (2nd half of sequences) */
				print_array_(array, size, size * 2 - 1);
		}
		merge(array, start, size, order, a_sz);
		if (twos <= 1 || size != 2)
		{
			printf("Result [%d/%d] (%s):\n", size, a_sz, order == 0 ? "UP" : "DOWN");
			if (order == 1) /* ascending order case */
				print_array_(array, start, size - 1);
			else /* descending order case (2nd half of sequences) */
				print_array_(array, size, size * 2 - 1);
		}
		if (size == 2)
			twos++;

	}
}


/**
 * bitonic_sort - sorts an array using Bitonic sort algorithm
 * Description: sorting in ascending order, bitonic sort is a
 * parallel algorithm and works for arrays/collections of power of
 * 2 elements i.e. (2^n) size.
 * Works by first converting the random data (in array) into a bitonic
 * sequence, a sequence of first increasing and then decreasing elements
 * (before and after an index i) i.e. array[0...(i - 1)] <= array[i] &
 * array[(i + 1)...(n-1)] <= array[i]. This' achieved through recursive
 * swaps, starting with sequences of 2, then 4, and so on elements
 * @array: the collection of random elements
 * @size: the number of elements in array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1; /* i.e. sort in ascending order */

	/* call sort method */
	actual_bitonic_sort(array, 0, (int)size, order, size);
}
