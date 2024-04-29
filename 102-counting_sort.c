#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array, and initializes it with zero.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to the allocated memory, or NULL if allocation fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i;
    char *p;

    if (nmemb == 0 || size == 0)
        return (NULL);

    p = malloc(nmemb * size);
    if (p == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        p[i] = '\0';

    return (p);
}

/**
 * counting_sort - Sorts an array of integers using the Counting Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *tmp;
	int index, maximum = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find maximum number in the array*/
	for (i = 0; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	counter = _calloc(maximum + 1, sizeof(int));
	tmp = _calloc(size, sizeof(int));
	if (counter == NULL || tmp == NULL)
	{
		free(counter);
		free(tmp);
		return;
	}

	for (i = 0; i < size; i++)
	{
		counter[array[i]]++;
	}

	/* Get cumulative counts*/
	for (index = 1; index <= maximum; index++)
	{
		counter[index] += counter[index - 1];
	}

	/* Sort the array based on counts*/
	for (i = 0; i < size; i++)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/*Copy sorted elements back to original array*/
	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}

	/*Print the sorted array*/
	print_array(array, size);

	/*Free allocated memory*/
	free(counter);
	free(tmp);
}
