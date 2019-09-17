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
 if(argcount<2)
 {
	 printf("Invalid Number of Arguments");
	 return 0;
 }

 FILE *fp,*fp1;
 fp=fopen(argvalue[1],"r");
 char line[500],ch,search[100];
 int count=0,n;

if(fp==NULL)
 {
   printf("Error :");
   return 0;
 }

printf("Enter Number of last characters you want to read");
scanf("%d",&n);

fseek(fp,-n-1,SEEK_END);
//fseek(fp,-n-1,SEEK_CUR);

while((ch=fgetc(fp))!=EOF)
{
  printf("%c",ch);
}

fclose(fp);
return 0;
}

