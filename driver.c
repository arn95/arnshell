//
// Created by Arnold Balliu on 1/31/17.
//

#include <stdlib.h>
#include <printf.h>
#include <memory.h>
#include <zconf.h>
#include "driver.h"
#include "helpers.h"
#include "memwatch.h"
#include "string.h"

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
        printf("%s λ ", prog_name);
        int size = 0; int* size_p; size_p = &size;

        char** tokens = parse_cmd(size_p);

        if (tokens != NULL){
            status = run_proc(tokens, *size_p);
            if (status == INVALID_CMD){
                printf("%s λ ", prog_name);
                fprintf(stdout, "%s\n", "Invalid command");
            }

            int i;
            for(i = 0; i<*size_p; i++){
                free(tokens[i]);
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
        if(c == EOF || c == '\n'){
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
    //char** tokens = string_tokenize("   cat memwatch.log    ", ' ', size_p);
    if (strlen(cmd_store) > 0){
        char** tokens = string_tokenize(cmd_store, ' ', size_p);
        free(cmd_store);
        return tokens;
    }

    free(cmd_store);
    return NULL;
}


int cat(char* path){
    char linebuf[4096];
    FILE *file = fopen(path, "r");
    if (file != NULL){
        while (fgets(linebuf, sizeof(linebuf), file)) {
            fprintf(stdout, "%s", linebuf);
        }
        fprintf(stdout, "\n");
    } else {
        fprintf(stdout,"%s\n", "File specified cannot be opened\n");
    }
}

int echo(char* thing){
    fprintf(stdout, "%s\n", thing);
}

int run_proc(char* argv[], int argc){
    if (argc != 0){
        if (argc == 1){
            if (strcmp(argv[0], "exit") == 0) {
                exit(1);
            }
        } else if (argc == 2){
            if (strcmp(argv[0], "cat") == 0){
                return cat(argv[1]);
            }
            if (strcmp(argv[0], "echo") == 0){
                return echo(argv[1]);
            }
        }
        return INVALID_CMD;
    }
    return NO_CMD;
}