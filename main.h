#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;
char *get_input(void);
int num_tok(char *s);
char **tokenizer(char *input);
int _strlen(char *str);
char *_strcpy(char *str);
void free_func(char **cmd);
int executioner(char **cmd, char **argv, char *input);
#endif
