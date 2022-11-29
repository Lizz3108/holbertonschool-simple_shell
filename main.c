#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char *ptr = NULL, *token, **tokens = malloc(sizeof(char));
	size_t n = 0;
	int i = 0;

	while (1)
	{
		write(1, "$ ", 2);
		getline(&ptr, &n, stdin);

		token = strtok(ptr, " \n");
		while(token)
		{
			tokens[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		execve(tokens[0], &*tokens, NULL);
	}
	return (0);
}
