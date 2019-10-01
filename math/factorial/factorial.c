/* 
 * @Author: Sahana Muralikrishnan
 * @Email: sahana_m_student@headstartschool.org
 *
 * Factorial Code for :https://github.com/AllAlgorithms/algorithms/tree/master/math/factorial
 */

#include<stdio.h>
int main()
{
	int i,f, product=0, factorial=1;
	printf("Enter the number to find factorial : ");
	scanf("%d",&f);
	
	if(f<0)
	 printf("Number has zero factorial\n");
	 
	 else 

	{	for(i=1; i<=f; i++)
	
		{
                        factorial=factorial*i;
                }
                printf("Factorial : %d\n" ,factorial);

	}
}


