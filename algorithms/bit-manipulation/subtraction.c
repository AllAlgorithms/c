#include <stdio.h>

int subtract(int x, int y)
{
	while(y != 0)
	{
		unsigned int borrow = y & ~x;
		x = y ^ x;
		y = borrow << 1;
	}
	return x;
}

int main()
{
	printf("diff of %d and %d is %d\n", 4, 3, subtract(4, 3));
	return 0;



