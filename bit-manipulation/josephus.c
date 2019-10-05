/* the josephus problem can be solved by finding the greatest
 * power of two less or equals than n, subtracting this power
 * from n, multipling it by two and increment by one
 */
unsigned josephus(unsigned n)
{
	/* no acceptable solution to n equals zero */
	if (n == 0) 
		return 0;
	
	/* finding the greatest power of two less than n */
	unsigned mask = 1u << (sizeof(unsigned) * 8 - 1);
	while ((n & mask) == 0)
		mask >>= 1;

	n  ^= mask;    /* subtracting this power from n */ 
	n <<= 1;       /* multiplying by 2 */ 
	n++;           /* incrementing by one */

	return n;
}
