#include <stdio.h>

int main(){
    int basicSalary;
    int numOfDaysWorked;
    printf("Enter basic Salary: ");
    scanf("%d", &basicSalary);
    printf("Enter number of days the employee came to work: ");
    scanf("%d", &numOfDaysWorked);

    if (numOfDaysWorked >= 25)
        printf("\nThe salary that the employee will get is: %d", basicSalary + (numOfDaysWorked-25)*1000);
    else
        printf("\nThe salary that the employee will get is: %d", basicSalary);

    return 0;
}