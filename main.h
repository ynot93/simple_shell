#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

void exec_cmd(char **argv, char **envp);
char *find_executable_path(char *cmd, char *original_path);
int is_interactive(void);
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);
void init_buffer(char **line_ptr, size_t *n);
void extend_buffer(char **line_ptr, size_t *n, size_t i);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *var_name);
char *str_tolower(const char *str);

/*String functions*/
int _strlen(char *string);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *string1, char *string2);
int _strcspn(char *string1, char *string2);
char *_strdup(const char *string);
char *_strchr(const char *string, char c);
int _strncmp(const char *string1, const char *string2, size_t n);
#endif
