

void puts(char *s){
  int size=0;
 // while(s[size]!='\0')
 // size++;
  char *t = s;
	while(*t) ++t;
       size=t-s;
   //    printf("%d",size);
  write(1,s,size);
}