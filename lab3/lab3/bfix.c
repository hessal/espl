#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "diff.h"


//int fputdiff(FILE *stream, struct diff *diff) {
 //   return fprintf(stream, "byte %lu -%u +%u\n",
 //                          diff->offset, diff->old, diff->new);
//}

//struct diff *parsediff(char *s, struct diff *diff) {
 //   char **sp = &s;
 //   *sp = strchr(*sp, ' '); /* skip 'byte' */
 //   diff->offset = strtol(*sp, sp, 10);
 //   diff->old = -strtol(*sp, sp, 10);
 //   diff->new = strtol(*sp, sp, 10);

 //   return diff;
//}

	int main( int argc, char *argv[] )
	{
        FILE *fp1, *fp2,*fp3;
        char line[100];
	int c,c2;
         int newValue,oldValue; 
	 char placeToChange;
          //read the file with the diffrences  
		fp1=fopen(argv[1],"r+");
			if (!fp1)
		{
			printf("Unable to open file1!");
			return 1;
		}
		//read the file we want to change
		fp2=fopen(argv[2],"r+");
			if (!fp2)
		{
			printf("Unable to open file2!");
			return 1;
		} 
		//read the second file
		fp3=fopen(argv[3],"r+");
			if (!fp3)
		{
			printf("Unable to open file3!");
			return 1;
		}
		
		while((c=fgetc(fp2))!=EOF){
		  printf("%d",c);
		  printf(" ");
		}
          
	       while (fgets(line,100,fp1)) {
		   fseek(fp3,line[5],SEEK_SET);
		   c=fgetc(fp3);
		   // printf("%d",c);
		   // printf(" ");
		     fseek(fp2,line[5],SEEK_SET);
		     fputc(c,fp2);
		   //  fseek(fp2,line[5],SEEK_SET);
		   //  c2=fgetc(fp2);
		//    printf("%d",c2);
		}
		
		while((c=fgetc(fp2))!=EOF){
		  printf("%d",c);
		  printf(" ");
		}
	
          fclose (fp1);
	  fclose(fp2);
	  fclose (fp3);
	  return 0;
      }