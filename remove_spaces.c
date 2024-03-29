#include "monty.h"

/**
 * remove_reading_space - removes extra space characters
 * @buffer: double pointer to the location reading characters from
 * @line: pointer to the location writing the cleaned characters
 * Return: void
 */

int remove_reading_space(char *buffer, char *line)
{
	int i, n, count;

	for (i = 0; i < _strlen(buffer); i++)
		if (buffer[i] != ' ' && buffer[i] != '\0')
			break;

	if (buffer[i] == '\0' || buffer[i] == '#')
	{
		_strcpy(line, "void");
		return (0);
	}
	for (n = 0; buffer[i] != '\0'; n++)
	{
		if (buffer[i] == ' ')
		{
			if (buffer[i + 1] == ' ')
			{
				line[n] = buffer[i];
				for (count = i + 1; buffer[count] != '\0'; count++)
				{
					if (buffer[count] != ' ')
					{
						n++;
						break;
					}
				}
				i = count;
				line[n] = buffer[i];
			}
		}
		line[n] = buffer[i];
		i++;
	}
	line[n] = '\0';
	return (_strlen(line));
}
