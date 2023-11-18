#include "sort.h"

/**
 * counting_sort - sort array of int usingcounting algorithm
 * @array: pointer to the first element of array
 * @size: the size of the array
*/
void counting_sort(int *array, size_t size)
{
	int iter_1, indx_m;
	int *cnt = NULL;
	int *indx_cp = NULL;
	size_t iter_2, garage;
	size_t val_sum = 0;

	if (!array || size < 2)
		return;
	indx_cp = malloc(sizeof(int) * size);
	if (!indx_cp)
		return;
	for (iter_2 = 0, indx_m = 0; iter_2 < size; iter_2++)
	{
		indx_cp[iter_2] = array[iter_2];
		if (array[iter_2] > indx_m)
			indx_m = array[iter_2];
	}
	cnt = malloc(sizeof(int) * (indx_m + 1));
	if (!cnt)
	{
		free(indx_cp);
		return;
	}
	for (iter_1 = 0; iter_1 <= indx_m; iter_1++)
		cnt[iter_1] = 0;
	for (iter_2 = 0; iter_2 < size; iter_2++)
		cnt[array[iter_2]] += 1;
	for (iter_1 = 0; iter_1 <= indx_m; iter_1++)
	{
		garage = cnt[iter_1];
		cnt[iter_1] = val_sum;
		val_sum += garage;
	}
	for (iter_2 = 0; iter_2 < size; iter_2++)
	{
		array[cnt[indx_cp[iter_2]]] = indx_cp[iter_2];
		cnt[indx_cp[iter_2]] += 1;
	}
	print_array(cnt, indx_m + 1);
	free(cnt);
	free(indx_cp);
}
