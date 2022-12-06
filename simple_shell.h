#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h> /* Write, Fork, Execve, Isatty*/
#include <stdio.h> /* Getline */
#include <string.h> /* Strtok */
#include <sys/types.h> /* Fork, Wait */
#include <stdlib.h> /* Exit */
#include <sys/wait.h> /* Wait */
#include <sys/stat.h> /* Stat */

char **tokenization(char *str, char *delim);
int execution(char **tokens, char **env);
char **path(char **env);
char *add_path(char **tokens, char **path_tok);

/* Auxiliar Functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *comparing, char *compare);
void free_array(char **tokens);
int _strncmp(char *comparing, char *compare, size_t n);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
#endif
