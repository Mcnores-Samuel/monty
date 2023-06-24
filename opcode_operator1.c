#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the head node of the stack.
 * @num: line numbers from the instruction file.
 * Return: 1 on success or -1 otherwise.
 */
int add(stack_t **stack, unsigned int num)
{
	int n = num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		return (-1);
	}

	num = (*stack)->n + (*stack)->next->n;
	pop(stack, n);
	pop(stack, n);
	push(stack, num);
	return (1);
}

/**
 * nop - doesn't do anything.
 * @stack: double pointer to the head node of the stack.
 * @num: line numbers from the instruction file.
 * Return: 1 signalling success.
 */
int nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;

	return (1);
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: double pointer to the head node of the stack.
 * @num: line numbers from the instruction file.
 * Return: 1 on success or -1 otherwise.
 */
int sub(stack_t **stack, unsigned int num)
{
	int n = num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		return (-1);
	}

	num = abs((*stack)->n - (*stack)->next->n);
	pop(stack, n);
	pop(stack, n);
	push(stack, num);
	return (1);
}
