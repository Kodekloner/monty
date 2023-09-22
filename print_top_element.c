#include "monty.h"
/**
 * print_top_element - prints the top stack element
 * @stack: stack
 * @value: The current line number.
 * Return: This function does not return a value.
*/
void print_top_element(stack_t **stack, unsigned int value)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", value);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
