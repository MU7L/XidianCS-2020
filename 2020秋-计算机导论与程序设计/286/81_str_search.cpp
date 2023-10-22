#include "stdio.h"
#include "string.h"

/*
标题
字符串查找

类别
字符串处理

时间限制
2S

内存限制
256Kb

问题描述
给出一个字符串和多行文字，输出在这些文字中出现了指定字符串的行。
程序还需要支持大小写敏感选项：
    当选项打开时，表示同一个字母的大写和小写看作不同的字符；
    当选项关闭时，表示同一个字母的大写和小写看作相同的字符。

输入说明
输入数据第一行包含一个字符串s，由大小写英文字母组成，长度不超过100。
第二行包含一个数字，表示大小写敏感选项。当数字为0时表示大小写不敏感，当数字为1时表示大小写敏感。
第三行包含一个整数n，表示给出的文字行数。
接下来n行，每行包含一个字符串，字符串由大小写英文字母组成，不含空格和其他字符。每个字符串长度不超过100。

输出说明
输出多行，每行包含一个字符串，按出现的顺序依次给出那些包含了字符串s的行。

输入样例
Hello
1
5
HelloWorld
HiHiHelloHiHi
GrepIsAGreatTool
HELLO
HELLOisNOTHello

输出样例
HelloWorld
HiHiHelloHiHi
HELLOisNOTHello
*/

int main(void) {
	char target[100] = {0}; //目标字符串
	int capital = 1; //敏感选项,默认开启
	int n;//整数行数
	char txt[100][100] = {0},txtcpy[100][100]={0};
	gets(target);
	scanf("%d", &capital);
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		gets(txt[i]);
		strcpy(txtcpy[i],txt[i]);
	}

	if (capital == 0) { //敏感关闭
		strlwr(target);
		for (int i = 0; i <= n; i++) {
			strlwr(txtcpy[i]);
		}
	}

	for (int i = 0; i <= n; i++) {
		if (strstr(txtcpy[i], target) != NULL) {
			puts(txt[i]);
		}
	}
}