#include "stdio.h"
#include "string.h"

int main(void) {
	char str[100] = {0}, track[100] = {0};
	gets(str);
	int i = 0, t = 0, is = 1,len=strlen(str);
	while (i<len) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			track[t++] = str[i];
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (str[i] == ')' && track[t-1] == '(') {
				goto deal;
			}
			else if (str[i] == ']' && track[t-1] == '[') {
				goto deal;
			}
			else if (str[i] == '}' && track[t-1] == '{') {
deal:
				track[--t]='\0';
				i++;
				continue;
			}
			else {
				is = 0;
				break;
			}
		}
		i++;
	}
	if (strcmp(track, "\0") != 0) {
		is = 0;
	}
	if (is == 1)
		printf("right");
	else
		printf("wrong");
}