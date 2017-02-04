//
// Created by Arnold Balliu on 1/31/17.
//

#include "helpers.h"

#ifndef ARNSHELL_STRING_H
#define ARNSHELL_STRING_H

#endif //ARNSHELL_STRING_H


int string_char_index(char*, char);
char** string_tokenize(char* input, char delim, int* size, int mode);
char* string_trim_leading(char*);
char* string_trim_trailing(char*);
char* string_trim(char*);
char* string_cut(char* s, char** slice, int index);
BOOLEAN string_is_empty(char* s);


