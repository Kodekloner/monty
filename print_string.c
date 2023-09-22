#include "monty.h"
/**
 * print_string - print string at the top of the stack, followed by a new line.
 * @stack: stack
 * @lineCount: The current line number.
 * Return: This function does not return a value.
*/
void print_string(stack_t **stack, unsigned int lineCount)
{
	stack_t *st;
	(void)lineCount;

	st = *stack;
	while (st)
	{
		if (st->n > 127 || st->n <= 0)
		{
			break;
		}
		printf("%c", st->n);
		st = st->next;
	}
	printf("\n");
}
