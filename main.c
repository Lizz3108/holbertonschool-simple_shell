#include "simple_shell.h"
int main(int ac __attribute((unused)), char ** av __attribute((unused)),  char **env)
{
	char *ptr = NULL, **tokens = NULL;
	size_t n = 0;
	int flag;
	unsigned int i = 0;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		flag = getline(&ptr, &n, stdin);

		/* Controls the exit with Ctrl-d */
		if (flag == EOF)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		/* If user press enter without inputting */
		if (ptr[0] == '\n')
		{
			free(ptr);
			ptr = NULL;
			write(1, "$ ", 2);
			continue;
		}

		tokens = tokenization(ptr, " \n");

		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(ptr);
			ptr = NULL;
			exit(0);
		}

		if (_strcmp(tokens[0], "env") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
			free(ptr);
			ptr = NULL;
			continue;
		}
		execution(tokens, env);

		free(ptr);
		ptr = NULL;
	}
	return (0);
}
