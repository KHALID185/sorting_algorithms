#include "sort.h"

/**
 * max_gap - maximum of the gap
 * @sz: size of array
 * Return: size of gap
*/
size_t max_gap(size_t sz)
{
	size_t k;

	k = 1;
	while (k < sz)
	{
		k = k * 3 + 1;
	}
	return ((k - 1) / 3);
}

/**
 * shell_sort - sorts array of in using shell sort knuth sequence
 * @array: pointer to the first element
 * @size: size of the array
 * Return: empty
*/
void shell_sort(int *array, size_t size)
{
	size_t gp, iter_1, iter_2;
	int garage;

	if (!array || !size)
		return;
	for (gp = max_gap(size); gp > 0; gp = (gp - 1) / 3)
	{
		for (iter_1 = gp; iter_1 < size; iter_1++)
		{
			garage = array[iter_1];
			for (
				iter_2 = iter_1;
				iter_2 > gp - 1 && array[iter_2 - gp] > garage; iter_2 -= gp
			)
			{
				array[iter_2] = array[iter_2 - gp];
			}
			array[iter_2] = garage;
		}
		print_array(array, size);
	}
}
