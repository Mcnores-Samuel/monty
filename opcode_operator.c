#include "monty.h"

int n = 0;

/**
 * push - pushes an element to the stack
 * @stack: double to the head node of the stack.
 * @num: data or number for the new element.
 * Return: void.
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
 * Return: void.
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

int pint(stack_t **stack, unsigned int num __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n + 1);
		return (-1);
	}
	else
		printf("%d\n", tmp->n);
	return (1);
}
