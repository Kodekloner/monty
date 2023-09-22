#include "monty.h"
/**
* free_stack_mem - frees stack memory (double linked list)
* @stack: stack
* Return: This function does not return a value.
*/
void free_stack_mem(stack_t *stack)
{
	stack_t *opp;

	opp = stack;
	while (stack)
	{
		opp = stack->next;
		free(stack);
		stack = opp;
	}
}
