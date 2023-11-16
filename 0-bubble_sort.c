#include "sort.h"

/**
 * bubble_sort - fct sorts array of integer in ascending way
 * @array: the array of integers
 * @size: the size of the array
 * Return: empty
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, nbr_pass;
	int garage;

	if (!array || !size)
		return;

	nbr_pass = 0;
	while (nbr_pass <= size - 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				garage = array[i];
				array[i] = array[i + 1];
				array[i + 1] = garage;
				print_array(array, size);
			}
		}
		nbr_pass++;
	}
}
