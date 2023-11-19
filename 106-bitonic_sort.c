#include "sort.h"

/**
 * cmp_bitnc - comparaison bitonic function
 * @srt_direction: sorted numbers direction
 * @arr: the array
 * @sz: the size of array
 * Return: empty
*/

void cmp_bitnc(char srt_direction, int *arr, size_t sz)
{
	size_t iter_1, iter;
	int change_plc;

	iter = sz / 2;
	for (iter_1 = 0; iter_1 < iter; iter_1++)
	{
		if ((arr[iter_1] > arr[iter_1 + iter]) == srt_direction)
		{
			change_plc = arr[iter_1];
			arr[iter_1] = arr[iter_1 + iter];
			arr[iter_1 + iter] = change_plc;
		}
	}
}

/**
 * mrg_bitnc - merge using bitonic algorithm function
 * @srt_direction: direction of the sorted numbers
 * @arr: the array
 * @sz: size of array
 * Return: empty
*/

void mrg_bitnc(char srt_direction, int *arr, size_t sz)
{
	if (sz <= 1)
		return;
	cmp_bitnc(srt_direction, arr, sz);
	mrg_bitnc(srt_direction, arr, sz / 2);
	mrg_bitnc(srt_direction, arr + (sz / 2), sz / 2);
}

/**
 * srt_bitnc - sort integers using bitonic algorithm
 * @srt_d: direction of array sorted
 * @arr: the array
 * @sz: size of array
 * @sz_t: total size
 * Return: empty
*/

void srt_bitnc(char srt_d, int *arr, size_t sz, size_t sz_t)
{
	if (sz <= 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", sz, sz_t, (srt_d == 1) ? "UP" : "DOWN");
	print_array(arr, sz);
	srt_bitnc(1, arr, sz / 2, sz_t);
	srt_bitnc(0, arr + (sz / 2), sz / 2, sz_t);
	mrg_bitnc(srt_d, arr, sz);
	printf("Result [%lu/%lu] (%s):\n", sz, sz_t, (srt_d == 1) ? "up" : "DOWN");
	print_array(arr, sz);

}

/**
 * bitonic_sort - sort array of int using bitonic algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: empty
*/

void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	srt_bitnc(1, array, size, size);
}
