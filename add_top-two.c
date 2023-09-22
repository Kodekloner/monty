#include "monty.h"
/**
 * add_top_two - adds together the two elements at the top of the stack.
 * @stack: The stack to perform the operation on.
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void add_top_two(stack_t **stack, unsigned int lineCount)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	opp = st->n + st->next->n;
	st->next->n = opp;
	*stack = st->next;
	free(st);
}
