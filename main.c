#include "simple_shell.h"
int main(void)
{
	char *ptr = NULL, **tokens;
	size_t n = 0;
	int status = 1;

	while (status)
	{
		write(1, "$ ", 2);
		getline(&ptr, &n, stdin);

		tokens = tokenization(ptr, " \n");

		status = execution(tokens);

		free(ptr);
	}
	return (0);
}
