#include "func16.h"

int perevod16(char* str){
	int rez = 0;
	int start = 2;
	if(str[0] == '-'){
		start = 3;
	}
	if(str[0] == '~'){ 
		if(str[1] == '-'){
		       	start = 4;}}
	if(str[0] == '~'){ 
		if(str[1] != '-') {
			start =3;}}

	for(start; start < strlen(str); start++){
		int flag = 0;
		int step = pow(16, strlen(str) - start - 1);
		/*if(isdigit(str[start]) != 0){
			rez += (int)(str[start] - '0') * step;
		}*/
		if(str[start] == 'a' || str[start] == 'A'){
			rez += 10 * step;
			flag = 1;
		}
		if(str[start] == 'b' || str[start] == 'B'){
			rez += 11 * step;
			flag = 1;
		}
		if(str[start] == 'c' || str[start] == 'C'){
			rez += 12 * step;
			flag = 1;
		}
		if(str[start] == 'd' || str[start] == 'D'){
			rez += 13 * step;
			flag = 1;
		}
		if(str[start] == 'e' || str[start] == 'E'){
			rez += 14 * step;
			flag = 1;
		}
		if(str[start] == 'f' || str[start] == 'F'){
			rez += 15 * step;
			flag = 1;
		}
		
		if(isdigit(str[start]) != 0){
			rez += (int)(str[start] - '0') * step;
			flag = 1;
		}
		if(flag == 0){
			printf("%c %c  error16\n", str[start], str[start+1]);
			exit(1);
		}
	}
	return rez;


}

void plus16(int a, int b){
	if(a + b < 0) printf("-0x%x (%d)\n", abs(a + b), a + b);
	else printf("0x%x (%d)\n", a + b, a + b);

}

void mp16(int a, int b){
	if(a * b < 0) printf("-0x%x (%d)\n", abs(a * b), a * b);
	else printf("0x%x (%d)\n", a * b, a * b);
}

void df16(int a, int b){
	if(a - b < 0) printf("-0x%x (%d)\n", abs(a - b), a - b);
	else printf("0x%x (%d)\n", a - b, a- b);
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
	if( a == 0) printf("0x%x (%d)\n", 0, 0);
	if(-a - 1 < 0) printf("-0x%x (%d)\n", abs(-(a + 1)), -(a + 1));
	if(-a - 1 >= 0)  printf("0x%x (%d)\n", -(a + 1), -(a + 1));
}
