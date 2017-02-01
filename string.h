//
// Created by Arnold Balliu on 1/31/17.
//

#include "helpers.h"

#ifndef ARNSHELL_STRING_H
#define ARNSHELL_STRING_H

#endif //ARNSHELL_STRING_H

typedef struct sString* String;

String string_init(char* str);
String string_init_empty();
String string_append(String s, char* item);
char* string_char_at(String s, int index);
int string_size(String s);
int string_char_index(String s, char c);
String string_copy(String dest, char* src);
String string_cut(String s, int index);
String string_dup(String s);
void string_print(String s);
void string_destroy(String s);
String* string_tokenize(String input, char delim);
BOOLEAN string_is_empty(String s);
String string_trim_leading(String s);
String string_trim_trailing(String s);
String string_trim(String s);

