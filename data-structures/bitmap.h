#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stddef.h>


typedef unsigned char bitnode;


bitnode *create_bitmap(size_t n);

void destroy_bitmap(bitnode *bitmap);

void set_bit(bitnode *bitmap, size_t bitpos);

void clear_bit(bitnode *bitmap, size_t bitpos);

int get_bit(bitnode *bitmap, size_t bitpos);

#endif
