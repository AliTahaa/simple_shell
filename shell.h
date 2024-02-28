#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIMITER " \t\n"
extern char **enviro;

char *read_all(void);
char **split_line(char *line);
int _run(char **command, char **argv, int idx);
char *_get_enviro(char *variable);
char *_get_path(char *command);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void free_arr(char **arr);

char *_itoa(int n);
void rev_string(char *str, int len);
void print_error(char *name, char *cmd, int idx);

int is_built_in(char *command);
void handle_built_in(char **command, char **argv, int status, int idx);
void exit_shell(char **command, int status);
void print_env(char **command, int status);

#endif