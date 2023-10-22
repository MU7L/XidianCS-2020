#include "stdio.h"
#include "stdlib.h"
#include "cstring"

int main(void) {
	char str[100] = {0}, num[10] = {0};
	gets(str);
	char *ps = str;
	int n[10] = {0};
	int len = 0;
	while (*ps) {
		memset(num, '\0', 10);
		char *pn = num;
		int is = 0;
		while (*ps >= '0' && *ps <= '9') {
			is = 1;
			*pn++ = *ps++;
		}
		ps++;
		if (is == 1) {
			n[len++] = atoi(num);
		}
	}
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (n[i] < n[j]) {
				int temp = n[i];
				n[i] = n[j];
				n[j] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", n[i]);
	}
}