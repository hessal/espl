#include <stdlib.h>
#include <string.h>


/** initial capacity of a newly created list;
    the capacity is doubled the list becomes full */
#define INITIAL_CAPACITY 16

namelist make_namelist() {
	namelist nl = (namelist)malloc(sizeof(struct namelist));
	nl->size = 0;
	nl->capacity = INITIAL_CAPACITY;
	nl->names = (struct namestat *)malloc(INITIAL_CAPACITY*sizeof(struct namestat));
	return nl;
}

/** double the capacity of the list, used by add_name when the list is full */
static void expand_namelist(namelist nl) {
	nl->capacity*= 2;
	nl->names = (struct namestat *)realloc(nl->names, nl->capacity*sizeof(struct namestat));
}

void add_name(namelist nl, char *name) {
	int i;
	for(i = 0; i!=nl->size; ++i) {
		if(!strcmp(name, nl->names[i].name)) {
			/** found the name, increase the count and exit */
			++nl->names[i].count;
			return;
		}
	}

    /** make more space if the namelist is full */
	if(nl->size==nl->capacity)
		expand_namelist(nl);

    /** i is after the last occupied cell, use it for the name,
        and increase the size */
	strcpy(nl->names[i].name, name);
	nl->names[i].count = 1;
	++nl->size;
}
		
	
