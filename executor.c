#include "main.h"

/**
 * executor - Execute a command with arguments.
 *
 * @arrayOfTokens: An array of command and arguments.
 * @argv: An array of strings representing the program's arguments.
 *
 * Return: The exit status of the executed command.
 */
int executor(char **arrayOfTokens, char **argv)
{
	int status;
	/*char *path_1st_arg = get_Path_1st_arg(arrayOfTokens[0]);*/
	pid_t pid;
	(void)argv;

	pid = fork();
	if (pid == 0)
	{
		if (execve(arrayOfTokens[0], arrayOfTokens, NULL) == -1)
		{
			perror(argv[0]);
			/*free_2D_array(arrayOfTokens);*/
			/*free(path_1st_arg);*/
			/*path_1st_arg = NULL;*/
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process*/
		wait(&status);
		/*free_2D_array(arrayOfTokens);*/
		/*free(path_1st_arg);*/
		/*path_1st_arg = NULL;*/
	}
	return (WEXITSTATUS(status));
}
