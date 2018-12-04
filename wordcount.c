/* File word count program
   @Author : Ashutosh Kumar
   @Date of Creation : 6th December,2017
   @Last Modified :
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argcount,char* argvalue[])
{
 //Declaration of file pointer and variables required

 FILE* fin;
 int count=0,ch,previous=' ';

 //validation for arguments
 if(argcount!=2)
 {
	 printf("Invalid Number of Arguments");
	 return 0;
 }
 //Opening the file in text and read mode 
 fin=fopen(argvalue[1],"r");
  
 //Error Handling
 if(fin==NULL)
 {
   printf( "Error : %s", strerror(errno));
   return 0;
  /*
   strerror(errno);
   exit(errno);
  */
 }
 
 while((ch=fgetc(fin))!=EOF)
 {
  if((isspace(ch) && (!(isspace(previous)))) || (ispunct(ch) && (!(ispunct(previous)))))
   {
    count=count+1;
   }
   previous=ch;
 }
 printf(" Number of words in file is %d ",count);

return 0;
}
