#include "deck.h"
/**
 * sort_deck - Sort a deck of cards from ace to king and
 * from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_value(deck);
	insertion_sort_deck_kind(deck);
}
/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 * spades to diamonds from ace to king
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *current, *tmp;

	for (current = *deck; current; current = current->next)
	{
		while (current->next &&
			(get_value(current->next) < get_value(current)))
		{
			tmp = current->next;
			current->next = tmp->next;
			tmp->prev = current->prev;

			if (current->prev)
				current->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = current;

			current->prev = tmp;
			tmp->next = current;

			if (tmp->prev)
				current = tmp->prev;
			else
				*deck = tmp;
		}
	}
}
/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
	if (strcmp(card->card->value, "King") == 0)
		return (13);
	return (atoi(card->card->value));
}
/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds..
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *current, *tmp;

	for (current = *deck; current; current = current->next)
	{
		while (current->next &&
			   (current->next->card->kind < current->card->kind))
		{
			tmp = current->next;
			current->next = tmp->next;
			tmp->prev = current->prev;

			if (current->prev)
				current->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = current;

			current->prev = tmp;
			tmp->next = current;

			if (tmp->prev)
				current = tmp->prev;
			else
				*deck = tmp;
		}
	}
}
