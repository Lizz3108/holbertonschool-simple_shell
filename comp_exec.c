#include "simple_shell.h"
/**
 * comp_exec - function that compares our string and execute the command.
 *
 * @tokens: Our array of tokens
 * @env: Our enviorment variables
 *
 * Return: Always return one
 *
 * Description: First our function will compare our token position 0
 * with the built-in (exit & env). If its not a built in he will check
 * for the command and print out the result of the execution.
 */
int comp_exec(char **tokens, char **env)
{
	unsigned int i = 0;
	pid_t child_pid;
	int j = 0, status;

	/* Built-in process start here */
	if (_strcmp(tokens[0], "exit") == 0)
		exit(0);

	/* Execution procress start here */
	child_pid = fork();

	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (_strcmp(tokens[0], "env") == 0)
		{
			while (env[i])
			{
				write(1, env[i], _strlen(env[i]));
				write(1, "\n", 1);
				i++;
			}
		}
		else if (execve(tokens[0], tokens, env) == -1)
		{
			perror("Execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
	}
	return (1);
}
