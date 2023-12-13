#include "func.h"
#include <stdio.h>


void plus(int a, int b){
	printf("%x (%d)\n", a + b, a + b);

}

void mp(int a, int b){
	printf("%x (%d)\n", a * b, a * b);
}

void df(int a, int b){
	printf("%x (%d)\n", a - b, a- b);
}

void pros(int a, int b){
	printf("%x (%d)\n", a % b, a % b);
}

void a_nd(int a, int b){
	printf("%x (%d)\n", a & b, a & b);
}

void o_r(int a, int b){
	printf("%x (%d)\n", a | b, a | b);
}

void x_or(int a, int b){
	printf("%x (%d)\n", a ^ b, a ^ b);
}

void inver(int a){
	printf("%x (%d)\n", -a, -a);
}
