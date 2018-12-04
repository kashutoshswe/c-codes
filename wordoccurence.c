/* 
Occurence of Word in file counting
Author : Ashutosh Kumar
Date : 19th April,2018
Last Modified :
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argcount,char *argvalue[])
{
 if(argcount<3)
 {
	 printf("Invalid Number of Arguments");
	 return 0;
 }

 FILE *fp,*fp1;
 fp=fopen(argvalue[1],"r");
 char line[500],ch,search[100];
 strcpy(search,argvalue[2]);
 int count=0;

if(fp==NULL)
 {
   printf("Error :");
   return 0;
 }

while(fgets(line,1000,fp) !=NULL)
{
   if(strstr(line,search))
   {
     count+=1;
   }
}

printf("Number of occurence %d",count);
fclose(fp);
return 0;
}

