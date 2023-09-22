#include "monty.h"
/**
 * add_node_to_stack - Insert a node into the stack.
 * @stack: stack
 * @node: new node to be added
 * Return: This function does not return a value.
*/
void add_node_to_stack(stack_t **stack, int node)
{

	stack_t *nw_n, *opp;

	opp = *stack;
	nw_n = malloc(sizeof(stack_t));
	if (nw_n == NULL)
	{ printf("Error\n");
		exit(0); }
	if (opp)
		opp->prev = nw_n;
	nw_n->n = node;
	nw_n->next = *stack;
	nw_n->prev = NULL;
	*stack = nw_n;
}
