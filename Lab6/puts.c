#include "font.h"

void puts(int i, int j){
  
      char *c= alphabet[i][j];
int length=0;
char *t = c;
while(*t) ++t;
length= t-c;
  write(1,c,length);
  
}