#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int ato(int num){
 int lastDigit; 
 int value=0;
 int a=1;
 while(num!=0){
   lastDigit=num%10;
  lastDigit=lastDigit-'0';
  value=value+ lastDigit*a;
  a=a*10;
}


int main(int argc, char **argv) {
	int a, op, b, c;

	if(argc!=4) {
		fprintf(stderr, "usage: calc <number> [+|-|*|/] <number>\n");
		exit(1);
	}

	a = ato(argv[1]);
	printf("%d",a);
	//op = argv[2][0];
	//b = atod(argv[3]);
	//switch(op) {
	//case '+': c = a + b; break;
	//case '-': c = a - b; break;
	//case '*': c = a * b; break;
	//case '/': c = a / b; break;
	//default: assert(0);
	}

	//printf("%d %c %d = %d\n", a, op, b, c);
	return 0;
}
