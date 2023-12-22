#include "func2.h"

int perevod2(char* str){
	int rez = 0;
	int start = 0;
	if(str[0] == '-' || str[0] == '~') start = 1;
	if(str[0] == '~' && str[1] == '-') start = 2;
	for(start; start < strlen(str); start++){
		if(str[start] == '1') rez += pow(2, strlen(str) - start - 1);
		if(str[start] != '1' && str[start] != '0'){
			printf("%c error5\n", str[start]);
			exit(1);
		}
	}
	return rez;

}
int perevod2to10(int x){
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
	printf("%d (%d)\n", perevod2to10(a + b), a + b);

}

void mp2(int a, int b){
	printf("%d (%d)\n", perevod2to10(a * b), a * b);
}

void df2(int a, int b){
	printf("%d (%d)\n",perevod2to10(a - b), a- b);
}

void pros2(int a, int b){
	printf("%d (%d)\n", perevod2to10(a % b), a % b);
}

void a_nd2(int a, int b){
	printf("%d (%d)\n", perevod2to10(a & b), a & b);
}

void o_r2(int a, int b){
	printf("%d (%d)\n", perevod2to10(a | b), a | b);
}

void x_or2(int a, int b){
	printf("%d (%d)\n", perevod2to10(a ^ b), a ^ b);
}

void inver2(int a){
	if(a == 0) printf("0 (0)");
	else printf("%d (%d)\n", perevod2to10(-(a + 1)), -(a + 1));
}
