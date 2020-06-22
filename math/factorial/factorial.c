/* 
 * @Author: Sahana Muralikrishnan
 * @Email: sahana_m_student@headstartschool.org
 *
 * Factorial Code for :https://github.com/AllAlgorithms/algorithms/tree/master/math/factorial
 */

#include <stdio.h>
long int multiplyNumbers(int n);
int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial of %d = %ld", n, multiplyNumbers(n));
    return 0;
}
long int multiplyNumbers(int n)
{
    if (n >= 1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}


