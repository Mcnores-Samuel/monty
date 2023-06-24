#include "monty.h"

/**
 * break_input_line - breaks the input line and creates tokens.
 * @line: pointer to line of af strings to break.
 * @separator: pointer to the token separator.
 * Return: array of individual words from an input line.
*/
char *break_input_line(char *line, char *separator)
{
	static char *input_line, words_array[64][20];
	static int word_count;
	char *ptr_start, *ptr_end;
	int len;

	if (line != NULL)
	{
		input_line = line;
		word_count = 0;
	}

	if (input_line == NULL)
		return (NULL);

	ptr_start = input_line;
	ptr_end = _strstr(input_line, separator);

	if (ptr_end == NULL)
		ptr_end = input_line + _strlen(input_line);

	len = ptr_end - ptr_start;
	_strncpy(words_array[word_count], ptr_start, len);
	words_array[word_count][len] = '\0';
	word_count++;

	if (word_count == 64)
		return (NULL);

	if (*ptr_end == '\0')
		input_line = NULL;
	else
		input_line = ptr_end + _strlen(separator);

	return (words_array[word_count - 1]);
}

/**
 * process_args - processes the arguments by allocating memory for every
 * command and all its arguments.
 * @opcode: double pointer to a opcode.
 * @data: pointer to pointer to the data field from the input line.
 * @line_ptr: pointer to input line to craete opcode and value from.
 * @delim: pointer to separator for the line to indivudual worlds.
 * Return: nothing.
*/
void process_args(char **opcode, char **data, char *line_ptr, char *delim)
{
	char *token;

	token = break_input_line(line_ptr, delim);

	while (token != NULL)
	{
		if (token == NULL)
			break;
		if (*opcode == NULL)
		{
			if (_strcmp(token, "pall") == 0)
			{
				*opcode = token;
				break;
			}
			*opcode = token;
		}
		else
			if (*data == NULL)
				if (token != NULL)
					*data = token;

		token = break_input_line(NULL, delim);
	}
}

/**
 * parse_opcode - breaks down a input line into individual strings.
 * and creates a node.
 * @head: pointer to head node.
 * @line_ptr: pointer to the input line.
 * @delim: pointer to the separator
 * Return: node created.
*/
int parse_opcode(create_cmd **head, char *line_ptr, char *delim)
{
	create_cmd *new_node = NULL;

	if (*line_ptr == '\0' || line_ptr == NULL)
		return (-1);

	new_node = (create_cmd *)malloc(sizeof(create_cmd));

	if (new_node == NULL)
	{
		fprintf(stderr, "%s\n", MALLLOC_ERR);
		exit(EXIT_FAILURE);
	};

	new_node->opcode = NULL;
	new_node->data = NULL;

	if (*head == NULL)
	{
		process_args(&(new_node->opcode), &(new_node->data), line_ptr, delim);
		new_node->next = *head;
		*head = new_node;
	}

	if (_strcmp((*head)->opcode, "void") == 0)
		return (-1);
	return (1);
}
