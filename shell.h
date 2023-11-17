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

typedef void (*sighandler_t)(int);

extern char **environ;

void loop(void);
char *get_input(void);
char **split_tokens(char *input);
int execute_commands(char **args, int line_number, char *program_name);
void kpsh_exit(char **args);
int get_num_args(char **args);
void change_dir(char **args);
void set_env(char **args);
void unset_env(char **args);
char *handle_path(char **args);



/* custom functions */
int print_prompt(void);
void signal_handler(int n);
void free_bufs(char **buffer);
void cd_error_message(const char *message);
char *handle_special_path(char **args);
char *command_error(int line_no, char *p_name, char *cmd);
void print_error_message(int line_no, char *p_name, char *cmd);
int check_args(char **args, char *input);

/* custom functions in helper files */
void *my_realloc(void *ptr, unsigned int new_size);
char *my_strdup(const char *str);
char *my_getenv(const char *name);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int b);
int my_atoi(char *s);
const char *my_strstr(const char *haystack, const char *needle);
int my_itoa(char str, int num);

/* sub custom functions */

void *my_memcpy(char *dest, const void *src, size_t n);
char *my_strcpy(char *dest, const char *src);
size_t my_strlen(const char *s);
int my_strcmp(char *s1, char *s2);
char *my_strchr(const char *str, int ch);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
int my_putchar(int c);
int my_printf(char *format, ...);

#endif
