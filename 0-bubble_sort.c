#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * using bubble sort algorithm
 * @array: the array to sort
 * @size: number of elements in the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i = 0, sorted = 1, j, k, temp, len = (int) size;

	for (; i < len; i++)
	{
		/* compare two adjacent elements and swap if necessary */
		for (k = 0, j = 1; j < (len - i) && k < (len - 1 - i); j++, k++)
		{
			if (array[k] > array[j]) /* swap */
			{
				sorted = 0; /* array isn't sorted after all */
				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
				/* print the array after every swap */
				print_array(array, size);
			}
		}
		/* check if a swap happened in 'this' pass - if not, array's sorted */
		if (sorted)
			break;
	}
}

