#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

#define DELIMITER " \t\r\n"
#define BUFF_SIZE 1024
#define MAX_INPUT_LENGTH 1024
#define MAX_COMMAND_LENGTH 100

extern __signalhandler_t signal(int __signal, __signalhandler_t __handler);
extern char **environ;

void loop(void);
char *get_input(void);
char **split_tokens(char *input);
int exe_cmds(char **args, int line_num, char *prog_name);
void kpsh_esit(char **args);
int get_num_args(char **args);
void change_dir(char **args);
void set_env(char **args);
void unset_env(char **args);
char *handle_path(char **args);



/* custom functions */
int print_prompt(void);
void signal_handler(int n);


/* custom functions in helper files */
void *_realloc(void *ptr, unsigned int new_size);
char *_strdup(const char *str);

/* sub custom functions */

void *_memcpy(char *dest, const void *src, size_t n);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);

#endif
