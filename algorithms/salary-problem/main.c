#include <stdio.h>

int main(){

    int base_salary;

    printf("Enter the base salary : \n");

    scanf("%d",&base_salary);

    int work_days;

    printf("Enter the Numbers of working days : \n");

    scanf("%d",&work_days);

    if(work_days <= 25)
        printf("Salary : %d",base_salary);

    else if (work_days <= 0)
        printf(0);

    else if(work_days > 31)
        printf("Salary : %d",base_salary + 6000 );


    else
        printf("Salary : %d",base_salary + 1000*(work_days-25));
    

return 0;


}