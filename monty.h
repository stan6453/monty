#ifndef _SSTACK_
#define _SSTACK_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;





/**
* struct global_var - this structure contains all our global variable
* @file: pointer to monty file
* @line: line content
* @push_argument: argument passed to push
*
* Description: carries values through the program
*/
typedef struct global_var
{
	FILE *file;
	char **line;
	int push_argument;
}  global_v;
extern global_v gv;



void run_program(char **argv);
size_t _getline(char **line, size_t *linesize, FILE *file, stack_t *stacktail);
void tokenize_string(char *line, char *cmd[3]);

/*
 * core functions. functions that
 * supposed to be part of main.c, but couldn't fit
 */
void execute_cmd(char *cmd[], stack_t **stack, unsigned int line_number);
void (*get_cmd(char *op))(stack_t **stack, unsigned int line_number);

/*utility functions*/
void freestack(stack_t *stacktail);
void freeallandexit(stack_t *stacktail, FILE *file, char *line, int exitcode);
int isonlydigit(char *s);
int first_char_is_digit(char *s);


/*the functions to handle different operations*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void idiv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/*debugging functions*/
void printstack(stack_t *stacktail);


#endif
