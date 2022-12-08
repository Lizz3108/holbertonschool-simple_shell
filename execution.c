#include "simple_shell.h"
/**
 * execution - function that compares our string and execute the command.
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
int execution(char **tokens,  char **env)
{
	int status, i;
	pid_t child_pid;
	char *path_tok, **cmd;
	struct stat buffer;

	if (stat(tokens[0], &buffer) != 0)
	{
		path_tok = path(env);
		cmd = tokenization(path_tok, ":");
		for (i = 0; cmd[i] != NULL; i++)
			printf("%s\n", cmd[i]);
		tokens[0] = add_path(tokens, cmd);
		if (stat(tokens[0], &buffer) != 0)
		{
			free_array(tokens);
			perror("cmd not found");
			return (0);
		}
	}

	child_pid = fork();
	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
			perror("./hsh");
	}
	else
		wait(&status);
	free_array(tokens);
	return (1);
}
