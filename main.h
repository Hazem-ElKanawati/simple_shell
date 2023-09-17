#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void sstrcat(char *x, char *y);
void prchar(char x);
void prstr(char *x);
extern char **environ;
void rm_newline(char *x);
char *_strdup(char *x);
char **handle_argument(char *x);
int arg_count(const char *comm);
void execute(char **args, char **env, char *argv[]);
char **get_path(char *pathptr);
void _execute(char **args, char **env, char *comm, char *name);
int _strlen(char *x);
int _strcmp(char *x, char *y);
int _strncmp(char *x, char *y, int n);




#endif
