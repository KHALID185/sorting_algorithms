#include "sort.h"

/**
 * selection_sort - using selection alg to sort in order array
 * @array: pointer to the first element in array
 * @size: size of array
 * return: empty
*/

void selection_sort(int *array, size_t size)
{
	int garage;
	size_t itr, itr_1, itr_2;

	if (!array || !size)
		return;
	for (itr = 0; itr <= size - 2; itr++)
	{
		for (itr_1 = size - 1, itr_2 = itr + 1; itr_1 > itr; itr_1--)
		{
			if (array[itr_1] < array[itr_2])
			{
				itr_2 = itr_1;
			}
		}
		if (array[itr] > array[itr_2])
		{
			garage = array[itr];
			array[itr] = array[itr_2];
			array[itr_2] = garage;
			print_array(array, size);
		}
	}
}
