#include "func8.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int perevod8(char* str){
	int rez = 0;
	int start = 1;
	if(str[start] == '-') start = 2;
	if(str[0] == '~') if(str[2] == '-') start = 3;
	if(str[0] == '~') if(str[2] != '-') start = 2;
	for(start; start < strlen(str); start++){
		if(isdigit(str[start]) && (int)(str[start]- '0') < 8){
			rez += (int)(str[start] - '0') * pow(8, strlen(str) - start - 1);
		}
		else{
			printf("error4\n");
			exit(1);
		}
	}
	return rez;
}

void plus8(int a, int b){
	if(a + b < 0) printf("-0%o (%d)\n", abs(a + b), a + b);
	else printf("0%o (%d)\n", a + b, a + b);

}

void mp8(int a, int b){
	if(a * b < 0) printf("-0%o (%d)\n", abs(a * b), a * b);
	else printf("0%o (%d)\n", a * b, a * b);
}

void df8(int a, int b){
	if(a - b < 0) printf("-0%o (%d)\n", abs(a - b), a - b);
	else printf("0%o (%d)\n", a - b, a- b);
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
	if(a == 0) printf("0%o (%d)\n", 0, 0);
	if(-(a + 1) < 0) printf("-0%o (%d)\n", abs(-(a + 1)), -(a + 1));
	if(-(a + 1) >= 0) printf("0%o (%d)\n", -(a + 1), -(a + 1));
}
