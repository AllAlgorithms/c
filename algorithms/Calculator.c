#include<stdio.h>
int main()
{
    int a, b;
    char op;
    float result;
    printf("Enter First Number:");
    scanf("%d", &a);
    printf("Enter Second Number:");
    scanf("%d", &b);
    printf("Enter Operater What Do You Want:");
    scanf(" %c", &op);
    switch (op)
    {
    case '+':
        result=a+b;
        printf("The Sum Is %f", result);
        break;
    case '-':
        result=a-b;
        printf("The Subtract Is %f", result);
        break;
    case '*':
        result=a*b;
        printf("The Multiply Is %f", result);
        break;
    case '/':
        result=a/b;
        printf("The Division Is %f", result);
        break;
        default:
    printf("Please Enter Envalid Operater");
        break;
    }
}
