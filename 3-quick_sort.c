#include "sort.h"
size_t partition(int *array, size_t lower_bound, size_t upper_bound);
void iter_sort(int *array, size_t size,
	       size_t lower_bound, size_t upper_bound);

/**
 * quick_sort - this finction sorts the values of the array passed in as an
 * argument using the quick sort algorithm and prints the result after each
 * iteration of sorting
 * @array: the array who's values are to be sorted
 * @size: the size of the array
 * Description: The function with work together with other helper functions
 * that are also defined in this module
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	/**
	 * declaration of the upper bound and lower bound variables which are
	 * used in defining the start and end of the array partition to be
	 * sorted since the algorithm uses a divide and conquer approach
	 */
	size_t lower_bound = 0;
	size_t upper_bound = size - 1;

	iter_sort(array, size, lower_bound, upper_bound);
}

/**
 * iter_sort - this is a helper function that iterates through
 * the process of partitioning and sorting the array segemnts
 * @array: the array to be sorted
 * @size: the size of the full array regardless of partitioning or not
 * @lower_bound: the start of the segment of the array to be sorted
 * @upper_bound: the end of the segment of the array to be sorted
 *
 * Return: Nothing
 */
void iter_sort(int *array, size_t size, size_t lower_bound, size_t upper_bound)
{
	if (lower_bound < upper_bound)
	{
		size_t k, location = partition(array, lower_bound, upper_bound);

		/**
		 * The recursive functions being called and actioning on each
		 * of the partitioned array
		 */
		iter_sort(array, size, lower_bound, location - 1);
		iter_sort(array, size, location + 1, upper_bound);

		/* Printing state of the array after each round of sorting */
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

/**
 * partition - this is the function that partitions the array
 * @array: the array to be partitioned
 * @lower_bound: the start of the array to be partitioned
 * @upper_bound: the end of the array to be partitioned
 * Description: This partitioning is done by placing a value in its correct
 * position and placing all the values less that it on its left side of the
 * array and all the values greater than it on the right side. This forms the
 * basis of divide and conquer that will help in sorting smaller chunks rather
 * that an entire array at once
 *
 * Return: The index of the pivot element after partitioning
 */
size_t partition(int *array, size_t lower_bound, size_t upper_bound)
{
	size_t pivot_index = lower_bound;
	int temp;

	/**
	 * The movement of the bound pointers should be done only if the
	 * lower bound is at a lower index of the array than the upper bound
	 */
	while (lower_bound < upper_bound)
	{
		/**
		 * The lower bound should move to the right only if the
		 * corresponding value of the index is less than the pivot
		 * element value. Likewise the upper bound should move back
		 * to the left only if the corresponding value is greater than
		 * the pivot value
		 */
		while (array[lower_bound] <= array[pivot_index])
		{
			lower_bound++;
		}

		while (array[upper_bound] > array[pivot_index])
		{
			upper_bound--;
		}
		/**
		 * After getting to a point where the conditions are not met,
		 * swap the lower bound value and the upper bound value
		 */
		if (lower_bound < upper_bound)
		{
			temp = array[lower_bound];
			array[lower_bound] = array[upper_bound];
			array[upper_bound] = temp;
		}
	}
	/**
	 * After exiting the while loop due to the lower bound and upper bound
	 * passing each other poition wise, swap the pivot value with the upper
	 * bound value and exit the function by returning the position of the
	 * newly placed pivot
	 */
	temp = array[upper_bound];
	array[upper_bound] = array[pivot_index];
	array[pivot_index] = temp;

	return (upper_bound);
}
