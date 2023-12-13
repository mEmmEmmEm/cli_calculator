#include "func8.h"
#include <stdio.h>


void plus8(int a, int b){
	printf("0%o (%d)\n", a + b, a + b);

}

void mp8(int a, int b){
	printf("0%o (%d)\n", a * b, a * b);
}

void df8(int a, int b){
	printf("0%o (%d)\n", a - b, a- b);
}

void pros8(int a, int b){
	printf("0%o (%d)\n", a % b, a % b);
}

void a_nd8(int a, int b){
	printf("0%o (%d)\n", a & b, a & b);
}

void o_r8(int a, int b){
	printf("0%o (%d)\n", a | b, a | b);
}

void x_or8(int a, int b){
	printf("0%o (%d)\n", a ^ b, a ^ b);
}

void inver8(int a){
	printf("0%o (%d)\n", -a, -a);
}
