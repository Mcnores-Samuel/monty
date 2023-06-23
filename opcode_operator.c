#include "monty.h"

int n = 0;

/**
 * push - pushes an element to the stack
 * @stack: double to the head node of the stack.
 * @num: data or number for the new element.
 * Return: 1 on success.
 */
int push(stack_t **stack, unsigned int num)
{
	stack_t *new_elem = NULL;

	new_elem = (stack_t *)malloc(sizeof(stack_t));

	if (new_elem == NULL)
	{
		write(2, MALLLOC_ERR, _strlen(MALLLOC_ERR));
		exit(EXIT_FAILURE);
	}

	new_elem->n = num;
	new_elem->prev = NULL;
	new_elem->next = NULL;

	if (*stack == NULL)
		*stack = new_elem;
	else
	{
		new_elem->next = *stack;
		(*stack)->prev = new_elem;
		*stack = new_elem;

	}
	return (1);
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the head node of the stack.
 * @n: unused value.
 * Return: number of elements in the stack
 */
int pall(stack_t **stack, unsigned int n __attribute__((unused)))
{
	stack_t *tmp = *stack;
	int i = 0;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/**
 * pint - prints the value at the top of the stack
 * followed by a new line.
 * @stack: double pointer to head node of the stack.
 * @num: unused number.
 * Return: 1 on success or -1 otherwise
 */
int pint(stack_t **stack, unsigned int num)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		return (-1);
	}
	else
		printf("%d\n", tmp->n);
	return (1);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head node of the stack.
 * @num: line number i the instruction file.
 * @Return: 1 on success or -1 otherwise and error is set.
 */
int pop(stack_t **stack, unsigned int num)
{
	stack_t *top = *stack, *second;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		return (-1);
	}
	else
	{
		top = *stack;
		second = (*stack)->next;
		if (second == NULL)
		{
			free(top);
			*stack = NULL;
		}
		free(top);
		second->prev = NULL;
		*stack = second;
	}

	return (1);
}
