# monty
## free_malloc.c

```
  _free_stack - frees the stack.
  @stack: double pointer to the head node of the stack.
  Return: void.
 
```
```
  free_input_array - frees an Array holding the input from the file.
  @buffer: the array or pointer to the array of strings.
  @size: number of elements in a buffer.
  Return: void.
 
```
## get_op_fun.c

```
  get_stack_operator - looks for the opcode matching the str.
  @instruct: the string to match or opcode instructions.
  Return: pointer to the function of the matching opcode instruction.
 
```
## handle_opcode_instruct.c

```
  is_int - checks is input string contains integers
  @h: pointer to head node containing opcode instructions.
  @n: line number of the instruction in a file.
  @buf: pointer to arrays of characters or strings.
  @num: number elements in buffer or buf
  @s: pointer to head node of the stack.
  Return: 0 if contains integer or -1 otherwise.
 
```
```
  add_stack_element - adds an item of element to the stack.
  @size: number of element in buffer array.
  @buffer: pointer array of strings of the buffer location in memory.
  Return: void
 
```
```
  process_file_instructions - processes the input from the file to read from.
  @file: pointer to the input file of instructions
  Return: void.
 
```
```
  handle_memory - frees all memory allocated if unexpexted behaviour occured.
  @h: pointer to head node containing opcode instructions.
  @buf: pointer to arrays of characters or strings.
  @num: number elements in buffer or buf
  @s: pointer to head node of the stack.
  Return: void

```
## monty.c

```
  main - entry point of the monty function.
  @argc: argument count.
  @argv: pointer to array of command line arguments
  Return: o on success or error is set appropriately.
 
```
## opcode_operator1.c

```
  add - adds the top two elements of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 on success or -1 otherwise.
 
```
```
  nop - doesn't do anything.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 signalling success.
 
```
```
  sub - subtracts the top two elements of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 on success or -1 otherwise.
 
```
```
  _div - devides the top two elements of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 on success or -1 otherwise.
 
```
```
  mul - multiplies the top two elements of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 on success or -1 otherwise.
 
```
## opcode_operator2.c

```
  mod - computes the rest of the division of the second top
  element of the stack by the top element of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line numbers from the instruction file.
  Return: 1 on success or -1 otherwise.
 
```
```
  pchar - Prints the char at the top of the stack,
  followed by a new line.
  @stack: double pointer to head node of the stack.
  @num: unused number.
  Return: 1 on success or -1 otherwise
 
```
```
  pstr - prints the string starting at the top of the stack.
  @stack: double pointer to head node of the stack.
  @num: unused number.
  Return: 1 on success, never fails.
 
```
```
  rotl -rotates the stack to the top
  @stack: double pointer to head node of the stack.
  @num: unused number.
  Return: 1 on success, never fails.
 
```
```
  rotr - rotates the stack to the bottom.
  @stack: double pointer to head node of the stack.
  @num: unused number.
  Return: 1 on success, never fails.
 
```
## opcode_operator.c

```
  push - pushes an element to the stack
  @stack: double to the head node of the stack.
  @num: data or number for the new element.
  Return: 1 on success.
 
```
```
  pall - prints all the values on the stack,
  starting from the top of the stack.
  @stack: double pointer to the head node of the stack.
  @n: unused value.
  Return: number of elements in the stack
 
```
```
  pint - prints the value at the top of the stack
  followed by a new line.
  @stack: double pointer to head node of the stack.
  @num: unused number.
  Return: 1 on success or -1 otherwise
 
```
```
  pop - removes the top element of the stack.
  @stack: double pointer to the head node of the stack.
  @num: line number i the instruction file.
  Return: 1 on success or -1 otherwise and error is set.
 
```
```
  swap -  swaps the top two elements of the stack.
  @stack: double pointer to head node of the stack.
  @num: line number from the instruction file.
  Return: 1 if success or -1 otherwise.
 
```
## parse_opcode_instruct.c

```
  break_input_line - breaks the input line and creates tokens.
  @line: pointer to line of af strings to break.
  @separator: pointer to the token separator.
  Return: array of individual words from an input line.

```
```
  process_args - processes the arguments by allocating memory for every
  command and all its arguments.
  @opcode: double pointer to a opcode.
  @data: pointer to pointer to the data field from the input line.
  @line_ptr: pointer to input line to craete opcode and value from.
  @delim: pointer to separator for the line to indivudual worlds.
  Return: nothing.

```
```
  parse_opcode - breaks down a input line into individual strings.
  and creates a node.
  @head: pointer to head node.
  @line_ptr: pointer to the input line.
  @delim: pointer to the separator
  Return: node created.

```
## remove_spaces.c

```
  remove_reading_space - removes extra space characters
  @buffer: double pointer to the location reading characters from
  @line: pointer to the location writing the cleaned characters
  Return: void
 
```
## string_fun1.c

```
  _strlen - calculates the string length.
  @string: the string.
  Return: number bytes or character in the string.

```
```
  _strcmp - compares two strings.
  @str1: first string to compare
  @str2: second string to compare with.
  Return: 0 on success or any other number on failure.

```
```
  _strncmp - compares specified number of bytes in two strings.
  @str1: first string.
  @str2: second string.
  @n: number of bytes to compare.
  Return: 0 on success or random number on failure.

```
```
  _strcat - appends a string at the end of another string.
  @dest: The string to append to.
  @src: source string to be appended.
  Return: pointer to resulting string dest.

```
```
  _strdup - duplicates a string.
  @str: string to duplicate.
  Return: pointer to the duplicate string.

```
## string_fun2.c

```
  _strncpy - copies n bytes of string src to dest.
  @dest: pointer to string destination.
  @src: pointer to string source.
  @n: number of bytes to copy from src to dest.
  Return: pointer to the destination string.

```
```
  _strstr - finds the first occurrence of the substring in the main string.
  @mainstr: pointer to the main string.
  @substr: pointer to substring
  Return: a pointer to the beginning of the located substring,
  or NULL if the substring is not found.

```
```
  _strcpy - copy a string from source to destination
  @destination: where the string is copied to
  @source: where the string is copied from
  Return: pointer to the destination
 
 
```
```
  _puts - function prints strings and prints a new line aftre
  @str: pointer to strings of character
 
  Return: Void
 
```
```
  _putchar - writes the character c to stdout
  @c: The character to print
 
  Return: On success 1.
  On error, -1 is returned, and errno is set appropriately.
 
```

