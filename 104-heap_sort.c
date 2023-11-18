#include "sort.h"

#define par(y) (((y) - 1) / 2)
#define lch(y) (((y) * 2) + 1)

/**
 * echange_place - change place for 2 elements
 * @arr: the array
 * @sz: the size of array
 * @el_1: first element
 * @el_2: second element
 * Return: empty
*/

void echange_place(int *arr, size_t sz, int *el_1, int *el_2)
{
	if (*el_1 != *el_2)
	{
		*el_1 = *el_1 + *el_2;
		*el_2 = *el_1 - *el_2;
		*el_1 = *el_1 - *el_2;
	}
	print_array((const int *)arr, sz);
}

/**
 * sft_down - siftdown etape
 * @arr: the array
 * @sz: the size of array
 * @db: start of array
 * @fin: the end of arr
 * Return: empty
*/

void sft_down(int *arr, size_t db, size_t fin, size_t sz)
{
	size_t head = db, echange, enf;

	while (lch(head) <= fin)
	{
		enf = lch(head);
		echange = head;
		if (arr[echange] < arr[enf])
			echange = enf;
		if (enf + 1 <= fin && arr[echange] < arr[enf + 1])
			echange = enf + 1;
		if (echange == head)
			return;
		echange_place(arr, sz, &arr[head], &arr[echange]);
		head = echange;
	}
}

/**
 * heap_f - heapify etape for heap sort
 * @arr: the array
 * @sz: the size of arr
 * Return: empty
*/

void heap_f(int *arr, size_t sz)
{
	ssize_t db;

	db = par(sz - 1);
	while (db >= 0)
	{
		sft_down(arr, db, sz - 1, sz);
		db--;
	}
}

/**
 * heap_sort - sort array of int using heap algorithm
 * @array: pointer to the first element of the array
 * @size: the size of array
 * Return: empty
*/

void heap_sort(int *array, size_t size)
{
	size_t fin;

	if (array == NULL || size <= 1)
		return;
	heap_f(array, size);
	fin = size - 1;
	while (fin > 0)
	{
		echange_place(array, size, &array[fin], &array[0]);
		fin--;
		sft_down(array, 0, fin, size);
	}
}
