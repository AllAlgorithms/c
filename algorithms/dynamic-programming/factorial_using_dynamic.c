#include<stdio.h>
#define MAX 1000

int fact[MAX]={0};


int factorial(int num){
	int i;
	fact[0]=1;
	
	for(i=1;i<=num;i++){
		fact[i]= i*fact[i-1];
	}
	return fact[num];
}
int main(){
	
	int n;
	printf("enter the number: \n");
	scanf("%d",&n);
	if(n<0){
		printf("Please enter the non-negative number");
	}
	else{
		printf("factorial of %d is: %d",n,factorial(n));
	}
	
	return 0;
	
}
