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
 char ch;

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
 
 ch=fgetc(fin);
 while(ch!=EOF)
 {
  fputc(ch,stdout); 
  ch=fgetc(fin);
 }

 fclose(fin);

return 0;
}
