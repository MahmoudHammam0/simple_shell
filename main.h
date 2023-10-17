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
int executioner(char **cmd, char **argv, int g);
char *get_path(char *str);
int path_check(char *s);
char **tokenizer(char *input);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_getenv(char *s);
int execute_builtin(char **s, char **argv, int *stat, int *env, int g);
void exit_func(char **cmd, char **argv, int *stat, int *env, int g);
void printenv(void);
char *_stcpy(char *dest, char *src);
int tok_num(char *str2);
void _free(char **cmd);
int cmd_check(char *s);
void print(char *s);
char *num_to_char(int n);
void _error(char *s, char **argv, int g);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _atoi(char *s);
char *_setenv(char **cmd, int *env);
void new_env(char *str, int *env);
int _unsetenv(char **cmd, int *env);
void built_in0(char **cmd, int *env);
void built_in1(char **cmd, int *env);
void built_in2(char **cmd, int *env, char **argv, int g);
int _cd(char **cmd, int *env);
char *env_pwd(char *new, int *env);
char *env_owd(char *old, int *env);
void env_update(char *new, char *curr, int *env);
char *path(char *curr_path, char *dir);
void cd_error(char **cmd, char **argv, int g);

#endif
