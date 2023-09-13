#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void exec_cmd(char **argv, char **envp);
/*char *create_path(const char *dir, const char *cmd);*/
char *find_executable_path(char *cmd, char *original_path);

#endif
