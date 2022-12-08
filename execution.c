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
	int status;
	pid_t child_pid;
	char **path_tok;
	struct stat rawr;

	child_pid = fork();
	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (stat(tokens[0], &rawr) == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
				perror("./hsh");
			/* Handle error insert here shawty */
		}
		else
			perror("dumb");
		path_tok = path(env);
		tokens[0] = add_path(tokens, path_tok);
		if (tokens[0] != NULL || tokens != NULL)
			execve(tokens[0], tokens, env);
	}
	else
		wait(&status);
	free_array(tokens);
	return (1);
}
