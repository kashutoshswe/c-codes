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

 FILE* fin,*fout;
 int count,previous;
 char ch[100];

 //validation for arguments
 if(argcount!=3)
 {
	 printf("Invalid Number of Arguments");
	 return 0;
 }
 //Opening the file in text and read mode 
 fin=fopen(argvalue[1],"r");
 fout=fopen(argvalue[2],"w");
  
 //Error Handling
 if(fin==NULL || fout==NULL)
 {
   printf( "Error : %s", strerror(errno));
   return 0;
  /*
   strerror(errno);
   exit(errno);
  */
 }
 
 while((fgets(ch,100,fin))!=NULL)
 {
  fputs(ch,fout); 
 }

 fclose(fin);
 fclose(fout);

return 0;
}
