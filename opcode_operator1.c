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
	int sub_num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		return (-1);
	}

	sub_num = (*stack)->n - (*stack)->next->n;

	if (sub_num > 0)
		sub_num = sub_num * -1;
	else
		sub_num = sub_num * -1;

	pop(stack, num);
	pop(stack, num);
	push(stack, sub_num);
	return (1);
}

/**
 * div - devides the top two elements of the stack.
 * @stack: double pointer to the head node of the stack.
 * @num: line numbers from the instruction file.
 * Return: 1 on success or -1 otherwise.
 */
int _div(stack_t **stack, unsigned int num)
{
	int num1, num2, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
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
		result = num2 / num1;
	else
		result = num1 / num2;
	pop(stack, num);
	pop(stack, num);
	push(stack, result);
	return (1);
}
