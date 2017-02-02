//
// Created by Arnold Balliu on 1/31/17.
//

#include <memory.h>
#include <stdlib.h>
#include <printf.h>
#include "string.h"
#include "helpers.h"
#include "memwatch.h"

int string_char_index(char* buf, char c){
    char* p;
    int count = 0;
    for(p = buf; *p != '\0'; p++){
        if (p[0] == c){
            return count;
        }
        count++;
    }
    return -1;
}

void string_cut(char** s, char** slice, int index){
    char* str = *s;
    int count = 0;
    char store[index+1];
    for(; *str != '\0'; str++){
        if(count == index){
            break;
        }
        store[count] = str[0];
        count++;
    }
    *s = str;
    store[count] = 0;
    strcpy(*slice, store);
}

char** string_tokenize(char* input, char delim, int* size){
    int len = (int)strlen(input);
    char** str_a = check_malloc(len*sizeof(char*));
    char* input_dup = strdup(input);
    //preliminary cleanup
    string_trim(input_dup);
    int count = 0;
    while(1){
        int index = string_char_index(input_dup, delim);
        if (index == -1){
            break;
        } else if (index == 0){
            input_dup = string_trim_leading(input_dup);
        } else {
            char* slice = (char*) check_malloc((index+1)* sizeof(char));
            string_cut(&input_dup,&slice, index);
            str_a[count++] = slice;
        }
    }
    if (!string_is_empty(input_dup)){
        str_a[count++] = strdup(input_dup);
        //free(input_dup);
    }
    *size = count;
    str_a = check_realloc(str_a, (count)* sizeof(char*));
    return str_a;
}

char* string_trim_leading(char* s){
    while (isspace(*s)){
        s = ++s;
    }
    return s;
}

char* string_trim_trailing(char* s){
    char* end = s + strlen(s) - 1;
    while(end > s && isspace((unsigned char)*end)) end--;
    *(end+1) = 0;
    return s;
}

char* string_trim(char* s){
    string_trim_leading(s);
    string_trim_trailing(s);
    return s;
}

BOOLEAN string_is_empty(char* s){
    if(*s != '\0')
        return FALSE;
    else
        return TRUE;
}


