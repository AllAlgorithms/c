/*Author: ALOK KHULBVAY>
Date:10/10/2020.
Program  to vreate a Command line calculator.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char *operation;
    int num1, num2;
    operation = argv[1];
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);
    if (strcmp(operation, "add") == 0)
    {
        printf("The sum of %d and %d is:%d\n", num1, num2, num1 + num2);
    }
    else if (strcmp(operation, "subtract") == 0)
    {
        printf("The difference of %d and %d is:%d\n", num1, num2, num1 - num2);
    }
    else if (strcmp(operation, "multiply") == 0)
    {
        printf("The product of %d and %d is:%d\n", num1, num2, num1 * num2);
    }
    else if (strcmp(operation, "divide") == 0)
    {
        printf("The division of %d and %d is:%d\n", num1, num2, num1 / num2);
    }
    return 0;
}
