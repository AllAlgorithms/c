#include <stdio.h>

// https://en.wikipedia.org/wiki/Fast_inverse_square_root
float Q_rsqrt( float number )
{
	int i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number * 0.5F;
	y  = number;
	i  = * ( int * ) &y;
	i  = 0x5f3759df - ( i >> 1 );
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );
	return y;
}

int main()
{
    float nn;
	printf("Enter a number: ");
    scanf("%f", &nn);
    float n = Q_rsqrt(nn);
    printf("Inverse Square Root of %f = %f", nn, n);
}