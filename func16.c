#include "func16.h"
#include <stdio.h>


void plus16(int a, int b){
	printf("0x%x (%d)\n", a + b, a + b);

}

void mp16(int a, int b){
	printf("0x%x (%d)\n", a * b, a * b);
}

void df16(int a, int b){
	printf("0x%x (%d)\n", a - b, a- b);
}

void pros16(int a, int b){
	printf("0x%x (%d)\n", a % b, a % b);
}

void a_nd16(int a, int b){
	printf("0x%x (%d)\n", a & b, a & b);
}

void o_r16(int a, int b){
	printf("0x%x (%d)\n", a | b, a | b);
}

void x_or16(int a, int b){
	printf("0x%x (%d)\n", a ^ b, a ^ b);
}

void inver16(int a){
	printf("0x%x (%d)\n", -a, -a);
}
