/* Program to Write Structures to the file
   @Author : Ashutosh Kumar
   @Date of Creation : 27th March,2018
   @Last Modified :
*/

#include<stdio.h>
#include "header.h"

int main()
{
    STUDENT s1;
    FILE *fp;
    int count=0,userinput=0;

    fp=fopen("data.txt","a");
    if(fp==NULL)
     {
       printf("File could not be opened");
       return 0;
     }
 
     printf("Enter the number of records you want to write to the file");
     scanf("%d",&userinput);	

     while(count<userinput)
     {
      printf("Enter Name of the Student");
      scanf("%s",s1.name);

      printf("Enter Prn of the Student");
      scanf("%lld",&s1.prn);

      printf("Enter GPA of the Student");
      scanf("%lf",&s1.gpa);
      count+=1;
      fwrite(&s1, sizeof(s1), 1, fp);
      printf("Data is written into file \n");
     }

     fclose(fp);
     fp=fopen("data.txt","r");

     while(fread(&s1, sizeof(s1), 1, fp)==1)
     {
        printf("Name: %s\n", s1.name);
        printf("PRN: %lld\n", s1.prn);
	printf("GPA: %lf\n\n",s1.gpa);
     }
     return 0;     
}
