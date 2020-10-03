/* 
 * @Author: Abderrezzaq Sendjasni
 * @Email: sendjasni.abderrezzaq@gmail.com
 *
 * Recursive Factorial Code 
 */
#include <stdio.h>
#include <stdlib.h>

long factorial(int number)
{
    if (number >= 1)
        return (number * factorial(number - 1));
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    int input_number;
    printf("Enter a number to calculate its factorial\n");
    scanf("%d", &input_number);

    printf("%d! = %ld\n", input_number, factorial(input_number));

    return EXIT_SUCCESS;
}
