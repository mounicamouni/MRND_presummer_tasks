//#define _CRT_SECURE_NO_WARNINGS
//#include <stddef.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<conio.h>
//#include<malloc.h>
//#include<string.h>
//#include<math.h>
//int topOp = -1, topNum = -1;
//
//int isOperator(char x){
//	if (x == '*' || x == '+' || x == '-' || x == '/' || x == '^')
//		return 1;
//	return 0;
//}
//
//void pushOperator(char *stack, char x){
//	topOp++;
//	stack[topOp] = x;
//}
//
//void pushNumber(int *stack, int x){
//	topNum++;
//	stack[topNum] = x;
//}
//
//char popOp(char *stack){
//	char temp = stack[topOp];
//	topOp--;
//	return temp;
//}
//
//
//int popNum(int *stack){
//	int temp = stack[topNum];
//	topNum--;
//	return temp;
//}
//
//int precedence(char ch ){
//	switch (ch)
//	{
//	case '^':
//		return 3;
//	case '/':
//		return 2;
//	case '*':
//		return 2;
//	case '+':
//		return 1;
//	case '-':
//		return 1;
//	default:
//		return 0;
//	}
//}
//
//int eval(int a,int b,char op){
//	int x;
//	switch (op)
//	{
//	case '+':
//		return a + b;
//	case '-':
//		return a - b;
//	case '*':
//		return a * b;
//	case '/':
//		return a / b;
//	case '^':
//		x= pow(double(a),double(b));
//		return x;
//	default:
//		break;
//	}
//	return 0;
//}
//
//
//int evaluate(char *str){
//	int len;
//	for (len = 0; str[len] != '\0' && str[len] != '\n'; len++){}
//	int temp=0;
//	char op;
//	int a, b, value;
//	char operator1;
//
//	int *numStack = (int*)malloc(sizeof(int)*len);
//	char *opStack = (char*)malloc(sizeof(char)*len);
//
//	for (int i = 0; i < len; i++){
//		temp = 0;
//		if (str[i] == ' ')
//			continue;
//
//
//		if (str[i] >= '0'&& str[i] <= '9'){
//
//			while (str[i] >= '0'&& str[i] <= '9'){
//				temp = temp * 10 + (str[i] - 48);
//				i++;
//			}
//			i--;
//			pushNumber(numStack, temp);
//		}
//
//		
//		else{
//			op = str[i];
//			if (str[i] == '*' && str[i + 1] == '*')
//			{
//				i++;
//				op = '^';
//			}
//			
//			if (precedence(op) > precedence(opStack[topOp]))
//				pushOperator(opStack,op);
//			else{
//
//				while (precedence(op) <= precedence(opStack[topOp])){
//					operator1 = popOp(opStack);
//					b = popNum(numStack);
//					a = popNum(numStack);
//					value = eval(a, b, operator1);
//					pushNumber(numStack,value);
//				}
//				pushOperator(opStack, op);
//			}
//
//		}
//	}
//
//	while (topOp != -1){
//		operator1 = popOp(opStack);
//		b = popNum(numStack);
//		a = popNum(numStack);
//		value = eval(a, b, operator1);
//		pushNumber(numStack, value);
//	}
//
//
//	return popNum(numStack);
//}
//char *toStr(int x){
//	char *str = (char*)malloc(sizeof(char) * 20);
//	int len = 0,i;
//	int n = x;
//	while (n != 0){
//		len++;
//		n /= 10;
//	}
//	for ( i = 1; i <= len; i++)
//	{
//		str[len - i] = (x % 10) + '0';
//		x /= 10;
//	}
//
//	str[i - 1] = '\0';
//	return str;
//}
//
//int main(){
//
//	char * buff= (char*)malloc(sizeof(char)*255);
//	FILE *fp = fopen("SampleFile_ExpressionEvaluator.txt", "r+");
//	FILE *fp1 = fopen("SampleFile_ExpressionEvaluator.txt", "r+");
//	
//
//	while ((fgets(buff, 255, (FILE*)fp)) != NULL){
//		int x = evaluate(buff);
//		buff[strlen(buff) - 1] = '=';
//		strcat(buff, toStr(x));
//		
//		fprintf(fp1,"%s\n",buff);
//
//		printf("%s = %d\n",buff, x);
//	}
//	
//	_getch();
//	return 0;
//}