#include "monty.h"
store_t store = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @agc: number of arguments
* @agv: monty file location as arguments
* Return: returns 0 on success
*/
int main(int agc, char *agv[])
{
	char *command;
	FILE *inputFile;
	size_t sz = 0;
	ssize_t rd_ln = 1;
	stack_t *sk = NULL;
	unsigned int lineCount = 0;

	if (agc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inputFile = fopen(agv[1], "r");
	store.montyFile = inputFile;
	if (!inputFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", agv[1]);
		exit(EXIT_FAILURE);
	}
	while (rd_ln > 0)
	{
		command = NULL;
		rd_ln = getline(&command, &sz, inputFile);
		store.command = command;
		lineCount++;
		if (rd_ln > 0)
		{
			execute_command(command, &sk, lineCount, inputFile);
		}
		free(command);
	}
	free_stack_mem(sk);
	fclose(inputFile);
return (0);
}
