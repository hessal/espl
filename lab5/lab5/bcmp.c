#include<stdio.h>
#include <string.h>

	int main( int argc, char *argv[] )
	{
		int i;
		FILE *fp1, *fp2;
		int c,c2;
		int counter=0;

		fp1=fopen(argv[1],"rb");
			if (!fp1)
		{
			printf("Unable to open file!");
			return 1;
		}
		
		fp2=fopen(argv[2],"rb");
			if (!fp2)
		{
			printf("Unable to open file!");
			return 1;
		}
		while (((c = fgetc(fp1)) != EOF) &&( (c2=fgetc(fp2))!=EOF)){
		    counter++;
		    if(c!=c2){
			printf("byte ");
			printf("%d",counter);
			printf(" ");
			printf("%c",c);
			printf ("  ");
			printf("%c",c2);
			printf(" ");
			return;
		      }
		}
	       
	       
	      fclose(fp1);
	      fclose(fp2);
	
		return 0;

    }