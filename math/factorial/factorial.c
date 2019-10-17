/* 
 * @Author: Sahana Muralikrishnan
 * @Email: sahana_m_student@headstartschool.org
 *
 * Factorial Code for :https://github.com/AllAlgorithms/algorithms/tree/master/math/factorial
 */

#include<stdio.h>
int main()
{
    int i,f, factorial=1;
	printf("Enter the number to find factorial : ");
	scanf("%d",&f);

	if(f<0)
        printf("Number has complex factorial\n");

    else if (f==0 || f==1)
        printf("Factorial : 1");

    else

	{
        for(i=2; i<=f; i++)
        {
            factorial=factorial*i;
         }
            printf("Factorial : %d\n" ,factorial);

	 } return 0;
}


