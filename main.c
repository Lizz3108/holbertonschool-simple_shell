#include "simple_shell.h"
int main(int ac __attribute((unused)), char ** av __attribute((unused)),  char **env)
{
	char *ptr = NULL, **tokens;
	size_t n = 0;
	int status = 1;
	unsigned int i = 0;

	while (status)
	{
		write(1, "$ ", 2);
		getline(&ptr, &n, stdin);

		if (_strcmp(ptr, "exit\n") == 0)
		{
			free(ptr);
			break;
		}
		
		if (_strcmp(ptr, "env\n") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
			free(ptr);
			break;
		}

		if (strcmp(ptr, "0x05\n") == 0)
		{
			free(ptr);
			break;
		}

		tokens = tokenization(ptr, " \n");

		status = execution(tokens);
	}
	return (0);
}
