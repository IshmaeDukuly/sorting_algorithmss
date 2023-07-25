#include "deck.h"
#include <stdio.h>
/**
*_strcmp - The comparison of two strings
*@str1: The string
*@str2: The string
*Return: 1 str1 and str2 is equal, 0 they are not equal
*/
int _strcmp(const char *str1, char *str2)
{
size_t m = 0;

if (str1 == '\0')
return (0);
while (str1[m])
{
if (str1[m] != str2[m])
return (0);
m++;
}
if (str1[m] == '\0' && str2[m])
return (0);
return (1);
}
/**
* get_card_position - return the position based on card you put in
* @node: represent the card
* Return: return the card position
*/
int get_card_position(deck_node_t *node)
{
int value;

value = (*node).card->value[0] - '0';
if (value < 50 || value > 57)
{
if (_strcmp((*node).card->value, "Ace") == 1)
value = 1;
else if (_strcmp((*node).card->value, "10") == 1)
value = 10;
else if (_strcmp((*node).card->value, "Jack") == 1)
value = 11;
else if (_strcmp((*node).card->value, "Queen") == 1)
value = 12;
else if (_strcmp((*node).card->value, "King") == 1)
value = 13;
}
value += (*node).card->kind * 13;
return (value);
}
/**
*swap_card - swap the card for the pre one
*@card: This is the card
*@deck: this the card deck itself
*Return: Now return the  pointer to the card that was entered
*/
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
deck_node_t *behind = card->prev, *recent = card;
/*NULL, 19, 48, 9, 71, 13, NULL*/

behind->next = recent->next;
if (recent->next)
recent->next->prev = behind;
recent->next = behind;
recent->prev = behind->prev;
behind->prev = recent;
if (recent->prev)
recent->prev->next = recent;
else
*deck = recent;
return (recent);
}

/**
* insertion_sort_deck - function that sorts the doubly linked deck
* of integers orderly using the insertion sort method
* @deck: Doubly linked deck to sort
*/
void insertion_sort_deck(deck_node_t **deck)
{
int val_pre, val_recent;
deck_node_t *node;

if (deck == NULL || (*deck)->next == NULL)
return;
node = (*deck)->next;
while (node)
{
/* preparing the previous val */
if (node->prev)
{
val_pre = get_card_position((node->prev));
val_recent = get_card_position(node);
}
while ((node->prev) && (val_pre > val_recent))
{
val_pre = get_card_position((node->prev));
val_recent = get_card_position(node);
node = swap_card(node, deck);

}
node = node->next;
}
}
/**
* sort_deck - sort the deck you want to using the
* insertion sort algorithm method
* @deck: The deck
*/
void sort_deck(deck_node_t **deck)
{
insertion_sort_deck(deck);
}

