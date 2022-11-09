#include "sort.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of the new pointer.
 * Return: Nothing
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	int *int_ptr = (int *)ptr;
	int *int_newptr = (int *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		int_newptr[i] = int_ptr[i];
}

/**
 * get_range - returns the upperbound of integers in an array
 * @array: the array from which to get range
 * @size: the number of elements in the array
 * Return: the upperbound
 */
int get_range(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max + 1);
}

/**
 * actual_counting_sort - sorts an array in ascending order using
 * the (non-comparative) linear algorithm, Counting Sort
 * Description: uses 3 arrays, an input, output & temporary storage
 * array. The temporary storage array (of size:
 * k = max integer in array + 1) holds first, the count of each integer
 * in input array (how many times it appears) and is updated, in place
 * to hold the position(ing) of said integers.
 * temporary_array[i] holds [i] + [i - 1] i.e. all the count of all the
 * elements up to that position.
 * @array: the array to sort
 * @n: size of the array
 * @temp: array to hold the values in the process
 * @K: the range of integers in the array to sort
 */
void actual_counting_sort(int *array, int n, int *temp, int K)
{
	int *count_array, i, j;

	/* dynamically allocate memory to temp array */
	count_array = malloc(sizeof(int) * K);
	if (count_array == NULL)
		return; /* malloc failed */
	/* complexity == O(K) */
	for (i = 0; i < K; i++)
		count_array[i] = 0; /* initialize the temp array of size K */
	/* complexity == O(n) */
	for (j = 0; j < n; j++)
	{
		/* array[j] == int element @ [j], increment its count */
		count_array[array[j]] = count_array[array[j]] + 1;
	}
	/* count_array[i] now contains the number of elements equal to i */
	/* complexity == O[K] */
	for (i = 1; i < K; i++)
	{
		/* current + all prev elements: gives position of I elem */
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	/* count_array[i] now contains the number of elements <= i */
	print_array(count_array, K);
	/* complexity == O(n) */
	for (j = n - 1; j >= 0; j--)
	{
		/*sub 1 since positioning starts @ 1 (not 0), its based on count */
		count_array[array[j]] = count_array[array[j]] - 1;
		temp[count_array[array[j]]] = array[j];
	}
	/* temp[] now contains the sorted elements of array[] */
	free(count_array); /* free temp array - no longer needed */
}

/**
 * counting_sort - sorts elements of an array using the linear algorithm,
 * Counting Sort (which's also a stable sorting algorithm)
 * @array: the array to sort
 * @size: the number of elements in the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int k, *output;

	/* check that array is defined and of size > 1 */
	if (!array || size < 2)
		return; /* array undefined, empty or of size 1 */
	/* (else) get k == max element in array + 1*/
	k = get_range(array, size);
	/* dynamically allocate memory (size k) to output array */
	output = malloc(sizeof(int) * k); /* will hold the sorted values */
	/* check that malloc didn't fail */
	if (output == NULL)
		return; /* malloc failed */
	/* call actual_counting_sort */
	actual_counting_sort(array, size, output, k);
	/* copy output into array */
	_memcpy(array, output, size);
	free(output); /* frees the dynamically allocated space */
}
