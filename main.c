#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char **argv){
	if(argc < 2){
		printf("error\n");
		return 1;
	}
	if(argc == 4){
	int op1 = 0;
	int num1;
	if(argv[1][0] == '0' && argv[1][1] == 'x'){
		//char* help = strstr(argv[1], "x") + 1;
		num1 = strtoq(argv[1], NULL, 16);
		op1 = 16;
	}
	if(argv[1][0] == '0' && argv[1][1] != 'x'){
		//char* help = strstr(argv[1], "0") + 1;
		num1 = strtoq(argv[1], NULL, 8);
		op1 = 8;
	}
	if(argv[1][0] != '0'){
		//char* help = argv[1];
		num1 = strtoq(argv[1], NULL, 2);
		op1 = 2;
	}
	
	int num2;
	int op2 = 0;
	if(argv[3][0] == '0' && argv[3][1] == 'x'){
		//char* help1 = strstr(argv[3], "x") + 1;
		num2 = strtoq(argv[3], NULL, 16);
		op2 = 16;
	}
	if(argv[3][0] == '0' && argv[3][1] != 'x'){
		//char* help1 = strstr(argv[3], "0") + 1;
		num2 = strtoq(argv[3], NULL, 8);
		op2 = 8;
	}
	if(argv[3][0] != '0'){
		//char* help1 = argv[3];
		num2 =  strtoq(argv[3], NULL, 2);
		op2 = 2;
	}
	//printf("%d", num1 + num2);
	plus(num1, num2, op1, op2);


	}
	return 0;
}
