#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct Activity            //Greedy Algorithm use
{
    int start;
    int finish;
};

void ActivitySelection(struct Activity a[],int n)
{
  int i,j,temp,temp2;
  for(i=0;i<n;i++)                //USED bubble sort
  {
      for(j=i+1;j<n-1;j++)
      {
          if(a[i].finish>a[j].finish)
           { temp = a[i].finish;
             temp2 = a[i].start;
             a[i].finish = a[j].finish;
             a[i].start = a[j].start;
             a[j].finish = temp;
             a[j].start = temp2;
            }
      }
  }
 /* printf("\nSorted ACTIVITY timings : ");
 for(i=0;i<n;i++)
 {
     printf("\nStart time of   %d : %d",i,a[i].start);
     printf("\nfinish  time of %d : %d",i,a[i].finish);
 }
 */

i = 0 ;
printf("\nActivities to be selected : ");
printf("\n(%d,%d)",a[i].start,a[i].finish);
count++;
for(j=1;j<n;j++)
{
    if(a[j].start >=a[i].finish)
        { count++;
          printf("\n(%d,%d)",a[j].start,a[j].finish);
           i=j;
        }
}
}
int main()
{
    int n,i;
    printf("Enter the numbers of activities : ");
    scanf("%d",&n);
    struct Activity obj[n];
    for(i=0;i<n;i++)
    {
        printf("\n Enter start time of %d activity : ",i);
        scanf("%d",&obj[i].start);
        printf("\n Enter finish time of %d activity : ",i);
        scanf("%d",&obj[i].finish);
    }
  /*    // for printing the input  
        for(i=0;i<n;i++)
    {
        printf("\n Start time of %d activity : ",i);
        printf("%d",obj[i].start);
        printf("\n Finish time of %d activity : ",i);
        printf("%d",obj[i].finish);
    }
    */
  printf("\n");
   ActivitySelection(obj,n);
   printf("\nTotal number of activities : %d ",count);

    return 0;

}
