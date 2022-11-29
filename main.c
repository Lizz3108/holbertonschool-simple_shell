#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 */
int main()
{
	size_t bufsize = 200, user_input;
	char *tokens, *buffer = malloc(sizeof(char) * bufsize);

	while(1)
	{
		printf("$ ");
		user_input = getline(&buffer, &bufsize, stdin);
	}
	return(0);

}
