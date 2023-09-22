#include "monty.h"
/**
  * rotate_left- rotates the stack to the left
  * @stack: stack
  * @lineCount: line_number
  * Return: This function does not return a value.
 */
void rotate_left(
	stack_t **stack,  __attribute__((unused)) unsigned int lineCount)
{
	stack_t *temp = *stack, *opp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	opp = (*stack)->next;
	opp->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = opp;
}
