//
// Created by Arnold Balliu on 1/31/17.
//

#include <stdlib.h>
#include <printf.h>
#include <memory.h>
#include "driver.h"
#include "helpers.h"
#include "memwatch.h"
#include "string.h"

const char* prog_name = "arnshell";

int main(int argc, char* argv[]){
//    String s = string_init("     hello        world what's up everybody yeee     ahh     ");
//    int size = 0;
//    int* size_p;
//    size_p = &size;
//    String* str_a = string_tokenize(s, ' ', size_p);
//    int i;
//    printf("Tokens\n");
//    for(i = 0; i<=*size_p; i++){
//        printf("%s\n", string_buffer(str_a[i]));
//        string_destroy(str_a[i]);
//    }
//    free(str_a);
//    string_destroy(s);
    run_shell(argc, argv);
}

int run_shell(int argc, char* argv[]){
    printf("%s λ ", prog_name);
    int size = 0; int* size_p; size_p = &size;
    char** tokens = parse_cmd(size_p);
    int i;
    printf("Tokens\n");
    for(i = 0; i<*size_p; i++){
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}

char** parse_cmd(int* size_p){
//    int BUFFER_SIZE = 100;
//    char* cmd_store = (char*)check_malloc(BUFFER_SIZE* sizeof(char));
//    int count = 0;
//    while(1){
//        int c = getchar();
//        if(c == EOF){
//            cmd_store[count] = 0;
//            break;
//        }
//        cmd_store[count] = (char)c;
//        if (count == BUFFER_SIZE - 2){
//            BUFFER_SIZE += BUFFER_SIZE;
//            cmd_store = (char*)check_realloc(cmd_store, BUFFER_SIZE);
//        }
//        count++;
//    }
    char** tokens = string_tokenize("hello asd sad dsa  as asd asd as das", ' ', size_p);
    //char** tokens = string_tokenize(cmd_store, ' ', size_p);
    //free(cmd_store);
    return tokens;
}


int cat(char* path){
    int pos = 0;
    char char_read;
    FILE* tty = fopen("/dev/tty", "r+");
    if (tty == NULL){
        fprintf(stderr,"%s", "/dev/tty cannot be opened\n");
        return FALSE;
    }
    FILE* current_file = fopen(path, "r");
    if (current_file == NULL){
        fprintf(stderr,"%s", "File cannot be opened\n");
        return FALSE;
    }

    while (pos++){
        char_read = (char) fgetc(current_file);
        fputc(char_read, tty);
    }

    fclose(tty);
    fclose(current_file);
    return TRUE;
}

int echo(){

}

void run_proc(){

}