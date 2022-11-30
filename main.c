#include "simple_shell.h"
int main(int ac __attribute((unused)), char ** av __attribute((unused)),  char **env)
{
	char *ptr = NULL, **tokens = NULL;
	size_t n = 0;
	int flag;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		flag = getline(&ptr, &n, stdin);

		if (flag == EOF) /* Controls the exit with Ctrl-d */
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

		comp_exec(tokens, env);
		free(ptr);
		ptr = NULL;
	}
	free(ptr);
	ptr = NULL;
	return (0);
}
