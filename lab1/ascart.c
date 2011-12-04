#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "font.h"

int main(int argc, char **argv) {
    int idx,i,j,size;
    int iline;
    int ans;
    int idx2=(int)' '-32;
    
    for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline){
	for(i=1;i<argc;++i){
	    size=strlen(argv[i]);
	    for(j=0;j<size;++j){
	      //printf("%d\n",(int)argv[i][j]+100);
		//idx=(int)argv[i][j]-32;
		idx=(int)argv[i][j]-32;
		char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
		printf("%s", (*symbol)[iline]);
	    }
	    printf("%s", alphabet[idx2][iline]);
	}
	printf("\n");
     }
    return 0;
}
    