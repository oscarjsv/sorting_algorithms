#include "sort.h"



void swap_right(listint_t **head, listint_t **list, listint_t **prev);
void swap_left(listint_t **list, listint_t **rev);

/**
 * insertion_sort_list - insertion sorting algorithm integers
 * @list: the head of the linked list
 * Return: nothing in-place algorithm
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *prev, *head;
	listint_t *rev;

	prev = NULL;


	if (list == NULL || *list == NULL)
	{
		return;
	}
	head = *list;
	if (head->next == NULL)
		return;

	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{

			swap_right(&head, list, &prev);
			rev = head;
			swap_left(list, &rev);
		}


		prev = head;
		head = head->next;
	}


}


/**
 * swap_right - swaping elemetn until the end of the list
 * @list: the head of the linked list
 * @prev: starting point to do the swapping
 * @head: actual position in the linked list
 * Return: nothing in-place algorithm
 */

void swap_right(listint_t **head, listint_t **list, listint_t **prev)
{
	listint_t *next, *head_t = *head, *prev_t = *prev;


	next = head_t->next;
	if (next->next != NULL)
		next->next->prev = head_t;

	head_t->next = next->next;
	head_t->prev = next;

	next->next = head_t;
	next->prev = prev_t;

	if (prev_t != NULL)
		prev_t->next = next;

	if (next->prev == NULL)
		*list = next;

	print_list(*list);
	*head = next;
}

/**
 * swap_left - swap elemet until the start of the list
 * @list: the head of the linked list
 * @rev: the starting point to swap the elements
 * Return: nothing in-place algorithm
 */

void swap_left(listint_t **list, listint_t **rev)
{
	listint_t *rev_t = *rev, *prev_r, *next_r;

	while (rev != NULL && rev_t->prev != NULL)
	{

		if (rev_t->n < rev_t->prev->n)
		{

			prev_r = rev_t->prev;
			next_r = prev_r->prev;

			prev_r->next = rev_t->next;
			rev_t->next->prev = prev_r;

			rev_t->next = prev_r;
			prev_r->prev = rev_t;

			if (next_r != NULL)
			{
				next_r->next = rev_t;
			}
			if (next_r == NULL)
			{
				*list = rev_t;
			}
			rev_t->prev = next_r;
			rev_t = prev_r;

		}
		else
		{
			break;
		}
		if (rev_t->prev == NULL)
		{
			*list = rev_t;
		}
		print_list(*list);
		rev_t = rev_t->prev;
	}

}
