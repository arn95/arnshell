//
// Created by Arnold Balliu on 1/31/17.
//

#include <memory.h>
#include <stdlib.h>
#include <printf.h>
#include "string.h"
#include "helpers.h"

struct sString{
    int size;
    char* buffer;
};

#define STRING_SIZE (sizeof(struct sString))

String string_init(char* str){
    int size = (int) strlen(str);
    String s = (String) check_malloc(STRING_SIZE);
    s->buffer = check_malloc(size*sizeof(char));
    strcpy(s->buffer, str);
    s->size = size;
    return s;
}

String string_init_empty(){
    int size = 1;
    String s = (String) check_malloc(STRING_SIZE);
    s->buffer = check_malloc(size*sizeof(char));
    s->size = size;
    return s;
}



String string_append(String s, char* item){
    int new_size = (int) (s->size + strlen(item)) * sizeof(char);
    s->buffer = check_realloc(s->buffer, new_size);
    s->size = new_size;
    strcat(s->buffer, item);
    return s;
}

int string_char_index(String s, char c){
    char* p;
    int count = 0;
    for(p = s->buffer; *p != '\0'; p++){
        if (p[0] == c){
            return count;
        }
        count++;
    }
    return -1;
}

String string_cut(String s, int index){
    char* p;
    int count = 0;
    char store[index+1];
    for(p=s->buffer; *p != '\0'; p++){
        char c_now = p[0];
        if(count == index){
            s->buffer = p;
            break;
        }
        store[count] = p[0];
        count++;
    }
    store[++count] = '\0';
    return string_init(store);
}

String string_copy(String dest, char* src){
    int new_size = (int) (dest->size + strlen(src)) * sizeof(char);
    dest->buffer = check_malloc(new_size);
    dest->size = new_size;
    strcpy(dest->buffer, src);
    return dest;
}

String string_dup(String s){
    String new = string_init(s->buffer);
    return new;
}

char* string_char_at(String s, int index){
    return strchr(s->buffer, index);
}


char* string_buffer(String s){
    return s->buffer;
}

int string_size(String s){
    return s->size;
}

void string_print(String s){
    printf("%s", s->buffer);
}

void string_destroy(String s){
    free(s);
}

String* string_tokenize(String input, char delim){
    String* string_array = check_malloc(input->size* sizeof(String));
    String input_dup = string_dup(input);
    //preliminary cleanup
    string_trim(input_dup);
    int count = 0;
    while(1){
        int index = string_char_index(input_dup, delim);
        if (index == -1){
            break;
        } else if (index == 0){
            string_trim_leading(input_dup);
        } else {
            String cut_string = string_cut(input_dup, index);
            string_array[count++] = cut_string;
        }
    }
    if (!string_is_empty(input_dup)){
        string_array[count] = string_dup(input_dup);
        string_destroy(input_dup);
    }

    return string_array;
}

String string_trim_leading(String s){
    while (isspace(*s->buffer)){
        s->buffer++;
    }
    return s;
}

String string_trim_trailing(String s){
    char* end = s->buffer + strlen(s->buffer) - 1;
    while(end > s->buffer && isspace((unsigned char)*end)) end--;
    *(end+1) = 0;
    return s;
}

String string_trim(String s){
    string_trim_leading(s);
    string_trim_trailing(s);
    return s;
}

BOOLEAN string_is_empty(String s){
    if(*s->buffer != '\0' || *s->buffer != ' ')
        return FALSE;
    else
        return TRUE;
}


