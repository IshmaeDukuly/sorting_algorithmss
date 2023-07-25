#include "sort.h"
/**
 * insertion_sort_list - This is the function that sorts doubly
 * list of integers orderly using the insertion sort algorithm
 * @list: Doublu linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *swap_node - swap a node for the previous one
 *@node: The node
 *@list: This is the node list
 *Return: return the pointer to the node_list
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
