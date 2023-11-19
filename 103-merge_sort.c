#include "sort.h"

/**
 * cmp_and_merge - compare the values and merge
 * @arr: the array
 * @indx_str: start index
 * @indx_stp: index to stop
 * @o_arr: the finale array
 * Return: empty
*/

void cmp_and_merge(int *arr, size_t indx_str, size_t indx_stp, int *o_arr)
{
	size_t iter_1 = indx_str, iter_2, iter_3, mdm;

	iter_2 = mdm = (indx_str + indx_stp) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + indx_str, mdm - indx_str);
	printf("[right]: ");
	print_array(arr + mdm, indx_stp - mdm);
	for (iter_3 = indx_str; iter_3 < indx_stp; iter_3++)
		if (iter_1 < mdm && (iter_2 >= indx_stp || arr[iter_1] <= arr[iter_2]))
		{
			o_arr[iter_3] = arr[iter_1++];
		}
		else
		{
			o_arr[iter_3] = arr[iter_2++];
		}
	printf("[Done]: ");
	print_array(o_arr + indx_str, indx_stp - indx_str);

}

/**
 * mrg - sorts top to down with recursive
 * @arr: the array
 * @indx_str: index to start
 * @indx_stp: index to stop
 * @o_arr: the finale array
 * Return: empty
*/

void mrg(int *arr, size_t indx_str, size_t indx_stp, int *o_arr)
{
	size_t mdm;

	mdm = (indx_str + indx_stp) / 2;
	if (indx_stp - indx_str < 2)
		return;
	mrg(o_arr, indx_str, mdm, arr);
	mrg(o_arr, mdm, indx_stp, arr);
	cmp_and_merge(arr, indx_str, indx_stp, o_arr);
}

/**
 * merge_sort - sort array using merge algorithm
 * @array: a pointer in the first element of array
 * @size: the size of the array
 * Return: Empty
*/

void merge_sort(int *array, size_t size)
{
	int *out;
	size_t iter;

	if (array == NULL || size <= 1)
		return;
	out = malloc(sizeof(int) * size);
	if (out == NULL)
		return;
	for (iter = 0; iter < size; iter++)
		out[iter] = array[iter];
	mrg(out, 0, size, array);
	free(out);
}
