#include "main.h"

/**
 * main - Entry point of the shell program
 * @ac: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0
 */
int main(int ac, char **argv)
{
	char *input_line = NULL;
	/* size_t input_line_size = 0; */
	/* ssize_t num_chars; */
	char **arrayOfTokens = NULL;
	/* char *path_1st_arg; */
	(void)ac;
	/* int i */

	while (1)
	{
		input_line = my_getline();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)  /*success*/
			{
				fflush(stdin);
				write(STDIN_FILENO, PROMPT, strlen(PROMPT));
			}
			return (0);
		}

		arrayOfTokens = get_arrayOfTokens(input_line);
		free(input_line);
		input_line = NULL;
		if (arrayOfTokens == NULL)
			continue;

		executor(arrayOfTokens, argv);
		free_2D_array(arrayOfTokens);
	}
	return (0);
}


