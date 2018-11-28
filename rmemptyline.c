/* Empty Line Removal Code
   @Author : Ashutosh Kumar
   @Date of Creation : 1st December,2017
   @Last Modified :

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argcount,char* argvalues[])
{
  
 //Declaration of file pointer and variables required

 FILE* fin;
 int count,ch,previous;

 //validation for arguments since only 2 arguments are required for wordcount in file 1st command 2nd file name

 if(argcount!=2)
 {
  printf("Invalid Number of Arguments \n");
  return 0;
 }

 //Opening the file in text and read mode 
 fin=fopen(argvalues[1],"r");
  
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
  previous=ch;
  ch=fgetc(fin);
  if(!(ch=='\n' && previous=='\n'))
   {
    printf("%c",previous);
   }
 }
fclose(fin);
return 0;
}
