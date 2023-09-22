#include "monty.h"
/**
 * pop_from_stack - prints the top stack
 * @stack: stack
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void pop_from_stack(stack_t **stack, unsigned int lineCount)
{
	stack_t *st;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	st = *stack;
	*stack = st->next;
	free(st);
}
