//
// Created by Arnold Balliu on 1/31/17.
//

#include <stdlib.h>
#include <printf.h>
#include <memory.h>
#include "driver.h"
#include "helpers.h"
#include "tokenizer.h"

int main(int argc, char* argv[]){
    //run_shell(argc, argv);
    //printf("%s", tokenize("hello world", ' '));
    //char** result = tokenize("hello world", ' ');
    String s = string_init("     hello        world what's up everybody yeee     ahh     ");
    String* str_a = string_tokenize(s, ' ');
    string_print(str_a[0]);
    string_print(str_a[1]);
    string_print(str_a[2]);
    string_print(str_a[3]);
    string_destroy(s);
}

int run_shell(int argc, char* argv[]){
    char* user_input = (char*) malloc(100*sizeof(char));
    while (1){

    }
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

char** parse_cmd(){

}

void run_proc(){

}