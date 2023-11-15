#ifndef MAIN_H
#define MAIN_H

#define MAX_TOKENS 1024
#define PROMPT "myShell$ "

extern char **environ;

#include <stdio.h>      /* getline, */
#include <unistd.h>     /* isatty, fork, read, write, execve */
#include <stdlib.h>
#include <string.h>     /* strtok */
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

char *my_getline(void);
char **get_arrayOfTokens(char *input);
void free_2D_array(char **array2D);
int executor(char **arrayOfTokens, char **argv);
char *getEnvironmentValue(char *variableName);
char *get_Path_1st_arg(char *first_arg);


/* str_functions */
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);





char *handle_first_arg(char *first_arg);



#endif /* MAIN_H */

