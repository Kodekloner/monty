#include "monty.h"
/**
 * switch_to_stack - Switch back to stack
 * @stack: stack
 * @lineCount: line_number
 * Return: This function does not return a value.
*/
void switch_to_stack(stack_t **stack, unsigned int lineCount)
{
	(void)stack;
	(void)lineCount;
	store.stackFlag = 0;
}
