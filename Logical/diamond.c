#include <stdio.h>
int main()
{
 int i=0,j=0;
 for(i=0;i<12;i=i+1)
 {
  for(j=0;j<11;j=j+1)
  {
   if(i<6)
   {
    if(j<6-i || j>=5+i)
    printf("*");
    else
    printf(" ");
   }
   else	
   {
    if(j<6-(11-i) || j>=5+(11-i))
    printf("*");
    else
    printf(" ");
   }
  } 
  printf("\n");
 }
return 0;
}
