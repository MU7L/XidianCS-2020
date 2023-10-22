
#include <stdio.h> 
#include <string.h>
 
int main() 
{
	char str[101];
	scanf("%s", str);
	int i, j, flag=1;//i记录周期长度,j记录从第二个周期开始字符的位置
	int len = strlen(str);//len为字符串长度
	for(i=1; i <= len; i++)
		if(len%i == 0)//字符串的长度一定可以被周期整除
		{
			flag = 1;
			//检测 字符串是否具有周期性
			for(j=i; j<len; j++)//str[i]为第二周期的第一个字符
			{
				if(str[j] != str[j%i])
				{
					flag = 0;
					break;
				}
			}
			if(flag)//找到周期跳出
				break;
		}
	printf("%d\n", i);
	return 0;
}
