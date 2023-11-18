#include "sort.h"

unsigned int power_of_10(unsigned int pw);
unsigned int s_cnt(int *arr, size_t sz, unsigned int value);

/**
 * s_cnt - sort the array first
 * @arr: the array
 * @sz: size of array
 * @value: value to met in order
 * Return: 1 int
*/

unsigned int s_cnt(int *arr, size_t sz, unsigned int value)
{
	int iter_1, srt_counter[10] = {0}, *idx_cp = NULL;
	size_t j, garage, srt_sm = 0;
	unsigned int dplct_1, dd_2, ordre = 0;

	dd_2 = power_of_10(value - 1);
	dplct_1 = dd_2 * 10;
	idx_cp = malloc(sizeof(int) * sz);
	if (idx_cp == NULL)
		exit(1);
	for (j = 0; j < sz; j++)
	{
		idx_cp[j] = arr[j];
		if (arr[j] / dplct_1 != 0)
			ordre = 1;
	}
	for (iter_1 = 0; iter_1 < 10 ; iter_1++)
		srt_counter[iter_1] = 0;
	for (j = 0; j < sz; j++)
		srt_counter[(arr[j] % dplct_1) / dd_2] += 1;
	for (iter_1 = 0; iter_1 < 10; iter_1++)
	{
		garage = srt_counter[iter_1];
		srt_counter[iter_1] = srt_sm;
		srt_sm += garage;
	}
	for (j = 0; j < sz; j++)
	{
		arr[srt_counter[(idx_cp[j] % dplct_1) / dd_2]] = idx_cp[j];
		srt_counter[(idx_cp[j] % dplct_1) / dd_2] += 1;
	}
	free(idx_cp);
	return (ordre);
}

/**
 * power_of_10 - fct calculate the power of 10
 * @pw: the power
 * Return: unsigned int
*/

unsigned int power_of_10(unsigned int pw)
{
	unsigned int iter, resultat;

	resultat = 1;
	for (iter = 0; iter < pw; iter++)
		resultat *= 10;
	return (resultat);
}

/**
 * radix_sort - sort array of int usingradix algorithm
 * @array: pointer to the first element of array
 * @size: the size of array
 * Return: empty
*/

void radix_sort(int *array, size_t size)
{
	unsigned int iter_1, iter_2 = 1;

	if (!array || size <= 1)
		return;
	for (iter_1 = 1; iter_2 == 1; iter_1++)
	{
		iter_2 = s_cnt(array, size, iter_1);
		print_array(array, size);
	}
}
