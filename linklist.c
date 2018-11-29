/* LinkList
   @Author : Ashutosh Kumar
   @Date of Creation : 19th April,2018
   @Last Modified :
*/

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
  int value;
  struct node *next;
}NODE;

NODE *start=NULL,*trav=NULL,*prev,*last;


void printdata()
{
 trav=start;
 while(trav!=NULL)
 {
   printf("%d -> ",trav->value);
   trav=trav->next;
 }
}


void searchdata()
{
 printdata();
 int ch,flag=0;
 printf("Enter Data to be searched");
 scanf("%d",&ch);
 trav=NULL;

 trav=start;
 if(start->value==ch)
  {
    flag=1;
    printf("Data found %d",ch);
  }
 else
 {
  while(trav!=NULL)
  {
   if(trav->value==ch)
    {
      flag=1;
      printf("Data found %d",ch);
      break;
    }
   trav=trav->next;
 }

 if(flag==0)
   printf("No such data \n");
 }
}


void updatedata()
{
 printdata();
 int ch,flag=0;
 printf("Enter Data to be Updated \n");
 scanf("%d",&ch);

 trav=start;
 while(trav!=NULL)
 {
   if(trav->value==ch)
    {
      flag=1;
      printf("Enter New Data \n");
      scanf("%d",&trav->value);
      printf("Data Updated Successfully \n");
      break;
    }
   trav=trav->next;
 }

 if(flag==0)
   printf("No such data \n");

 printdata(); 
}

void insertdata()
{

while(1)
{
 NODE *temp=(NODE*)(calloc(1,sizeof(NODE)));
 int ch,choice;
 printf("Enter Data");
 scanf("%d",&temp->value);
 temp->next=NULL;
 
 if(start==NULL)
  {
     start=temp;
     last=temp;
  }
 else
  {
     last->next=temp;
     last=temp;
  }
 printdata();
 printf("Do you want to Continue 1 for yes 0 for No");
 scanf("%d",&choice);
 if(choice==0)
   break;
 }
}


void insertdata2()
{
 printdata();
 NODE *temp=(NODE*)(calloc(1,sizeof(NODE)));

 int ch;
 printf("Enter Data before you want to insert data");
 scanf("%d",&ch);

 printf("Enter new data");
 scanf("%d",&temp->value);

 temp->next=NULL;
 
 if(start==NULL)
     start=temp;
 else
  {
    if(start->value==ch)
    {
      temp->next=start;
      start=temp;
    }
    else
    {
     prev=NULL;
     trav=start;
     while(trav!=NULL)
     {
       if(trav->value==ch)
         break;

       prev=trav;
       trav=trav->next;
     }
     prev->next=temp;
     temp->next=trav;
    }
   }
 printdata();
}




void deletedata()
{
 trav=NULL;
 int ch,flag=0;
 if(start==NULL)
  printf("No data in Linklist");
 
 else
 {
  printdata();
  printf("Enter Data to be deleted");
  scanf("%d",&ch);

  trav=start;
  prev=NULL;
  if(start->value==ch)
  {
    start=start->next;
    printf("Data Deleted %d\n",trav->value);
    free(trav);
  }
 
  else
  {
   while(trav!=NULL)
   {
    if(trav->value != ch)
     {
       prev=trav;
       trav=trav->next;
     }
    else
     { 
       flag=1;
       prev->next=trav->next;
       trav->next=NULL;
       free(trav);
       printf("Data Deleted %d\n",trav->value);
       break;
     }
   }
   if(flag==0)
     printf("No such Records");
  }
 }
 printdata();
}


void reverselist()
{
  NODE *prev,*next,*current;

  prev=next=NULL;

  current=start;
  while(current!=NULL)
  {
   next=current->next;
   current->next=prev;
   prev=current;
   current=next;
  }
  start=prev;

  printdata();
}

int main()
{
 int choice,ch;

while(1)
{
 printf("\n 1 To add element to Linklist \n 2 To Delete element from Linklist \n 3 To Search in Linklist \n 4 To update element in Linklist\n 5 To add element at a particular position\n 6 To Reverse the Linklist \n");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1:
    insertdata();
    break;
   case 2:
    deletedata();
    break;
   case 3:
    searchdata();
    break;
   case 4:
    updatedata();
    break;
   case 5:
    insertdata2();
    break;
   case 6:
    reverselist();
    break;
   default:
   printf("Wrong Choice");
   break;
 }
 printf("Do you want to Continue 1 for Yes, 0 for No");
 scanf("%d",&ch);
 if(ch==0)
   break;
}
 return 0;
}

 
