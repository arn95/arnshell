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



int cat(char** paths, int size){
    int i;
    for(i = 1; i<size; i++){
        char linebuf[4096];
        FILE *file = fopen(paths[i], "r");
        if (file != NULL){
            while (fgets(linebuf, sizeof(linebuf), file)) {
                //fprintf(stdout, "%s", linebuf);
                printf(linebuf);
            }
            //fprintf(stdout, "\n");
            printf("\n");
        } else {
            perror("File cannot be opened");
        }
        fclose(file);
    }
}

int echo(char** thing, int size){
    int i;
    for(i = 1; i<size; i++){
        char* temp = thing[i];
        //fprintf(stdout, "%s", thing[i]);
        printf(thing[i]);
        if (i+1 < size){
            printf(" ");
        }
    }
    printf("\n");
    return 1;
}

int sys_proc(char** argv, int argc, int redir){

    int fd = NULL;

    int status;
    int pid;
    pid=fork();
    if(pid<0) {
        perror("Failed fork");
        exit(1);
    } else if (pid==0) {
        //printf("Child pid: %d\n",getpid());

        if (redir != -1){
            fd = creat(argv[redir+1], 0644);
            if (fd < 0){
                perror("Failed to open output file");
                exit(0);
            }
            dup2(fd,STDOUT_FILENO);
            close(fd);
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
        return 0;
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

int run_proc(char* argv[], int argc){
    int status = check_redir(argv,argc);

    if (argc != 0){
        if (strcmp(argv[0], "exit") == 0)
            exit(1);
        else {
            return sys_proc(argv, argc, status);
        }
    }
    return NO_CMD;
}
