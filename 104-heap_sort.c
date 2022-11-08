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
 * create_heap - creates a heap instance
 * @capacity: the initial capacity of instantiated heap
 * Return: pointer to the heap instance
 */
heap_t *create_heap(int capacity)
{
	heap_t *new;

	/* allocate memory to the heap instance */
	new = malloc(sizeof(heap_t));
	/* check if memory allocation was successful */
	if (new == NULL)
		return (NULL); /* malloc failed */
	/* (else,) initialize heap elements */
	new->capacity = capacity;
	/* allocate memory to array to hold capacity integer elems */
	new->array = malloc(sizeof(int) * capacity);
	if (new->array == NULL)
		return (NULL); /*malloc failed */
	new->count = 0; /* heap has zero elements currently */
	return (new);
}

/**
 * siftDown - recursively places a node in its right location
 * relative to its children nodes to maintain the heap property.
 * Description: heap property -> depending on type of heap (max or min)
 * the parent node (for max) must be greater than its children.
 * Leaf nodes are therefore the least elements in a given path
 * Heapifying is achieved by recursively swapping the node with its
 * max child until order in order (heap property achieved)
 * @heap: the heap to heapify (i.e. maintain heap property for)
 * @index: the index of the node to heapify (if out of order, meaning
 * for the case of max heap, the node is less than one or more of its
 * descendants)
 * @size: size of array (purely for use with print_array after swap)
 * Return: Nothing
 */
void siftDown(heap_t *heap, int index, int size)
{
	int left, right, max;

	/* get the children of the [index] node */
	left = (2 * index) + 1;
	/* check left is within bounds of heap->array */
	if (left >= heap->count)
		left = -1; /* out of bounds, hence not a child */
	right = (2 * index) + 2;
	/* check right is within bounds of heap->array */
	if (right >= heap->count)
		right = -1; /* out of bounds, hence not a child */
	/* check that the children are valid (not -1) */
	if (left != -1 && heap->array[left] > heap->array[index])
		max = left; /* track max index */
	else /* left is either -1 or [left] < [index] -> can't swap */
		max = index;
	if (right != -1 && heap->array[right] > heap->array[max])
		max = right;
	/*printf("in siftDown: max = %d & index (%d)\n", max, index);*/
	if (max != index) /* need to swap node with (max) child */
	{
		swap(heap->array, max, index);
		/* print array after every swap */
		print_array(heap->array, size); /* count changes, pass size to fn */
		siftDown(heap, max, size); /* Repeat until heap property achieved */
	}
}

/**
 * build_heap - heapifies an array (builds a heap from an
 * array of elements)
 * Description: the key is to find the last elemnt's (last leaf)
 * parent and heapify from there as leaf nodes always satisfy the heap
 * property (they have no children to compare with)
 * @heap: an empty heap to populate with array elements
 * @array: the array to be heapified
 * @size: the number of elements in array (array size)
 * Return: Nothing
 */
void build_heap(heap_t *heap, int *array, int size)
{
	int i;

	/* check that heap exists */
	if (heap == NULL)
		return; /* no heap to heapify array */
	/* copy array elements int heap->array */
	for (i = 0; i < size; i++)
		heap->array[i] = array[i];
	/* update heap count to size */
	heap->count = size;
	/* heapify array (heap) - starting at last element's parent */
	for (i = (size - 1) / 2; i >= 0; i--) /* i = parent(heap, size-1)*/
		siftDown(heap, i, (int)size);
}

/**
 * heap_sort - sorts an array (in place) using a heap
 * Description: heapifies array, swaps the root (max element)
 * with the last element in array, heapifies new array of size--
 * and repeats until size = 1 in which case the array is sorted in
 * ascending order (smallest element first)
 * @array: the array to heap sort
 * @size: the number of elements in array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, old_size;

	/* create a heap of capacity size within which to array sort */
	heap_t *heap = create_heap((int)size);
	/* if heap is created: heapify array */
	if (heap != NULL)
	{
		build_heap(heap, array, (int)size);
		old_size = heap->count;
		/*printf("heap built (max value should be at root): ");*/
		print_array(heap->array, size); /*print heap->array (that's the sorted)?*/
		/* to sort the array: starting with root & last elem */
		for (i = (int)size - 1; i > 0; i--)
		{
			/* once array is 'heapified', root is max elem */
			swap(heap->array, 0, i); /* root with last elem */
			/* print array after swap */
			print_array(heap->array, size);
			heap->count -= 1;
			siftDown(heap, 0, (int)size); /* heapify heap from root */
		}
		/* restore heap->count once done */
		heap->count = old_size;
		/* copy heap->array (now sorted) into array */
		for (i = 0; i < (int)size; i++)
			array[i] = heap->array[i];
		/* delete heap once done - to free allocated memory */
		free(heap->array);
		free(heap);
	}
}

