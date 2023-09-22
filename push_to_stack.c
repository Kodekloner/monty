#include "monty.h"
/**
 * push_to_stack - add node to the stack
 * @stack: stack
 * @value: The current line number.
 * Return: This function does not return a value.
*/
void push_to_stack(stack_t **stack, unsigned int value)
{
	int m, i = 0, fg = 0;

	if (store.argument)
	{
		if (store.argument[0] == '-')
			i++;
		for (; store.argument[i] != '\0'; i++)
		{
			if (store.argument[i] > 57 || store.argument[i] < 48)
				fg = 1; }
		if (fg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", value);
			fclose(store.montyFile);
			free(store.command);
			free_stack_mem(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", value);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE); }
	m = atoi(store.argument);
	if (store.stackFlag == 0)
		add_node_to_stack(stack, m);
	else
		add_node_to_queue(stack, m);
}
