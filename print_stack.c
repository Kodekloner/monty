#include "monty.h"
/**
 * print_stack - prints the stack to the standard input
 * @stack: stack
 * @value: The current line number.
 * Return: This function does not return a value.
*/
void print_stack(stack_t **stack, unsigned int value)
{
	stack_t *st;
	(void)value;

	st = *stack;
	if (st == NULL)
		return;
	while (st)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}
