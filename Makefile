all: test verify_32 verify_64
	true

test: test.c fptc.h
	gcc -o test -O3 -Wall test.c

verify_32: verify.c fptc.h
	gcc -o verify_32 -O3 -Wall -DFIXEDPT_BITS=32 -lm verify.c

verify_64: verify.c fptc.h
	gcc -o verify_64 -O3 -Wall -DFIXEDPT_BITS=64 -lm verify.c
