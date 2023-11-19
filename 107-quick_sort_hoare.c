#include "sort.h"

void srt_hoare(int *array, ssize_t indx_min, ssize_t indx_max, size_t size);
size_t hoare_partition(int *arr, ssize_t indx_min, ssize_t indx_max, size_t sz);

/**
 * quick_sort_hoare - sorts an array of int with quick sort hoare algrthm
 * @array: pointer to the first element of array
 * @size: The size of the array
 * Return: empty
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	srt_hoare(array, 0, size - 1, size);
}
/**
 * srt_hoare - sort array of int using hoare partition algorithm
 * @arr: the array
 * @indx_min: index minimum of the hoare_partition
 * @indx_max: index maximum of the hoare_partition
 * @size: the size of array
 * Return: empty
*/

void srt_hoare(int *array, ssize_t indx_min, ssize_t indx_max, size_t size)
{
	ssize_t pvt_arr;

	if (indx_min < indx_max)
	{
		pvt_arr = hoare_partition(array, indx_min, indx_max, size);
		srt_hoare(array, indx_min, pvt_arr, size);
		srt_hoare(array, pvt_arr + 1, indx_max, size);

	}
}

/**
 * hoare_partition - the Hoare partition scheme function
 * @arr: the array
 * @indx_min: index minimum
 * @indx_max: index maximum
 * @sz: the size of array
 * Return: the size
*/

size_t hoare_partition(int *arr, ssize_t indx_min, ssize_t indx_max, size_t sz)
{
	int change_plc, pvt_arr;

	pvt_arr = arr[indx_max];
	while (indx_min <= indx_max)
	{
		while (arr[indx_min] < pvt_arr)
			indx_min++;
		while (arr[indx_max] > pvt_arr)
			indx_max--;
		if (indx_min <= indx_max)
		{
			if (indx_min != indx_max)
			{
				change_plc = arr[indx_min];
				arr[indx_min] = arr[indx_max];
				arr[indx_max] = change_plc;
				print_array(arr, sz);
			}
			indx_min++;
			indx_max--;
		}
	}
	return (indx_max);
}
