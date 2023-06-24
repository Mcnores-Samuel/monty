#include "monty.h"

/**
 * get_stack_operator - looks for the opcode matching the str.
 * @instruct: the string to match or opcode instructions.
 * Return: pointer to the function of the matching opcode instruction.
 */
int (*get_stack_operator(char *instruct))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t builtins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};

	while (builtins[i].opcode != NULL)
	{
		if (_strncmp(builtins[i].opcode, instruct, _strlen(instruct)) == 0)
			return (builtins[i].f);
		i++;
	}

	return (NULL);
}
