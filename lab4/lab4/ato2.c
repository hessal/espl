#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int ato(char *num){
 int lastDigit; 
 int value=0;
 int a=1;

 int size=strlen(num);
  int i=0;
// printf("%d",size);
 while(size>0){
   
   lastDigit=num[size-1]-'0';
  
  lastDigit=lastDigit*a;
 
  value=value+lastDigit;
 
  a=a*10;
 // num=num/10;
   size--;
  }
  return value;
}
