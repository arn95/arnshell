//
// Created by Arnold Balliu on 1/31/17.
//

#ifndef ARNSHELL_HELPERS_H
#define ARNSHELL_HELPERS_H

#define TRUE 1
#define FALSE 0
#define BOOLEAN int
#define EQUAL 0

#ifndef NULL
#define NULL 0
#endif

void abort1(char *);
void *check_malloc(int);
void *check_realloc(void *, int);

#endif //ARNSHELL_HELPERS_H
