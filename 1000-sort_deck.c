#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

void swap_nodes(deck_node_t **list, deck_node_t **node1, deck_node_t *node2)
{
	deck_node_t *prev_node, *next_node;

	if (*node1 == node2)
	return;

	prev_node = node2->prev_node;
	next_node = node2->next_node;

	if (*node1 != NULL)
		(*node1)->next_node = node2;

	if (node2->prev_node != NULL)
		node2->prev->next_node = *node1;
	else
		*list = *node1;

	node2->prev_node = *node1;
	node2->next_node = (*node1)->next_node;

	(*node1)->prev_node = prev_node;
	(*node1)->next_node = next_node;

	if (next_node != NULL)
	next_node->prev_node = *node1;
}

void sort_deck(deck_node_t **deck)
{
	deck_node_t *cur, *index;
	const card_t *key;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	return;

	cur = (*deck)->next;

	while (cur != NULL)
	{
		key = cur->card;
		index = cur->prev_node;

	while (index != NULL && index->card->kind > key->kind)
	{
		swap_nodes(deck, &index->next_node, index);
		index = index->prev_node;
	}

	while (index != NULL && index->card->kind == key->kind &&
		index->card->value[0] > key->value[0])
	{
		swap_nodes(deck, &index->next_node, index);
		index = index->prev_node;
	}

	cur = cur->next_node;
	}
}
