#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "func16.h"
#include "func8.h"
#include "func2.h"

int type_op(char* str){
	if(str[0] == '~') str =  str + 1;
	if(str[0] == '-'){
		str = str + 1;
	}
	if(str[0] == '1'){
		return 2;
	}
	if(str[0] == '0' && str[1] == 'x'){
		return 16;
	}
	if(str[0] == '0' && str[1] != 'x' && str[1] != 0){
		return 8;
	}
	else if(str[0] == '0' && str[1] != 'x') return 2;
	else return -1;
}

int main(){
	
	size_t size = 0;
	int op1;
	int op2;
	int num1;

	char znak = 0;
	char* input = NULL;
	int sign = 1;
	int sign2 = 1;
	
	char* num1s = NULL;
	char* num2s = NULL;


	getline(&input, &size, stdin);
	if(input == NULL){
		printf("error1\n");
		return 1;
	}
	
	if(strchr(input, '~') != NULL){
		char num1_b[128];
		sscanf(input, "%127s", num1_b);
		num1s = strdup(num1_b);
		//printf("%s\n", num1s);
		if(num1s[1] == '-') sign = -1;
		op1 = type_op(num1s);
		//printf("%sa", num1s);
		if(op1 == 2) num1 = perevod2(num1s);
		if(op1 == 8) num1 = perevod8(num1s);
		if(op1 == 16) num1 = perevod16(num1s);
		znak = '~';
	}
	else{

	char num1_b[128];
	char op_b[2];
	char num2_b[128];
	sscanf(input,"%127s %1s %127s", num1_b, op_b, num2_b);
	num1s = strdup(num1_b);
	if(num1s[0] == '-') sign = -1;
	op1 = type_op(num1s);

	num2s = strdup(num2_b);
	if(num2s[0] == '-') sign2 = -1;
	op2 = type_op(num2s);

	znak = op_b[0];
	}

	if(op1 == -1 || op2 == -1){
		printf("error2\n");
		return 1;
	}
	
	int num2;
	if(op1 == 16) num1 = sign * perevod16(num1s);

	if(op1 == 8) num1 = sign * perevod8(num1s);
	if(op1 == 2) num1 = sign * perevod2(num1s);
	/*printf("%d\n", num1);
	printf("%d\n", strlen(num1s));
	printf("%s\n", num1s);*/
	if(op2 == 16) num2 = sign2 * perevod16(num2s);
	if(op2 == 8) num2 = sign2 * perevod8(num2s);
	if(op2 == 2) num2 = sign2 * perevod2(num2s);
	//printf("%d\n", num2);


	

	//printf("%s\n %s\n %s\n", num1, op, num2);
	
	/*
	int len = strlen(input);
	char num1[128];
	char num2[128];
	int i = 0;

	int start = 0;

	for(i; i < strlen(input); i++){
		if(isspace(input[i])){
			break;
		}
		else num1[i] = input[i];
	}
	if(num1[0] != '~'){
		printf("%d\n", i);
		i = i + 1;
		for(i; i < strlen(input); i++){
			if(isspace(input[i])) break;
			znak = input[i];
		}
		if(znak == 0){
			printf("error\n");
			return 1;
		}
		i = i + 1;
		int j = i;
		for(i; i < strlen(input); i++){
			if(isspace(input[i])) break;
			num2[i - j] = input[i];
		}
		if(num2 == NULL){
			printf("error\n");
			return 1;
		}
	}
	printf("%s\n", num1);
	else{
		start = 1;
		znak = '~';
	}
*/
	/*if(num1[start] == '-'){
		sign = -1;
		start++;
	}
	if(num1[start] == '1'){
		for(start; start < strlen(num1); start++){
			if(!('0' <=  num1[start] && num1[start] <= '1')){
				printf("Ошибка ввода1\n");
				printf("%c\n %s\n %d\n", num1[start], num1, strlen(num1));
				return 1;
			}
		}
		op1 = 2;
	}

	if(num1[start] == '0' && num1[start + 1] == 'x'){
		for(start + 1; start < strlen(num1); start++){
			if(!(('0' <= num1[start] && num1[start] <= '9') || ('a' <= num1[start] && num1[start] <= 'f') || ('A' <= num1[i] && num1[start] <= 'F'))) {
				printf("Ошибка ввода2\n");
				return 1;
			}
		}
		op1 = 16;
	}
	if(num1[start] == '0' && num1[start + 1] != 'x'){
			for(start; start < strlen(num1); start++){
				if('0' > num1[start] || '7' < num1[start]){
					printf("Ошибка ввода3\n");
					return 1;
				}
			}
			op1 = 8;
	}
	 if(num2 != NULL){
		 int sign2 = 1;
		 start = 0;
	
		if(num2[start] == '-'){
			sign2 = -1;
			start++;
		}
		if(num2[start] == '1'){
			for(start; start < strlen(num2); start++){
				if(!('0' <=  num2[start] || '1' >= num2[start])){
					printf("Ошибка ввода4\n");
					return 1;
				}
			}
			op2 = 2;
		}

		if(num2[start] == '0' && num2[start + 1] == 'x'){
			for(start + 1; start < strlen(num2); start++){
				if(!(('0' <= num2[start] && num2[start] <= '9') || ('a' <= num2[start] && num2[start] <= 'f') || ('A' <= num2[i] && num2[start] <= 'F'))) {
					printf("Ошибка ввода5\n");
					return 1;
				}
			}
			op2 = 16;
		}
		if(num2[start] == '0' && num2[start + 1] != 'x'){
				for(start; start < strlen(num2); start++){
					if('0' > num2[start] || '7' < num2[start]){
						printf("Ошибка ввода6\n");
						return 1;
					}
				}
				op2 = 8;
		}

		
	}	

*/


	/*while( i  < len - 1 && input[i] != ' '){
		if(input[0] == '~'){
			znak = '~';
			++input;
		}
		if(input[0] == '-'){
			sign = -1;
			++input;
		}
		if(input[0] == '0' && input[1] == 'x'){
		
		}
		if(input[0] == '0' && input[1] != 'x'){
			//
		}
		if(intput[0] == '1'){
			//
		}

	}*/

	//char str_b[1024];
	//char *str = (char *)str_b;
	//char* strr = NULL; 
	//char* str = NULL;
	//getline(&strr, &len, stdin);
	//fgets(str, 10000, stdin);
	//sscanf(strr, "%99s\0", str);
	//printf("%s\n", str);
	/*if(str == NULL || strlen(str) <= 1 || str[0] == '\0') {
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
		//if (znak) { printf("ERROR"); return 1;}
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
		}*/
	if(znak != '~'){
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
		else if(znak == '&' && sign == 1 && sign2 == 1){
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

		else if (znak == '|' && sign == 1 && sign2 == 1){

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
		else if (znak == '^' && sign == 1 && sign2 == 1){
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

	free(input);
	free(num1s);
	free(num2s);
	return 0;
}
