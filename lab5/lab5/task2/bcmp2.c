#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
int c[10];
FILE *fp1, *fp2;
fp1=openFile("file1.txt");
	if (!fp1)
		{
			write(1,"Unable to open file!",21);
			return 1;
		}
		write(1,"bbb",3); //check that write works
	
//while ((c = readFile2(fp1)) != EOF) 	
    c[0] = readFile2(fp1);
     c[1] = readFile2(fp1);
    write(1,c[0],1);
     write(1,c[1],1);
return 0;
}