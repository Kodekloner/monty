#include "monty.h"
/**
 * swap_top_two - swaps the top two elements of the stack.
 * @stack: stack
 * @lineCount: line_number
 * Return: This function does not return a value.
*/
void swap_top_two(stack_t **stack, unsigned int lineCount)
{
	stack_t *st;
	int num = 0, opp;

	st = *stack;
	while (st)
	{
		st = st->next;
		num++;
	}
	if (num < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	opp = st->n;
	st->n = st->next->n;
	st->next->n = opp;
}
