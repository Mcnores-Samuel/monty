#include "monty.h"

/**
 * _free_stack - frees the stack.
 * @stack: double pointer to the head node of the stack.
 * Return: void.
 */
void _free_stack(stack_t *stack)
{
	stack_t *current_item;

	while (stack != NULL)
	{
		current_item = stack;
		stack = stack->next;
		free(current_item);
	}
}

/**
 * free_input_array - frees an Array holding the input from the file.
 * @buffer: the array or pointer to the array of strings.
 * @size: number of elements in a buffer.
 * Return: void.
 */
void free_input_array(char **buffer, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(buffer[i]);
	free(buffer);
}
