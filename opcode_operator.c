#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double to the head node of the stack.
 * @num: data or number for the new element.
 * Return: void.
 */
void push(stack_t **stack, unsigned int num)
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
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the head node of the stack.
 * @n: unused value.
 * Return: void.
 */
void pall(stack_t **stack, unsigned int n __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
