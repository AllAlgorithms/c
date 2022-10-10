#include <stdio.h>

int add(int x, int y)
{
	while(x > 0)
	{
		unsigned int carry = x & y;
		y = x ^ y;
		x = carry << 1;
	}
	return y;
}

int main()
{
	printf("sum of %d and %d is %d\n", 3, 4, add(3, 4));
	return 0;
}


