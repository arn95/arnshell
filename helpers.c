//
// Created by Arnold Balliu on 1/31/17.
//

#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
//#include "memwatch.h"

void abort1(char *s){
    fprintf(stderr, "%s\n", s);
    exit(-1);
}

void *check_malloc(int size){
    char *cp;
    cp = malloc(size);
    if (cp == NULL)
        abort1("check malloc: No core");
    return(cp);
}

void *check_realloc(void *p, int size){

    p = realloc(p,size);
    if (p == NULL)
        abort1("check realloc: No core");
    return(p);
}