#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char ** argv){
    char inbuf[200];  
    int j,i,k,line=1,c,flag=0;
    for (j=1;j<argc;j++) {
      printf("%s ", argv[j] );
    }
    printf("\n");
    int status=-1;
    int p[2];
    if(pipe(p)==-1)
      printf("pipe eror");
    int pid = fork();
    if(pid!=0)  {
      close(p[1]);
       printf("1 ");
       while (c=read(p[0],inbuf,1)>0){
	  if(flag==1){
	    printf("%d ",line);
	    flag=0;
	  }
       printf("%s",inbuf);
	  if(inbuf[0]=='\n'){
	      flag=1;
	      line++;
	  }
	}
      wait(&status);
      printf("exit status: %d \n ", status);
   }
    else {
        close(p[0]);
	dup2(p[1],1);
	close(p[1]);
        execvp(argv[2],argv+2);
	printf("error\n");
    }
    return 0;
}