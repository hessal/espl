#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "font.h"

void print(char *s,int size1){
  write(1,s,size1);
} 



int main(int argc, char **argv) {
    int idx,i,j,size,size1,size2;
    int iline;
    int ans;
    int idx2=(int)' '-32;
    
 for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline){
    for(i=1;i<argc;++i){
       size=returnStrlen(argv[i]);
	for(j=0;j<size;++j){
	    idx=(int)argv[i][j]-32;
	    char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
	    size1=returnStrlen( (*symbol)[iline]);
	    print( (*symbol)[iline],size1);
	}
    size2=returnStrlen(  alphabet[idx2][iline]);
      printf("%s", alphabet[idx2][iline],size2);
    }
printf("\n");
     }
    return 0;
}
    