#include "sort.h"
#include <stdio.h>
/**
*swap_node - swap a node for his previous one
*@node: node
*@list: node list
*Return: return a pointer to a node which was enter it
*/
listint_t *swap_node(listint_t *node, listint_t **list)
{
listint_t *behind = node->prev, *recent = node;
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
*list = recent;
return (recent);
}
/**
*cocktail_sort_list - this is a cocktail sort implementation
*working on a double linked lists
*@list: list
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *node;
int swap_done = 1;

if (list == NULL || (*list) == NULL || (*list)->next == NULL)
return;
node = *list;
while (swap_done == 1)
{
swap_done = 0;
while (node->next)
{
if (node->n > node->next->n)
{
node = swap_node(node->next, list);
swap_done = 1;
print_list(*list);
}
node = node->next;
}
if (swap_done == 0)
break;
swap_done = 0;
while (node->prev)
{
if (node->n < node->prev->n)
{
node = swap_node(node, list);
swap_done = 1;
print_list(*list);
}
else
node = node->prev;
}
}
}
