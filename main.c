#include "simple_shell.h"
/**
 * main - it run our infiite loop for the shell
 *
 * @ac: argument count
 * @av: argument vector
 * @env: enviorment
 *
 * Return: always return 0.
 *
 * Description: This program runs in a infinite loop. Inside this loop we
 * checked it we are in interactive mode, if so we print the prompt. Then
 * we processed to get the command inputed by the user. That input is cross
 * checked to see if they press the Ctrl-d command. If of the program will
 * print a new line and exit. Otherwise it will checke it the input is a new
 * line (the user just pressed enter), if so she will print the prompt.
 * Afterwards we tokenize the command, then we check if its a built-in,
 * otherwise we execute the commmand, and then free for next use.
 */
int main(int ac, char **av,  char **env)
{
	char *ptr = NULL, **tokens = NULL;
	size_t n = 0;
	int flag;

	(void) ac;
	(void) av;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		flag = getline(&ptr, &n, stdin);

		if (flag == EOF)
		{
			free(ptr);
			exit(EXIT_SUCCESS);
		}
		if (ptr[0] == '\n')
		{
			free(ptr);
			ptr = NULL;
			continue;
		}

		tokens = tokenization(ptr, " \n");
		comp_exec(tokens, ptr, env);

	}
	return (0);
}
