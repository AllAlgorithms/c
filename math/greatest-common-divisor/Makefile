TARGET=greatest-common-divisor
INCDIR=.
CC=gcc
CFLAGS=-I$(INCDIR) -Wall -Wextra -O3

OBJ = greatest-common-divisor.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ) *~ core
