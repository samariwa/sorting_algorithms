#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/*int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
	/*int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};*/
	int array[] = {170, 45, 75, 90, 2, 802, 2, 66, 12};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	merge_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
