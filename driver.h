//
// Created by Arnold Balliu on 1/31/17.
//

#include "string.h"

#ifndef ARNSHELL_DRIVER_H
#define ARNSHELL_DRIVER_H

#endif //ARNSHELL_DRIVER_H

int cat(char**,int);

int echo(char**,int);

char** parse_cmd(int* size_p);

int run_shell();

int run_proc(char**, int);

int sys_proc(char** argv, int argc);
