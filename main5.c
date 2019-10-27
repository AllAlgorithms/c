#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c, s;
	float area;
	
	printf("Enter a value for side a: ");
	scanf("%d",&a);
	
	printf("Enter a value for side b: ");
	scanf("%d",&b);
	
	printf("Enter a value for side c: ");
	scanf("%d",&c);
	
	s = (a + b + c)/2;
	
	area = sqrt(s * (s - a) * (s - b) * (s - c)); 
	
	printf("The area of triangle with sides %d, %d, %d is %.2f sq unit", a, b, c, area);
	
	return 0;
	
}
