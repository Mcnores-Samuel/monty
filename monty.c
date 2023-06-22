#include "monty.h"


/**
 * main - entry point of the monty function.
 * @argc: argument count.
 * @argv: pointer to array of command line arguments
 * Return: o on success or error is set appropriately.
 */
int main(int argc, char **argv)
{

	FILE *file;

	if (argc < 2)
	{
		fprintf(stderr, "%s\n", USAGE_ERR);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "%s%s\n", FILE_ERR, argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file_instructions(file);
	fclose(file);
	return (0);
}
