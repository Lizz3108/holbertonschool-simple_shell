#include "simple_shell.h"
int main(int ac __attribute((unused)), char ** av __attribute((unused)),  char **env)
{
	char *ptr = NULL, **tokens;
	size_t n = 0;
	int status = 1;
	unsigned int i;

	while (status)
	{
		write(1, "$ ", 2);
		getline(&ptr, &n, stdin);

		tokens = tokenization(ptr, " \n");

		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(ptr);
			break;
		}

		
		if (_strcmp(tokens[0], "env") == 0)
		{
			for (i = 0; env[i]; i++)
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
			}
			free(ptr);
			break;
		}

		if (strcmp(ptr, "0x03\n") == 0)
		{
			free(ptr);
			break;
		}

		status = execution(tokens);
	}
	return (0);
}
