#include "monty.h"
/**
 * switch_to_queue - switch to from stack to queue
 * @stack: stack
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void switch_to_queue(stack_t **stack, unsigned int lineCount)
{
	(void)stack;
	(void)lineCount;
	store.stackFlag = 1;
}

/**
 * add_node_to_queue - add node to stack
 * @node: new node to be added
 * @stack: stack
 * Return: This function does not return a value.
*/
void add_node_to_queue(stack_t **stack, int node)
{
	stack_t *nw_n, *opp;

	opp = *stack;
	nw_n = malloc(sizeof(stack_t));
	if (nw_n == NULL)
	{
		printf("Error\n");
	}
	nw_n->n = node;
	nw_n->next = NULL;
	if (opp)
	{
		while (opp->next)
			opp = opp->next;
	}
	if (!opp)
	{
		*stack = nw_n;
		nw_n->prev = NULL;
	}
	else
	{
		opp->next = nw_n;
		nw_n->prev = opp;
	}
}
