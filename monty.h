#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct store_s - Structure for storing command arguments,
 * 									file, and line command.
 * @argument: Value of the argument.
 * @montyFile: Pointer to the Monty file.
 * @command: line command.
 * @stackFlag: Flag indicating a change between stack and queue.
 * Description: This structure carries essential values throughout the program.
 */
typedef struct store_s
{
    char *argument;
    FILE *montyFile;
    char *command;
    int stackFlag;
} store_t;
extern store_t store;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_to_stack(stack_t **stack, unsigned int value);
void print_stack(stack_t **stack, unsigned int value);
void print_top_element(stack_t **stack, unsigned int value);
int execute_command(
	char *command, stack_t **stack, unsigned int lineCount, FILE *inputFile);
void free_stack_mem(stack_t *stack);
void pop_from_stack(stack_t **stack, unsigned int lineCount);
void swap_top_two(stack_t **stack, unsigned int lineCount);
void add_top_two(stack_t **stack, unsigned int lineCount);
void do_nothing(stack_t **stack, unsigned int lineCount);
void subtract_top_two(stack_t **stack, unsigned int lineCount);
void divide_top_two(stack_t **stack, unsigned int lineCount);
void multiply_top_two(stack_t **stack, unsigned int lineCount);
void modulo_top_two(stack_t **stack, unsigned int lineCount);
void print_char(stack_t **stack, unsigned int lineCount);
void print_string(stack_t **stack, unsigned int lineCount);
void rotate_left(
	stack_t **stack, __attribute__((unused)) unsigned int lineCount);
void rotate_right(
	stack_t **stack, __attribute__((unused)) unsigned int lineCount);
void add_node_to_stack(stack_t **stack, int node);
void add_node_to_queue(stack_t **queue, int node);
void switch_to_queue(stack_t **stack, unsigned int lineCount);
void switch_to_stack(stack_t **stack, unsigned int lineCount);
#endif
