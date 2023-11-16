#include "sort.h"

/**
 * echange_place - swap place of two nodes
 * @nd_1: adrss first node
 * @nd_2: adrss second node
 * Return: empty
*/

void echange_place(listint_t *nd_1, listint_t *nd_2)
{
	if (nd_1->prev != NULL)
		nd_1->prev->next = nd_2;
	if (nd_2->next != NULL)
		nd_2->next->prev = nd_1;
	nd_1->next = nd_2->next;
	nd_2->prev = nd_1->prev;
	nd_1->prev = nd_2;
	nd_2->next = nd_1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of int
 * @list: adrss of the pointer of the head list
 * Return: empty
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *garage, *itr;

	if (!list || !*list || (*list)->next == NULL)
		return;
	itr = (*list)->next;
	while (itr != NULL)
	{
		garage = itr;
		itr = itr->next;
		while (garage != NULL && garage->prev)
		{
			if (garage->prev->n > garage->n)
			{
				echange_place(garage->prev, garage);
				if (garage->prev == NULL)
					*list = garage;
				print_list((const listint_t *)*list);
			}
			else
				garage = garage->prev;
		}
	}
}
