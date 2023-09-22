#include "monty.h"
/**
* execute_command - execute_commands the opcode
* @stack: stack linked list - stack
* @lineCount: line_lineCount
* @inputFile: poiner to input file
* @command: line command
* Return: This function does not return a value.
*/
int execute_command(
	char *command, stack_t **stack, unsigned int lineCount, FILE *inputFile)
{
	instruction_t aust[] = {
				{"push", push_to_stack}, {"pall", print_stack},
				{"pint", print_top_element}, {"pop", pop_from_stack},
				{"swap", swap_top_two}, {"add", add_top_two},
				{"nop", do_nothing}, {"sub", subtract_top_two},
				{"div", divide_top_two}, {"mul", multiply_top_two},
				{"mod", modulo_top_two}, {"pchar", print_char},
				{"pstr", print_string}, {"rotl", rotate_left},
				{"rotr", rotate_right}, {"queue", switch_to_queue},
				{"stack", switch_to_stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *au;

	au = strtok(command, " \n\t");
	if (au && au[0] == '#')
		return (0);
	store.argument = strtok(NULL, " \n\t");
	while (aust[j].opcode && au)
	{
		if (strcmp(au, aust[j].opcode) == 0)
		{	aust[j].f(stack, lineCount);
			return (0);
		}
		j++;
	}
	if (au && aust[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lineCount, au);
		fclose(inputFile);
		free(command);
		free_stack_mem(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
