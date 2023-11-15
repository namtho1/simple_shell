#include "main.h"

/**
 * my_getline - Read a line of input from the user.
 *
 * Return: A pointer to the input line, or NULL on failure or EOF.
 */
char *my_getline(void)
{
	char *input_line = NULL;
	size_t input_line_size = 0;
	ssize_t num_chars;

	/* Check if input is coming from a terminal */
	if (isatty(STDIN_FILENO) == 1)    /*success*/
	{
		fflush(stdin);
		write(STDIN_FILENO, PROMPT, strlen(PROMPT));
	}

	num_chars = getline(&input_line, &input_line_size, stdin);
	if (num_chars == -1)
	{
		/*perror("getline");*/
		free(input_line);
		input_line = NULL;
		return (NULL);
	}
	return (input_line);
}

