/* swaps two integers without using an auxiliary variable */
void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
