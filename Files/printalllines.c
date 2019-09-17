#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <ctype.h>

int main(int argcount,char *argvalues[])
{
 FILE *fin;
 int k;
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
   if(ch[1]!='\0')
   printf("%s",ch);
 }

 fclose(fin);
 return 0;
}
