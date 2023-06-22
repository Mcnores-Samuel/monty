#include "monty.h"

/**
 * add_stack_element - adds an item of element to the stack.
 * @size: number of element in buffer array.
 * @buffer: pointer array of strings of the buffer location in memory.
 * Return: void
 */
void add_stack_element(int size, char **buffer)
{
	stack_t *stack = NULL;
	void (*func_ptr)(stack_t **, unsigned int);
	create_cmd *head = NULL;
	char *copy_buffer;
	int n, value = 0;

	for (n = 0; n < size && buffer[n] != NULL; n++)
	{
		if (buffer[n] != NULL)
			copy_buffer = _strdup(buffer[n]);

		parse_opcode(&head, copy_buffer, " ");

		func_ptr = get_stack_operator(head->opcode);
		if (func_ptr != NULL)
		{
			if (head->data != NULL)
				value = atoi(head->data);
			func_ptr(&stack, value);
		}
		free(head);
		free(copy_buffer);
		head = NULL;
	}
	_free_stack(stack);
}

/**
 * process_file_instructions - processes the input from the file to read from.
 * @file: pointer to the input file of instructions
 * Return: void.
 */
void process_file_instructions(FILE *file)
{
	int count = 0, i = 0, bytes;
	char *container, final[100], ch;
	char **buffer;

	while ((ch = fgetc(file)) != EOF)
		if (ch == '\n')
			count++;

	rewind(file);

	buffer = (char **)malloc(sizeof(char *) * count);
	if (buffer == NULL)
	{
		fprintf(stderr, "%s\n", MALLLOC_ERR);
		exit(EXIT_FAILURE);
	}
	memset(buffer, 0, count);

	for (i = 0; i < count; i++) {
		container = (char *)malloc(sizeof(char) * 100);
		fgets(container, sizeof(char) * 100, file);
		bytes = strlen(container);
		container[bytes - 1] = '\0';
		remove_reading_space(&container, final);
		bytes = _strlen(final);
		final[bytes] = '\0';
		buffer[i] = (char *)malloc(sizeof(char) * bytes + 1);
		_strncpy(buffer[i], final, _strlen(final));
		buffer[i][bytes] = '\0';
	}
	add_stack_element(count, buffer);
	free_input_array(buffer, count);
}
