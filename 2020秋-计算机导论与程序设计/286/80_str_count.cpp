#include "stdio.h"
#include "string.h"
#include "ctype.h"

/*标题
字符统计

类别
字符串处理

时间限制
1S

内存限制
256Kb

问题描述
给出一个字符C和一行文字S，统计在这行文字S中字符C出现的次数。
程序还需要支持大小写敏感选项：
  当选项打开时，表示同一个字母的大写和小写看作不同的字符；
  当选项关闭时，表示同一个字母的大写和小写看作相同的字符。

输入说明
输入数据由两行构成。
第一行包含一个字符C和一个数字n。字符C为大小或小写英文字母。数字n表示大小写敏感选项，
	当数字n为0时表示大小写不敏感，
	当数字n为1时表示大小写敏感。
	字符C和数字n之间用空格分隔。
第二行为一个字符串S，字符串由大小写英文字母组成，不含空格和其他字符。字符串S长度不超过100。

输出说明
输出字符C在字符串S中出现的次数。

输入样例
样例1输入
L 1
HELLOWorld
样例2输入
L 0
HELLOWorld

输出样例
样例1输出
2
样例2输出
3
*/

int main(void) {
	char str[100] = {0};
	char c;
	int n;
	scanf("%c %d", &c, &n);
	getchar();
	gets(str);
	if (n == 0) {
		c = tolower(c);
		strlwr(str);
	}
	char *p = str;
	int t = 0;
	while (*p != '\0') {
		if (*p == c) {
			t++;
		}
		p++;
	}
	printf("%d", t);
}