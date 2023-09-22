#include "monty.h"
/**
 * divide_top_two - divides two top elements of the stack.
 * @stack: stack
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void divide_top_two(stack_t **stack, unsigned int lineCount)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	if (st->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	opp = st->next->n / st->n;
	st->next->n = opp;
	*stack = st->next;
	free(st);
}
