#include "func2.h"
#include <stdio.h>
#include <math.h>

int perevod(int x){
	int size = 0;
	int help = x;
	/*while(help / 10){
		help = help / 10;
		size ++;
	}
	help = x;*/
	int rez = 0;
	int count = 1;
	while(help){;
		rez += (help % 2) * count; 
		count *= 10;
		help = help / 2;
	}
	return rez;
}

void plus2(int a, int b){
	printf("%d (%d)\n", perevod(a + b), a + b);

}

void mp2(int a, int b){
	printf("%d (%d)\n", perevod(a * b), a * b);
}

void df2(int a, int b){
	printf("%d (%d)\n",perevod(a - b), a- b);
}

void pros2(int a, int b){
	printf("%d (%d)\n", perevod(a % b), a % b);
}

void a_nd2(int a, int b){
	printf("%d (%d)\n", perevod(a & b), a & b);
}

void o_r2(int a, int b){
	printf("%d (%d)\n", perevod(a | b), a | b);
}

void x_or2(int a, int b){
	printf("%d (%d)\n", perevod(a ^ b), a ^ b);
}

void inver2(int a){
	printf("%d (%d)\n", perevod(-a), -a);
}
