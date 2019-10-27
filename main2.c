#include <stdio.h>

int main() {
	float naira;
	float dollar;
	
	printf("Enter the amount of Naira you want to convert:");
	scanf("%f", &naira);
	
	dollar = naira / 148;
	
	printf("The dollar equivalent of N%.2f is $%.2f", naira, dollar); 
}
