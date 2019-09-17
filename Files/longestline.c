/* 
Longest Line in a File
Author : Ashutosh Kumar
Date : 19th April,2018
Last Modified :
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argcount,char *argvalue[])
{
 if(argcount<2)
 {
	 printf("Invalid Number of Arguments");
	 return 0;
 }
 
 FILE *fp,*fp1;
 fp=fopen(argvalue[1],"r");
 char line[500],ch;  
 int count=0,max=0,x=0,start;

 if(fp==NULL)
 {
   printf("Error :");
   return 0;
 }

 while((ch=fgetc(fp))!=EOF)
 {
   count+=1;
   if((ch=='.'))
   {
     if(count>max)
     {
       max=count;
       fseek(fp,-(max-1),SEEK_CUR);
       fgets(line,max,fp);   
     }
   count=0;
   } 
 }

 
 printf("Longest Line in the file is %s",line);
 
 fclose(fp);
 return 0;
}
