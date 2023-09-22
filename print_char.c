#include "monty.h"
/**
 * print_char - prints the top stack, followed by a new line.
 * @stack: stack
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void print_char(stack_t **stack, unsigned int lineCount)
{
	stack_t *st;

	st = *stack;
	if (!st)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	if (st->n > 127 || st->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", st->n);
}
