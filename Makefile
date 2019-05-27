CFLAGS = -I src
CC = gcc $(CFLAGS)

all: bin/test bin/verify_32 bin/verify_64

bin/test: tests/test.c src/fptc.h
	$(CC) -o bin/test -O3 -Wall tests/test.c

bin/verify_32: tests/verify.c src/fptc.h
	$(CC) -o bin/verify_32 -O3 -Wall -DFIXEDPT_BITS=32 -lm tests/verify.c

bin/verify_64: tests/verify.c src/fptc.h
	$(CC) -o bin/verify_64 -O3 -Wall -DFIXEDPT_BITS=64 -lm tests/verify.c

clean:
	rm -f bin/*