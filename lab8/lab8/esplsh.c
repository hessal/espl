
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/stat.h>
#include <fcntl.h>

#define BUF_LEN 1024
static char command[BUF_LEN+1];
static int argc;
static char *argv[BUF_LEN+1];

/* read command and remove end of line if present */
int read_command() {
  int len;

  if(fgets(command, BUF_LEN, stdin)) {
    len = strlen(command);
    if(len>0 && command[len-1]=='\n')
      command[len-1] = '\0';
    return 1;
  }
  
  return 0;
}

#define NO_SEP '\0'
#define EOC '\1'

/* split the command line into arguments and fill argv with pointers
to the arguments */
void split_command() {
  char *s, sep;
  int between;

  between = 1;
  argc = 0;
  sep = NO_SEP;
  for(s = command; *s; ++s) {
    switch(*s) {
    case '\"': case '\'':
      if(sep==NO_SEP) {
        sep = *s;
      } else if(sep==*s) {
        sep = '\0';
      }
      break;
    case '\\':
      ++s;
      break;
    case ' ':
      if(!sep) {
        between = 1;
        *s = '\0';
        continue;
      }
      break;
    }
    if(between) {
      argv[argc++] = s;
      between = 0;
    }
  }
  argv[argc] = NULL;
}

/* expand arguments, substitute shell variable values etc. */
void expand_args() {
  char **a = argv;
  while(*a) {
    if(**a=='"' || **a=='\'') { /* TODO: quotes can be in any place */
      *a = strdup(*a);
      memmove(*a, *a+1, strlen(*a));
      (*a)[strlen(*a)-1] = 0;
    } else {
      *a = strdup(*a);
    }
    /* TODO: eliminate escapes \ */
    /* TODO: expand environment variables */
    ++a;
  }
}

/* free arguments allocated during expansion */
void free_args() {
  char **a = argv;
  while(*a) {
    free(*a);
    ++a;
  }
}

/* run an external program */
void run_program() {
  int pid, status,pid2,index;
  static char ststr[8];

  /* TODO: input, output redirection */
  /* TODO: pipelines */
  /* TODO: background commands */
  
    int p[2];
    if(pipe(p)==-1)
	printf("pipe eror");
     char c2;
     int i;
      for (i=0; i<argc; ++i){
	char tmp= *(argv[i]);
	  if(tmp=='|'){
	     c2=tmp;
	     index=i;
	    if((pid2=fork())==0){
	      dup2(p[0],0);
	      execvp(argv[i+1],argv+i+1);
	    }
        }
     }
    
   if(((pid=fork())>0) &(pid2>0) ) {
    waitpid(pid, &status, 0);
    sprintf(ststr, "%d", status);
    setenv("?", ststr, 1);
    }
  else if(pid==0) {
    char c= *(argv[argc-2]);
     if (c2=='|') {
       dup2(p[1],1);
          argv[index]='\0';
      } 
     if (c=='<'){
         int fd = open(argv[argc-1],O_RDONLY); 
         dup2(fd,0);
         argv[argc-2]= '\0';
         close(fd);
      }
     else if(c=='>') {
        int fdout = open(argv[argc-1],O_WRONLY|O_TRUNC|O_CREAT , S_IRUSR|S_IWUSR);
        close(1);
        dup2(fdout,1);
        argv[argc-2]= '\0';
        close(fdout);
    }
    execvp(argv[0], argv);
    perror(argv[0]);
  }
   else {
    perror(getenv("SHELL")); 
  }
  
}

int main(int _argc, char **_argv) {
  /* clear shell variables and re-assign a minimum set */
  clearenv();
  setenv("PATH", ":/bin:/usr/bin", 1);
  setenv("PROMPT", "$ ", 1);
  setenv("SHELL", _argv[0], 1);

  signal(SIGINT, SIG_IGN); /* ignore ^C */

  while(1) {
    printf("%s", getenv("PROMPT"));
    if(!read_command())
      break;
    split_command();
    if(!argc)
      continue;
    expand_args();
    /* process builtin commands */
    if(!strcmp(argv[0],"exit")) {
      break;
    } else if(!strcmp(argv[0],"set")) {
      if(argc!=3) {
        fprintf(stderr, "set: two arguments required\n");
        continue;
      }
      setenv(argv[1], argv[2], 1);
    } else if(!strcmp(argv[0], "cd")) {
      if(argc!=2) {
        fprintf(stderr, "cd: one argument required\n");
        continue;
      }
      if(chdir(argv[1])==-1) {
        perror("cd");
      }
    } else if(!strcmp(argv[0], "pwd")) {
      if(argc!=1) {
        fprintf(stderr, "pwd: no arguments allowed\n");
        continue;
      }
      printf("%s\n", getcwd(command, BUF_LEN));
    } else {
      /* run external command */
      run_program();
    }
    free_args();
  }
  printf("\n");

  return 0;
}
    

