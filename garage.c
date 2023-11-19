#include "deck.h"

int cmp_s(const char *str1, const char *str2);
char upload_val(deck_node_t *el_crd);
void insert_kind(deck_node_t **dk);
void insert_deck_val(deck_node_t **dk);
void sort_deck(deck_node_t **deck);

/**
 * cmp_s - compare two strings
 * @str1: string 1
 * @str2: string 2.
 * Return: int
*/

int cmp_s(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * upload_val - uploade the value of the card
 * @el_crd: pointer to a strct card
 * Return: char
*/

char upload_val(deck_node_t *el_crd)
{
	if (cmp_s(el_crd->card->value, "Ace") == 0)
		return (0);
	if (cmp_s(el_crd->card->value, "1") == 0)
		return (1);
	if (cmp_s(el_crd->card->value, "2") == 0)
		return (2);
	if (cmp_s(el_crd->card->value, "3") == 0)
		return (3);
	if (cmp_s(el_crd->card->value, "4") == 0)
		return (4);
	if (cmp_s(el_crd->card->value, "5") == 0)
		return (5);
	if (cmp_s(el_crd->card->value, "6") == 0)
		return (6);
	if (cmp_s(el_crd->card->value, "7") == 0)
		return (7);
	if (cmp_s(el_crd->card->value, "8") == 0)
		return (8);
	if (cmp_s(el_crd->card->value, "9") == 0)
		return (9);
	if (cmp_s(el_crd->card->value, "10") == 0)
		return (10);
	if (cmp_s(el_crd->card->value, "Jack") == 0)
		return (11);
	if (cmp_s(el_crd->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_kind - insertion strct kind
 * @dk: pointer to the head of doubles linked list deck
 * Return: empty
*/

void insert_kind(deck_node_t **dk)
{
	deck_node_t *i, *add, *garage;

	for (i = (*dk)->next; i != NULL; i = garage)
	{
		garage = i->next;
		add = i->prev;
		while (add != NULL && add->card->kind > i->card->kind)
		{
			add->next = i->next;
			if (i->next != NULL)
				i->next->prev = add;
			i->prev = add->prev;
			i->next = add;
			if (add->prev != NULL)
				add->prev->next = i;
			else
				*dk = i;
			add->prev = i;
			add = i->prev;
		}
	}
}

/**
 * insert_deck_val - insertion of value of strct decl
 * @dk: pointer to the head of doubly-linked list deck
 * Return: empty
*/

void insert_deck_val(deck_node_t **dk)
{
	deck_node_t *i, *add, *garage;

	for (i = (*dk)->next; i != NULL; i = garage)
	{
		garage = i->next;
		add = i->prev;
		while (
			add != NULL && add->card->kind == i->card->kind &&
			upload_val(add) > upload_val(i)
		)
		{
			add->next = i->next;
			if (i->next != NULL)
				i->next->prev = add;
			i->prev = add->prev;
			i->next = add;
			if (add->prev != NULL)
				add->prev->next = i;
			else
				*dk = i;
			add->prev = i;
			add = i->prev;
		}
	}
}

/**
 * sort_deck - a function that sorts a deck of cards.
 * @deck: A pointer to the head of doubly-linked list
 * Return: empty
 */

void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || (*deck)->next == NULL)
		return;

	insert_kind(deck);
	insert_deck_val(deck);
}
