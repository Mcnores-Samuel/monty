#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MALLLOC_ERR "Error: malloc failed"
#define USAGE_ERR "USAGE: monty file"
#define FILE_ERR "Error: Can't open file "
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
 * struct command_s - the structure store a commmand and arguments
 * @command: command name or simply a command.
 * @argument: Array of arguments of the command.
 * @next: pointer to the next node.
 * Description: Every command and the arguments are craeted as a node
 * at each command call.
 */
typedef struct command_s
{
	char *opcode;
	char *data;
	struct command_s *next;
} create_cmd;
int _putchar_errno(char c);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strstr(char *mainstr, char *substr);
char *_strcpy(char *destination, char *source);
int _atoi(char *string);
int _putchar(char c);
void _puts(char *str);
#endif
