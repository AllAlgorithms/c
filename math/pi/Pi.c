#include<stdio.h>

int main(){
//This program calculates a approximate value to pi, using a serie
	float pi=0, i=1.0, signal=1;
	while(4/i>0.0001)
	{
		pi+=signal*4/i;
		signal*=-1;
		i+=2;
		
	}	
	
	printf("Pi value is: %f", pi);
	return 0;		
}

