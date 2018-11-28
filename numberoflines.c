#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <ctype.h>

int main(int argcount,char *argvalues[])
{
 FILE *fin;
 int count;
 char ch[100]; 

 if(argcount<2)
 {
  printf("Invalid Number of Arguments");
  return 0;
 }

 fin=fopen(argvalues[1],"r");
 if(fin==NULL)
 {
   printf("Error");
   return 0;
 }

 while((fgets(ch,100,fin))!=NULL)
 {
  count=count+1;
 }

 printf("Number of Lines in the file is %d",count);
 fclose(fin);
 return 0;
}
