#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "diff.h"

int fputdiff(FILE *stream, struct diff *diff) {
    return fprintf(stream, "byte %lu -%u +%u\n",
                           diff->offset, diff->old, diff->new);
}

struct diff *parsediff(char *s, struct diff *diff) {
    char **sp = &s;
    *sp = strchr(*sp, ' '); /* skip 'byte' */
    diff->offset = strtol(*sp, sp, 10);
    diff->old = -strtol(*sp, sp, 10);
    diff->new = strtol(*sp, sp, 10);

    return diff;
}
