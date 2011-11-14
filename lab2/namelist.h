#ifndef NAMELIST_H
#define NAMELIST_H

/** expanding array based implementation of name list;
    the names are stored in an array, which is expanded 
	dynamically when necessary */

/** maximum name length+1, according to the C standard */
#define NAMELEN 64

/** single name statistics */
struct namestat {
	char name[NAMELEN];     /* the name */
	int count;              /* number of occurences */
};

/** list of name statistics */
struct namelist {
	int capacity;           /* maximum capacity, used internally */
	int size;               /* actual size, first size members of names are used */
	struct namestat *names; /* array of name statistics */
};

typedef struct namelist *namelist;

/** allocate a new namelist, to free first free ->names, then namelist */
namelist make_namelist();

/** add a new or already registered name to the list */
void add_name(namelist nl, char *name);

#endif