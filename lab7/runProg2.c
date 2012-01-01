#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char ** argv){
    int j;
    for (j=1;j<argc;j++) {
      printf("%s ", argv[j] );
    }
    printf("\n");
    int status=-1;
    int pid = fork();
    if(pid!=0)  {
	wait(&status);
	printf("exit status: %d \n ", status);
     }
    else {
	execvp(argv[1],argv+1);
	printf("error\n");
    }
    return 0;
}