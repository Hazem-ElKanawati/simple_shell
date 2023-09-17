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
void custom_print(const char *text);
void prchar(char x);
void prstr(char *x);
extern char **environ;
void rm_newline(char *x);
char *_strdup(char *x);
char **handle_argument(char *x);
int arg_count(const char *comm);



#endif
