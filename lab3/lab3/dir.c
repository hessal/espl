#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[])
{
        DIR             *dip;
        struct dirent   *dit;
        struct stat info;
        int             i = 0;
        int size; 
	char path[1025];
        
        /* check to see if user entered all the arguments */
        if (argc != 3)
        {
                printf("\nplease enter: an option(l or h) and a diractory");
                return 0;
        }
 
        if ((dip = opendir(argv[2])) == NULL)
        {
                perror("opendir");
                return 0;
        }
         printf("Directory stream is now open\n");
        
        while ((dit = readdir(dip)) != NULL)
        {
                i++;
                printf("\n%s", dit->d_name);
	         if(strcmp(argv[1],"l")==0){
		//if(argv[1]==76){
		strcpy(path, argv[2]);
                strcat(path, "/");
                strcat(path, dit->d_name);
                size=stat(path, &info);
		printf("\t\t%10ld", info.st_size);
		}
		
        }
 
        printf("\n\nreaddir() found a total of %i files\n", i);
 
        if (closedir(dip) == -1)
        {
                perror("closedir");
                return 0;
        }
 
        printf("\nDirectory stream is now closed\n");
        return 1;
}