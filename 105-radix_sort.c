#include "sort.h"

/**
 * get_largest - returns the largest elemnt in array
 * @array: the array to search
 * @size: the number of elemnts in array
 * Return: the largest integer
 */
int get_largest(int *array, size_t size)
{
	int i, max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}


/**
 * free_grid - frees up a 2d grid
 * @grid: double pointer to 2d grid
 * @height: height of grid
 * Return: nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]); /* free row in grid */
	free(grid); /* free actual grid */
}

/**
 * alloc_grid - creates a 2d integer grid
 * Description: Each element of the grid should be initialized to 0
 * @width: int size width of array
 * @height: int size height of array
 * Return: Pointer to new grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width + height < 2 || width < 1 || height < 1)
		return (NULL); /* cant be a 2d array (contains <= 1 rows */

	/*grid is a pointer to pointers (double pointer) - an array of arrays */
	/*i.e. it is a pointer to 1D arrays (sorta like single rows) in 2D arrays*/
	grid = malloc(height * sizeof(*grid));
	/*total size = size of pointer (array):(int *) * height (no of arrays/rows) */
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		/*now assign memory to individual arrays/rows;*/
		grid[i] = malloc(width * sizeof(**grid));
		/* **grid is the value of array elements (type = type of element) */
		if (grid[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(grid[i]);/* free row/ array */
			free(grid);/* free 2D array */
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;/* initialize the arrays/rows */
	}

	return (grid);
}

/**
 * radix_sort - sorts elements of an array in ascending order
 * Description: arranges the elements in buckets (0 - 9) on the basis
 * of the pass-th digit (0 -> k - 1) in elements.
 * the number of passes = the number of digits in the largest element
 * of the array
 * After every pass, the array is rearranged (the buckets are collected)
 * in the newly attained order
 * @array: the array to sort
 * @size: the number of elements in the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int **buckets, *bucket_count, i, j, k, mod, passes = 0, max, pass, div = 1;

	/* get the largest number in array */
	max = get_largest(array, size);
	/* calculate the number of passes based on largest number */
	while (max > 0)
	{
		passes++;
		max /= 10; /* get number of digits in max */
	} /* dynamically allocate memory to temp arrays */
	bucket_count = malloc(sizeof(int) * (int)size); /* as many as size values */
	buckets = alloc_grid(10, (int)size); /* width(0->9) by height(rows/size) */
	if (bucket_count == NULL || buckets == NULL)
		return; /* malloc failed */
	/* sort: starting from least significant digit */
	for (pass = 0; pass < passes; pass++)
	{ /* initialize bucket_count (tracks elements (count) in bucket) */
		for (i = 0; i < 10; i++)
			bucket_count[i] = 0;
		/* sort elements according to the pass-th digit (into buckets) */
		for (i = 0; i < (int)size; i++)
		{
			mod = (array[i] / div) % 10; /* the pass-th digit */
			buckets[mod][bucket_count[mod]] = array[i];
			bucket_count[mod] += 1;
		} /* collect the buckets (rearrange array with bucket elements) */
		i = 0; /* start at array[0] */
		for (k = 0; k < 10; k++)
		{ /* collect all elements in bucket k */
			for (j = 0; j < bucket_count[k]; j++)
			{
				array[i] = buckets[k][j];
				i++;
			}
		} /* repeat until most significant digit (last pass) */
		print_array(array, size); /* print array after every pass */
		div *= 10; /* for next least significant digit -> most significant */
	} /* free all dynamically allocated memory */
	free(bucket_count);
	free_grid(buckets, 10);
}
