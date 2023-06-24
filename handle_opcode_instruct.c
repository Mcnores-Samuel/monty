#include "monty.h"

/**
 * is_int - checks is input string contains integers
 * @h: pointer to head node containing opcode instructions.
 * @n: line number of the instruction in a file.
 * @buf: pointer to arrays of characters or strings.
 * @num: number elements in buffer or buf
 * @s: pointer to head node of the stack.
 * Return: 0 if contains integer or -1 otherwise.
 */
int is_int(create_cmd *h, int n, char **buf, int num, stack_t *s)
{
	char *endptr;

	strtol(h->data, &endptr, 10);
	if (h->data == endptr || *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", n + 1);
		handle_memory(h, buf, num, s);
		return (-1);
	}
	return (0);
}
/**
 * add_stack_element - adds an item of element to the stack.
 * @size: number of element in buffer array.
 * @buffer: pointer array of strings of the buffer location in memory.
 * Return: void
 */
int add_stack_element(int size, char **buffer)
{
	stack_t *stack = NULL;
	int (*func_ptr)(stack_t **, unsigned int), n, value = 0;
	create_cmd *head = NULL;

	for (n = 0; n < size && buffer[n] != NULL; n++)
	{
		if (parse_opcode(&head, buffer[n], " ") == -1)
		{
			free(head);
			head = NULL;
			continue;
		}
		func_ptr = get_stack_operator(head->opcode);
		if (func_ptr != NULL)
		{
			if (head->data != NULL)
			{
				if (is_int(head, n, buffer, size, stack) == -1)
					return (-1);
				value = atoi(head->data);
			}
			else
				value = n + 1;
			if (func_ptr(&stack, value) == -1)
			{
				handle_memory(head, buffer, size, stack);
				return (-1);
			}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n + 1, head->opcode);
			handle_memory(head, buffer, size, stack);
			return (-1);
		}
		free(head);
		head = NULL;
	}
	_free_stack(stack);
	return (0);
}

/**
 * process_file_instructions - processes the input from the file to read from.
 * @file: pointer to the input file of instructions
 * Return: void.
 */
void process_file_instructions(FILE *file)
{
	int count = 0, i = 0, bytes, n = 0;
	char container[100], final[100], ch;
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

	for (i = 0; i < count; i++)
	{
		fgets(container, sizeof(char) * 100, file);
		bytes = strlen(container);
		container[bytes - 1] = '\0';
		remove_reading_space(container, final);
		bytes = _strlen(final);
		final[bytes] = '\0';
		buffer[i] = (char *)malloc(sizeof(char) * bytes + 1);
		_strncpy(buffer[i], final, _strlen(final));
		buffer[i][bytes] = '\0';
		n++;

	}

	if (add_stack_element(count, buffer) == -1)
	{
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (buffer != NULL)
		free_input_array(buffer, count);
}

/**
 * handle_memory - frees all memory allocated if unexpexted behaviour occured.
 * @h: pointer to head node containing opcode instructions.
 * @buf: pointer to arrays of characters or strings.
 * @num: number elements in buffer or buf
 * @s: pointer to head node of the stack.
 * Return: void
*/
void handle_memory(create_cmd *h, char **buf, int num, stack_t *s)
{
	free(h);
	if (buf != NULL)
		free_input_array(buf, num);
	_free_stack(s);
}
