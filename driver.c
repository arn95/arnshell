//
// Created by Arnold Balliu on 1/31/17.
//

#include <stdlib.h>
#include <printf.h>
#include <memory.h>
#include <zconf.h>

#include <stdio.h>
#include "driver.h"
#include "helpers.h"
#include "string.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


const char* prog_name = "arnshell";
const int INVALID_CMD = -1;
const int NO_CMD = -2;

int main(int argc, char* argv[]){
    run_shell();
    return 0;
}

int run_shell(){
    int status;
    while(1){

        printf("%s α ", prog_name);
        int size = 0; int* size_p; size_p = &size;

        char** tokens = parse_cmd(size_p);
        char* t1 = tokens[0];
        char* t2 = tokens[1];
        if (tokens != NULL){
            status = run_proc(tokens, *size_p);
            if (status == INVALID_CMD){
	        //printf("%s λ ", prog_name);
                exit(1);
            }

            int i;
            for(i = 0; i<*size_p; i++){
                char* temp = tokens[i];
                free(temp);
            }
            free(tokens);
        }
    }
    //cat("memwatch.log");
}

char** parse_cmd(int* size_p){
    int BUFFER_SIZE = 100;
    char* cmd_store = (char*)check_malloc(BUFFER_SIZE* sizeof(char));
    int count = 0;
    while(1){
        int c = getchar();
        if (c == EOF){
            exit(1);
        }
        if(c == '\n'){
            cmd_store[count] = 0;
            break;
        }
        cmd_store[count] = (char)c;
        if (count == BUFFER_SIZE - 2){
            BUFFER_SIZE += BUFFER_SIZE;
            cmd_store = (char*)check_realloc(cmd_store, BUFFER_SIZE);
        }
        count++;
    }
    //char** tokens = string_tokenize("ls -l", ' ', size_p);
    if (strlen(cmd_store) > 0){
        //testing if its echo
        char** tokens;
        char** echo_token = string_tokenize(cmd_store, ' ', size_p,1);
        if (*size_p != 0){
            if (strcmp(*echo_token, "echo") == 0){
                char** echo_args = string_tokenize(cmd_store, ' ', size_p, 2);
                char** result = (char**) check_malloc(3*sizeof(char*));
                result[0] = strdup(*echo_token);
                result[1] = strdup(*echo_args);
                free(*echo_token);
                free(*echo_args);
                free(echo_token);
                free(echo_args);
                free(cmd_store);
                //fix for execvp
                result[2] = NULL;
                *size_p = 2;
                return result;
            }
        }
        free(echo_token);
        tokens = string_tokenize(cmd_store, ' ', size_p, 0);
        if (*size_p != 0){
            //fix for execvp
            tokens[*size_p] = NULL;
            free(cmd_store);
            return tokens;
        }
    }
    free(cmd_store);
    return NULL;
}

int sys_proc(char** argv, int argc, int redir, int has_pipe){

    int status;
    int pid;

    if (has_pipe == -1){
        pid=fork();
        if(pid<0) {
            perror("Failed fork");
            exit(1);
        } else if (pid==0) {
            //printf("Child pid: %d\n",getpid());

            if (redir != -1){
                char* output = strdup(argv[redir+1]);

                //clean argv
                int i;
                for(i = redir; i<argc; i++){
                    free(argv[i]);
                    argv[i] = NULL;
                }

                int fd = creat(output, 0644);
                if (fd < 0){
                    perror("Failed to open output file");
                    exit(0);
                }
                dup2(fd,STDOUT_FILENO);
                close(fd);
                free(output);
            }

            if (argc > 1)
                status = execvp(argv[0], argv);
            else if (argc == 1) {
                argv[1] = NULL;
                argv[2] = NULL;
                status = execvp(argv[0], argv);
            }
            if (status == -1) {
                perror("Invalid command");
                return status;
            }
        } else {
            waitpid(pid,&status,0);
            if (pipe != -1){
                int pipes[2];
                dup2(pipes[1], 1);
                close(pipes[0]);
            }
            return 0;
        }
    } else {
        int pipes[2];
        pipe(pipes);
        char** argv1 = check_malloc(argc* sizeof(char*));
        char** argv2 = check_malloc(argc* sizeof(char*));
        int i;
        for (i = 0; i<has_pipe; i++){
            argv1[i] = strdup(argv[i]);
        }
        argv1[has_pipe] = NULL;
        int count = 0;
        for (i = has_pipe+1; i<argc; i++){
            argv2[count++] = strdup(argv[i]);
        }
        argv2[count] = NULL;
        int pid1 = fork();
        if (pid1 == 0) {
            close((int) stdout);
            close(pipes[0]);
            dup2(pipes[1], (int) stdout);
            execvp(argv1[0], argv1);
            for (i = 0; i<has_pipe; i++){
                free(argv1[i]);
            }
            free(argv1);
        }
        int pid2 = fork();
        if (pid2 == 0) {
            close((int) stdin);
            close(pipes[1]);
            dup2(pipes[0], (int) stdin);
            execvp(argv2[0], argv2);
            for (i = 0; i<count; i++){
                free(argv2[i]);
            }
            free(argv2);
        }

        close(pipes[0]);
        close(pipes[1]);
        waitpid(pid1, 0, 0);
        waitpid(pid2,0,0);
    }
    return 1;
}

int check_redir(char** argv, int argc){
    int i;
    for(i = 0; i<argc; i++){
        if(strcmp(argv[i], ">") == 0){
            if (i+1 < argc){
                return i;
            }
        }
    }
    return -1;
}

int check_pipe(char** argv, int argc){
    int i;
    for(i = 0; i<argc; i++){
        if(strcmp(argv[i], "|") == 0){
            if (i+1 < argc){
                return i;
            }
        }
    }
    return -1;
}

int run_proc(char* argv[], int argc){
    int redir_status = check_redir(argv,argc);
    int pipe_status = check_pipe(argv, argc);

    if (argc != 0){
        if (strcmp(argv[0], "exit") == 0)
            exit(1);
        else {
            return sys_proc(argv, argc, redir_status, pipe_status);
        }
    }
    return NO_CMD;
}
