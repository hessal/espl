#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) {
    char buffer[40],buffer2[40];
    int handler1=0, handler2=0,c1,i,close=1,close2=1,size1=0,size2=0,minFileSize=0;
    handler1=openFile("file1.txt",3);
   // printf("%d",handler1);
    if (handler1<1){
	write(1,"Unable to open file!",20);
	return 1;
    }
    readFile2(handler1,buffer,30);
   // for(i=0;i<10;++i){
       //printf("%c",buffer[i]);
    //}
    close=closeFile("file1.txt");
    handler2=openFile("file2.txt",4);
  //  printf("  ");
   // printf("%d",handler2);
    if (handler2<1){
	write(1,"Unable to open file!",20);
	return 1;
    }
    readFile2(handler2,buffer2,11);
   // for(i=0;i<11;++i){
   //	printf("%c",buffer2[i]);
   // }
    close2=closeFile("file2.txt");
    size1=strlen(buffer);
    size2=strlen(buffer2);
 // printf("%d",size1);
  // printf("%d",size2);
    if(size1<size2)
	minFileSize=size1;
    else
	minFileSize=size2;
   
   // printf("%d",minFileSize);
    for(i=0;i<minFileSize;++i){
	if(buffer[i]!=buffer2[i]){
	    write(1," byte ",5);
	    write(1,i,1);
	    write(1," -",2);
	    write(1,&buffer[i],1);
	    write(1," +",2);
	    write(1,&buffer2[i],1);
	  }
      
    } 
    return 0;
}