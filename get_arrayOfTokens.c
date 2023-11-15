#include "main.h"

/**
 * get_arrayOfTokens - Tokenize an input line into an array of tokens.
 *
 * @input_line: The input line to tokenize.
 *
 * Return: A dynamically allocated array of tokens, or NULL on failure.
 */
char **get_arrayOfTokens(char *input_line)
{
	char *token;
	char **arrayOfTokens;
	int j, i = 0;

	if (!input_line)
		return (NULL);

	arrayOfTokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (arrayOfTokens == NULL)
	{
		free_2D_array(arrayOfTokens);
		perror("malloc");
		return (NULL);
	}

	token = strtok(input_line, " \n\t");
	if (token == NULL)
	{
		free(arrayOfTokens); /*Free the memory allocated for the array*/
		return (NULL);
	}
	while (token && i < MAX_TOKENS - 1)
	{
		arrayOfTokens[i] = strdup(token);  /*Duplicate the token*/
		if (arrayOfTokens[i] == NULL)
		{
			perror("strdup");
			/* Free the previously allocated tokens and the array */
			for (j = 0; j < i; j++)
			{
				free(arrayOfTokens[j]);
			}
			free(arrayOfTokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \n\t");
	}
	arrayOfTokens[i] = NULL;
	return (arrayOfTokens);
}

