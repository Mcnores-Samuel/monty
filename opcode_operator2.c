#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: double pointer to the head node of the stack.
 * @num: line numbers from the instruction file.
 * Return: 1 on success or -1 otherwise.
 */
int mod(stack_t **stack, unsigned int num)
{
	int num1, num2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		return (-1);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		return (-1);
	}

	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	if (num2 > num1)
		result = num2 % num1;
	else
		result = num1 % num2;
	pop(stack, num);
	pop(stack, num);
	push(stack, result);
	return (1);
}

/**
 * pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @stack: double pointer to head node of the stack.
 * @num: unused number.
 * Return: 1 on success or -1 otherwise
 */
int pchar(stack_t **stack, unsigned int num)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		return (-1);
	}

	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		return (-1);
	}

	if (tmp->n >= 0 && tmp->n <= 127)
		printf("%c\n", tmp->n);

	return (1);
}

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: double pointer to head node of the stack.
 * @num: unused number.
 * Return: 1 on success or -1 otherwise
 */
int pstr(stack_t **stack, unsigned int num __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		printf("\n");
		return (1);
	}

	if (tmp->n > 0 && tmp->n <= 127)
	{
		while (tmp != NULL)
		{
			if (tmp->n == 0 || tmp->n < 0)
				break;
			if (tmp->n > 0 && tmp->n <= 127)
				printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	printf("\n");
	return (1);
}
