#include "simple_shell.h"
/**
 * execution - This function was manage the execution of command
 * @tokens: our command line already tokenized.
 * Return: upon failure it will return , otherwise 1.
 */
int execution(char **tokens, char **env)
{
	int status, i = 0;
	pid_t child_pid = fork();

	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("Execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	return (1);
}
