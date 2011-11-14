#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[] )
{ 
    FILE *fp1;
    int fileCount=1, i=0, c, size, j=0, flag=1, k=0, counter2=0, isword=0, id=0, namesIndex=0;
    int size2=0;
    char words[80]; 
    char names[80][80];
    int counters[20];
    int savedWordsCounter=0;
    for (i=0;i<20;++i)
	  counters[i]=1;
    int counter=0;
    for(fileCount=1;fileCount<argc;++fileCount){
	  id=0;
	  fp1 = fopen( argv[fileCount], "r" );
	  if ( ! fp1 )
	  {
		printf("Error opening file %s\n", argv[1]);
	  }
	  while ((c = fgetc(fp1)) != EOF){
		if (isalpha(c)){
		      isword=1;  
		      words[id]=c;
		      id++;
		}
		if(c=='"'){
		    counter++;
		}   
		if((c==' ') || (c=='(') || (c==',') || (c==')') || (c=='[')){
		      if(id>0 && counter==0){
			    for(j=0;j<namesIndex & flag==1;++j){
				counter2=0;
				size2=strlen(names[j]);
				if(size2==id){
				      for(k=0;k<id;++k){
					    if(names[j][k] == words[k])
						  counter2++;
					    if(counter2==id){
						  counter2=0;
						  counters[j]++;
						  flag=0;
					      }
				      }
				} 
			  }
			  if(flag==1){   
				for(i=0;i<id;++i){
				      names[namesIndex][i]=words[i];
				}
			      namesIndex++;
			  }
		      }
		    isword=0;
		    id=0;
		    flag=1;
		}
	      if(counter==2){
		    counter=0;
		    id=0;
	      }    
	  }   
	  fclose(fp1);
    }
    for(i=0;i<namesIndex;++i){
	if((strcmp(names[i],"else")!=0) &&(strcmp(names[i],"int")!=0) &&(strcmp(names[i],"if")!=0)  &&(strcmp(names[i],"char")!=0)   &&(strcmp(names[i],"return")!=0) ){
	      size=strlen(names[i]);
	      for(j=0;j<size;++j){
		    printf("%c" ,names[i][j]);
		}    
	      printf("%d", counters[i]);
	      printf("         ");
	}
    }
  return 0;
  }