#include <stdlib.h>
#include <stdio.h>
#include "font.h"

void prsym(int idx) {
	int iline;
	char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
	for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
		printf("%s\n", (*symbol)[iline]);
}


int main(int argc, char **argv) {
	switch(argc) {
	case 1: {
			int idx;
			for(idx = 0;; ++idx) {
				if(!alphabet[idx][0])
					break;
				prsym(idx);
			}
		}
		break;
	case 2:
		prsym(atoi(argv[1]));
		break;
	default:
		printf("print all available symbols or a symbol by the given index in ASCII art.\n\nusage: %s [symbol-index]\n", argv[0]);
		return 1;
	}
	return 0;
}
