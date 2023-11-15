#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if it fails.
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *dub;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;
	dub = (char *)malloc((i + 1) * sizeof(char));
	if (dub == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		dub[i] = str[i];
	}
	dub[i] = '\0';
	return (dub);
}

/**
 * _strlen - Calculates the length of a string
 * @s: The string to calculate the length of
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int  length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}


/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = src[j];
	return (dest);
}

/**
 * _strcpy - Copies a string from source to destination
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

