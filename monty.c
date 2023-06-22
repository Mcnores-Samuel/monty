#include "monty.h"


/**
 * get_stack_operator - looks for the opcode matching the str.
 * @instruct: the string to match or opcode instructions.
 * Return: pointer to the function of the matching opcode instruction.
 */
void (*get_stack_operator(char *instruct))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t builtins[] = {
		{"push", push},
		{"pall", pall},
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



/**
 * main - entry point of the monty function.
 * @argc: argument count.
 * @argv: pointer to array of command line arguments
 * Return: o on success or error is set appropriately.
 */
int main(int argc, char **argv) {

	FILE *file;

	if (argc < 2) {
		fprintf(stderr, "%s\n", USAGE_ERR);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file) {
		fprintf(stderr, "%s%s\n", FILE_ERR, argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file_instructions(file);
	fclose(file);	
	return 0;
}
