#include "monty.h"

int add(stack_t **stack, unsigned int num)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
	}

	num = (*stack)->n + (*stack)->next->n;
	printf(" after add: %d\n", num);
	return (1);
}
