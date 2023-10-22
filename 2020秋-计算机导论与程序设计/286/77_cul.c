#include "stdio.h"
#include "stdlib.h"

/*
标题
表达式求值

类别
字符串处理

时间限制
1S

内存限制
256Kb

问题描述
表达式由两个非负整数x，y和一个运算符op构成，求表达式的值。
这两个整数和运算符的顺序是随机的，可能是”x op y”， “op x y”或者 “x y op”，例如，“25 + 3”表示25加3，“5 30 *” 表示5乘以30，“/ 600 15”表示600除以15。

输入说明
输入为一个表达式，表达式由两个非负整数x，y和一个运算符op构成，x，y和op之间以空格分隔，但顺序不确定。
x和y均不大于10000000，op可以是+，-,*，/，%中的任意一种，分表表示加法，减法，乘法，除法和求余。
除法按整数除法求值，输入数据保证除法和求余运算的y值不为0。

输出说明
输出表达式的值。

输入样例
样例1输入
5 20 *
样例2输入
4 + 8
样例3输入
/ 8 4

输出样例
样例1输出
100
样例2输出
12
样例3输出
2
*/

int main(void) {
	char str[100] = {0};
	gets(str);
	char *p = str;
	char op;
	char x[100] = {0}, y[100] = {0};
	int is = 0;
	while (*p != '\0') {
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%') {
			op = *p;
			p++;
		}
		else if (*p >= '0' && *p <= '9') {
			if (is == 0) {
				char *pn = x;
				while (*p >= '0' && *p <= '9') {
					*pn = *p;
					pn++;
					p++;
				}
				is = 1;
			}
			else {
				char *pn = y;
				while (*p >= '0' && *p <= '9') {
					*pn = *p;
					pn++;
					p++;
				}
			}
		}
		else {
			p++;
		}
	}
	int xn = atoi(x), yn = atoi(y), res;
	switch (op) {
		case '+':
			res = xn + yn;
			break;
		case '-':
			res = xn - yn;
			break;
		case '*':
			res = xn * yn;
			break;
		case '/':
			res = xn / yn;
			break;
		case '%':
			res = xn % yn;
			break;
	}
	printf("%d", res);
}