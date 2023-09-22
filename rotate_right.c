#include "monty.h"
/**
  * rotate_right- rotates the stack right
  * @stack: stack
	* @lineCount: line_number
  * Return: This function does not return a value.
 */
void rotate_right(
	stack_t **stack, __attribute__((unused)) unsigned int lineCount)
{
	stack_t *cp;

	cp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *stack;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*stack)->prev = cp;
	(*stack) = cp;
}
