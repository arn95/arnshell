//
// Created by Arnold Balliu on 1/31/17.
//

#include <memory.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "helpers.h"
#include "string.h"

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

String* tokenize(String input, char delim){
    String* string_array = check_malloc(10* sizeof(String));
    String input_dup = string_dup(input);
    int count = 0;
    while(1){
        int index = string_char_index(input_dup, ' ');
        if (index == -1)
            break;
        String cut_string = string_cut(input_dup, index);
        string_array[count++] = cut_string;
    }
    return string_array;
}
