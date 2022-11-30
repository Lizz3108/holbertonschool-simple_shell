#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h> /* Write, Fork, Execve, Isatty*/
#include <stdio.h> /* Getline */
#include <string.h> /* Strtok */
#include <sys/types.h> /* Fork, Wait */
#include <stdlib.h> /* Exit */
#include <sys/wait.h> /* Wait */

int execution(char **tokens);
char **tokenization(char *str, char *delim);

/* Auxiliar Functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *coparing, char *compare);

#endif
