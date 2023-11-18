#include "sort.h"

void ech_place(listint_t *index_new, listint_t *index_prev, listint_t **d_lst);

/**
 * cocktail_sort_list - sort array of int using cocktail sort algorithm
 * @list: doubly linked list
 * Return: empty
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *srt_tail = *list, *el_f = NULL, *el_l = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	do {
		while (srt_tail->next)
		{
			if (srt_tail->n > srt_tail->next->n)
				ech_place(srt_tail->next, srt_tail, list);
			else
				srt_tail = srt_tail->next;
		}
		el_l = srt_tail;
		while (srt_tail->prev != el_f)
		{
			if (srt_tail->n < srt_tail->prev->n)
				ech_place(srt_tail, srt_tail->prev, list);
			else
				srt_tail = srt_tail->prev;
		}
		el_f = srt_tail;
	} while (el_f != el_l);
}

/**
 * ech_place - echange value in the array
 * @index_new: pointer in a new value of array
 * @index_prev: pointer in the old value of array
 * @d_lst: a doubly linked list
 * Return: empty
*/

void ech_place(listint_t *index_new, listint_t *index_prev, listint_t **d_lst)
{
	listint_t *garage_1 = index_new->next;
	listint_t *garage_2 = index_prev->prev;

	if (garage_1 != NULL)
		garage_1->prev = index_prev;
	if (garage_2 != NULL)
		garage_2->next = index_new;
	index_new->prev = garage_2;
	index_prev->next = garage_1;
	index_new->next = index_prev;
	index_prev->prev = index_new;
	if (*d_lst == index_prev)
		*d_lst = index_new;
	print_list(*d_lst);
}
