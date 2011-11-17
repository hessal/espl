#ifndef DIFF_H
#define DIFF_H

#include <stdio.h>

/** difference definition */
struct diff {
    long offset; /* offset of the difference in file */
    int old,     /* old value of the byte */
        new;     /* new value of the byte */
};

/* print the difference line to the stream */
int fputdiff(FILE *stream, struct diff *diff);

/* parse the difference line */
struct diff *parsediff(char *s, struct diff *diff);

#endif