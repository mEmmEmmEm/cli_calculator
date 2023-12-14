#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func16.h"
#include "func8.h"
#include "func2.h"

int main(){
	
	
	int num1;
	int op1;
	int op2;
	int num2;
	char znak = 0;
	char str_b[1024];
	char *str = (char *)str_b;
	scanf("%s", str);
	if(str == NULL) {
		printf("error\n");
		return 1;
	}
	
	if (str[0] == '~') {
		znak = '~';
		++str;
		
	}
	char* endptr = NULL;
	int sign = 1;
	if (str[0] == '-') {
		if (znak) { printf("ERROR"); return 1;}
		sign = -1;
		++str;
	}

	if(str[0] == '0' &&  str[1] == 'x'){
		
		num1 = sign * strtoq(str, &endptr, 16);
	       	op1 = 16;	


	}

	if(str[0] == '0' && str[1] != 'x'){
		num1 = sign * strtoq(str, &endptr, 8);
		op1 = 8;
	}
	if(str[0] != '0' && str[0] != '~'){
		num1 = sign * strtoq(str, &endptr, 2);
		op1 = 2;
	}
	if(endptr[0]){
		printf("ERROR\n");
		return 1;
	}
	if (znak == 0) {

		while (scanf("%c", &znak) && znak == ' ');
		char str1_b[1024];
		char *str1 = (char *)str1_b;
		scanf("%s", str1);

		int sign1 = 1;
		if (str1[0] == '-') {
			sign1 = -1;
			++str1;
		}
		if(str1[0] == '0' && str1[1] == 'x'){
			num2 = sign1 * strtoq(str1, &endptr, 16);
			op2 = 16;
		}
		if(str1[0] == '0' && str1[1] != 'x'){
			num2 = sign1 * strtoq(str1, &endptr, 8);
			op2 = 8;
		}
		if(str1[0] != '0'){
			num2 = sign1 * strtoq(str1, &endptr, 2);
			op2 = 2;
		}
		if(endptr[0]){
			printf("ERROR\n");
			return 1;
		}
		if(op1 != op2){
			printf("Ошибка: системы счисления не совпадают\n");
			return 1;
		}
		if(znak == '+'){
		
			if(op1 == 16){
				plus16(num1, num2);
			}
			if(op1 == 8){
				plus8(num1, num2);
			}
			if(op1 == 2){
				plus2(num1, num2);
			}	
		}
		else if(znak == '-'){
			if(op1 == 16){
				df16(num1, num2);
			}
			if(op1 == 8){
				df8(num1, num2);
			}
			if(op1 == 2){
				df2(num1, num2);
			}

		}
		else if(znak == '*'){
			if(op1 == 16){
				mp16(num1, num2);
			}
			if(op1 == 8){
				mp8(num1, num2);
			}
			if(op1 == 2){
				mp2(num1, num2);
			}
		}
		else if(znak == '%'){
			if(op1 == 16){
				pros16(num1, num2);
			}
			if(op1 == 8){
				pros8(num1, num2);
			}
			if(op1 == 2){
				pros2(num1, num2);
			}
		}
		else if(znak == '&' && sign == 1 && sign1 == 1){
			if(op1 == 16){
				a_nd16(num1, num2);
			}
			if(op1 == 8){
				a_nd8(num1, num2);
			}
			if(op1 == 2){
				a_nd2(num1, num2);
			}
		}

		else if (znak == '|' && sign == 1 && sign1 == 1){

			if(op1 == 16){
				o_r16(num1, num2);
			}
			if(op1 == 8){
				o_r8(num1, num2);
			}
			if(op1 == 2){
				o_r2(num1, num2);
			}
		}
		else if (znak == '^' && sign == 1 && sign1 == 1){
			if(op1 == 16){
				x_or16(num1, num2);
			}
			if(op1 == 8){
				x_or8(num1, num2);
			}
			if(op1 == 2){
				x_or2(num1, num2);
			}
		}
		else {
			printf("ERROR\n");
		}



	}
	else{
		if(op1 == 16){
			inver16(num1);
		}
		if(op1 == 8){
			inver8(num1);
		}
		if(op1 == 2){
			inver2(num1);
		}
	}

	
	return 0;
}
