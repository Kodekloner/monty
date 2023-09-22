#include "monty.h"
/**
  * subtract_top_two - sustration the two top stack
  * @stack: stack
	* @lineCount: line_number
  * Return: This function does not return a value.
 */
void subtract_top_two(stack_t **stack, unsigned int lineCount)
{
	stack_t *opp;
	int pup, nd;

	opp = *stack;
	for (nd = 0; opp != NULL; nd++)
		opp = opp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineCount);
		fclose(store.montyFile);
		free(store.command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE);
	}
	opp = *stack;
	pup = opp->next->n - opp->n;
	opp->next->n = pup;
	*stack = opp->next;
	free(opp);
}
