#include <stdio.h>
#include <math.h>

int main(void) { 
	float a = 0, b = 0, c = 0, D = 0, r1 = 0, r2 = 0, img = 0;
	printf("Enter the coefficient of x^2 : ");
	scanf("%f", &a);
	
	printf("Enter the coefficient of x : ");
	scanf("%f", &b);
	
	printf("Enter c : ");
	scanf("%f", &c);
	
	D = b * b - (4 * a * c);
	
	if(D == 0){
		r1 = -b / (2 * a);
		r2 = r1;
		printf("The root are %f and %f .", r1, r2);
	}
	
	else if(D > 0){
		r1 = (-b + sqrt(D)) / (2 * a);
	    r2 = (-b - sqrt(D)) / (2 * a);
	    printf("The root are %f and %f .", r1, r2);
	}
	
	else{
		r1 = -b / (2 * a);
		r2 = r1;
		img = sqrt(-D) / (2 * a);
		printf("The root are %f and %f .", r1, r2);
		printf("The imaginary part is %f .", img);
	}
	
	return 0;
}

//----------------------Output--------------------------

// Enter the coefficient of x^2 : 3
// Enter the coefficient of x : 6
// Enter the c : -6
// The two roots are 0.732050807568877 and -2.73205080756888
