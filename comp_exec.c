#include "simple_shell.h"
int comp_exec(char **tokens, char **env)
{
	unsigned int i = 0;
	pid_t child_pid;
	int j = 0, status;
	if (_strcmp(tokens[0], "exit") == 0)
		exit(0);

	if (_strcmp(tokens[0], "env") == 0)
	{
		while (env[i])
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}

	child_pid = fork();

	if (child_pid == -1) /* Child process have failed */
		perror("Child process failed");
	else if (child_pid == 0) /* Inside the child */
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("Execve");
			exit(EXIT_FAILURE);
		}
	}
	else /* Inside father */
	{
		wait(&status);
		while (tokens[j]) /* Free the two dimention array */
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
	}
	return (1);
}

