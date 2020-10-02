#include "bitmap.h"
#include <stdlib.h>

bitnode *create_bitmap(size_t n)
{
	size_t num = n / 8;

	if (n % 8 != 0)
		num++;

	bitnode *bitmap = calloc(num, sizeof(bitnode));

	return bitmap;
}

void destroy_bitmap(bitnode *bitmap)
{
	free(bitmap);
}

static bitnode _get_mask(size_t bitpos)
{
	bitnode bit_number = bitpos % 8;	/* The n'th bit that this bit will ocupy in its byte */
	bitnode mask = 1 << (7 - bit_number);	/* The mask to set that bit */		

	return mask;
}


void set_bit(bitnode *bitmap, size_t bitpos)
{
	if (bitmap) {
		size_t index = bitpos / 8;		/* The byte that this bit belongs to */
		bitnode mask = _get_mask(bitpos);

		bitmap[index] |= mask;
	}
}

void clear_bit(bitnode *bitmap, size_t bitpos)
{
	if (bitmap) {
		size_t index = bitpos / 8;		/* The byte that this bit belongs to */
		bitnode mask = ~(_get_mask(bitpos));

		bitmap[index] &= mask;
	}
}

int get_bit(bitnode *bitmap, size_t bitpos)
{
	if (bitmap) {
		size_t index = bitpos / 8;
		bitnode mask = _get_mask(bitpos);

		return !!(bitmap[index] & mask);
	}

	return 0;
}
