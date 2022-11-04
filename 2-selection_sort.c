#include "sort.h"

/**
 * smallest - returns the position (index)
 * of the smallest integer in an array starting
 * at index, pos
 * @arr: the array in which to look
 * @pos: the starting lookup index
 * @size: the size of the array
 * Return: an integer index (position)
 */
int smallest(int *arr, int pos, int size)
{
	int i, min = arr[pos], min_pos = pos;

	for (i = pos + 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_pos = i;
		}
	}
	/*printf("min: %d at [%d]\n", min, min_pos);*/
	return (min_pos);
}

/**
 * selection_sort - sorts an array of integers in ascending
 * order using selection sort algorithm
 * (continuously swap the smallest value with the net unsorted
 * element in array)
 * @arr: the array of integers to sort
 * @size_: number of elements in array
 * Return: Nothing
 */
void selection_sort(int *arr, size_t size_)
{
	int i, min_pos, temp, size = (int)size_;

	for (i = 0; i < size; i++)
	{
		min_pos = smallest(arr, i, size);
		/* swap if necessary */
		if (min_pos > i)
		{
			temp = arr[i];
			arr[i] = arr[min_pos];
			arr[min_pos] = temp;
			/* print the array after swapping */
			print_array(arr, size);
		}
	}
}
