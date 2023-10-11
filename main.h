#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
char *get_input(void);
char *_strtok(char *str, const char *delim);
char **split_string(char *input, int *num_words);
int _strlen(char *str);
char *_strcpy(char *str);
char *add_path(char *str);
int executioner(char **cmd, char **argv);
char *get_path(char *str);
int path_check(char *s);
char **tokenizer(char *input);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_getenv(char *s);
int execute_builtin(char *s);
void printenv(void);
char *_stcpy(char *dest, char *src);
int tok_num(char *str2);
void _free(char **cmd);
int cmd_check(char *s);

#endif
