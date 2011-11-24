#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/**int ato(char *num){
 int lastDigit; 
 int value=0;
 int a=1;

 int size=strlen(num);
  int i=0;
// printf("%d",size);
 while(size>0){
   
   lastDigit=num[size-1]-'0';
  
  lastDigit=lastDigit*a;
 
  value=value+lastDigit;
 
  a=a*10;
 // num=num/10;
   size--;
  }
  return value;
}
*/
int main(int argc, char **argv) {
	int a, op, b, c;

	if(argc!=4) {
		fprintf(stderr, "usage: calc <number> [+|-|*|/] <number>\n");
		exit(1);
	}

	a = ato(argv[1]);
	op = argv[2][0];
	b = ato(argv[3]);
	switch(op) {
	case '+': c = a + b; break;
	case '-': c = a - b; break;
	case '*': c = a * b; break;
	case '/': c = a / b; break;
	default: assert(0);
	}
        //printf("%d %c %d =", a, op, b);
	printf("%d %c %d = %d\n", a, op, b, c);
	return 0;
}
