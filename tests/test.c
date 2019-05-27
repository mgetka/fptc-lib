#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* This is a pure integer-only test program for fptc */

//#define FPT_WBITS 16


#include "fptc.h"

void
fpt_print(fpt A)
{
	char num[20];

	fpt_str(A, num, -2);
	puts(num);
}

int main() {

	fpt A, B, C;
	
	printf("fptc library version: %s\n", FPT_VCSID);
	printf("Using %d-bit precision, %d.%d format\n\n", FPT_BITS, FPT_WBITS, FPT_FBITS);

	printf("The most precise number: ");
	fpt_print(1);
	printf("The biggest number: ");
	fpt_print(0x7fffff00);
	printf("Here are some example numbers:\n");

	printf("Random number: ");
	fpt_print(fl2fpt(143.125));
	printf("PI: ");
	fpt_print(FPT_PI);
	printf("e: ");
	fpt_print(FPT_E);
	puts("");

	A = fl2fpt(2.5);
	B = i2fpt(3);

	fpt_print(A);
	puts("+");
	fpt_print(B);
	C = fpt_add(A, B);
	puts("=");
	fpt_print(C);
	puts("");

	fpt_print(A);
	puts("*");
	fpt_print(B);
	puts("=");
	C = fpt_mul(A, B);
	fpt_print(C);
	puts("");

	A = fl2fpt(1);
	B = fl2fpt(4);
	C = fpt_div(A, B);

	fpt_print(A);
	puts("/");
	fpt_print(B);
	puts("=");
	fpt_print(C);

	printf("exp(1)=");
	fpt_print(fpt_exp(FPT_ONE));

	puts("");
	puts("sqrt(pi)=");
	fpt_print(fpt_sqrt(FPT_PI));
	
	puts("");
	puts("sqrt(25)=");
	fpt_print(fpt_sqrt(fl2fpt(25)));

	puts("");
	puts("sin(pi/2)=");
	fpt_print(fpt_sin(FPT_HALF_PI));

	puts("");
	puts("sin(3.5*pi)=");
	fpt_print(fpt_sin(fpt_mul(fl2fpt(3.5), FPT_PI)));

	puts("");
	puts("4^3.5=");
	fpt_print(fpt_pow(fl2fpt(4), fl2fpt(3.5)));

	puts("");
	puts("4^0.5=");
	fpt_print(fpt_pow(fl2fpt(4), fl2fpt(0.5)));

	return (0);
}
