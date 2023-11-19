#include "sort.h"

/**
 * echange_place - swap two element of array
 * @arr: the array
 * @sz: size of array
 * @el_1: first element of array
 * @el_2: second element of array
 * Return: empty
*/

void echange_place(int *arr, size_t sz, int *el_1, int *el_2)
{
	if (*el_1 != *el_2)
	{
		*el_1 = *el_1 + *el_2;
		*el_2 = *el_1 - *el_2;
		*el_1 = *el_1 - *el_2;
		print_array((const int *)arr, sz);
	}
}

/**
 * sch_Lomuto - Lomuto partition scheme.
 * @arr: the array
 * @sz: the size of the array
 * @index_l: the low index
 * @index_h: the high index
 * Return: the size
*/

size_t sch_Lomuto(int *arr, size_t sz, ssize_t index_l, ssize_t index_h)
{
	int pvt = arr[index_h];
	int iter_1, iter_2;

	for (iter_1 = iter_2 = index_l; iter_2 < index_h; iter_2++)
		if (arr[iter_2] < pvt)
			echange_place(arr, sz, &arr[iter_2], &arr[iter_1++]);
	echange_place(arr, sz, &arr[iter_1], &arr[index_h]);
	return (iter_1);
}

/**
 * sort_int - sort via lumuto
 * @arr: the array
 * @sz: the size
 * @index_l: low index
 * @index_h: high index of the rang sorted
 * Return: empty
*/

void sort_int(int *arr, size_t sz, ssize_t index_l, ssize_t index_h)
{
	if (index_l < index_h)
	{
		size_t pvt = sch_Lomuto(arr, sz, index_l, index_h);

		sort_int(arr, sz, index_l, pvt - 1);
		sort_int(arr, sz, pvt + 1, index_h);
	}
}

/**
 * quick_sort - sort array of int with quick sort algorithm
 * @array: pointer to the first element of the array
 * @size: the size of the array
 * Return: empty
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	sort_int(array, size, 0, size - 1);
}
