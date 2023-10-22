#include "stdio.h"
#include "stdlib.h"

int main(void) {
	char str[100] = {0}, num[100] = {0};
	gets(str);
	char *ps = str, *pn = num;
	while (*ps) {
		if (*ps >= '0' && *ps <= '9') {
			*pn++ = *ps;
		}
		ps++;
	}
	int n;
	n = atoi(num); //?
	int is = 0;
	for (int i = n / 2; i > 0; i--) {
		if (n % i == 0) {
			is = 1;
			printf("%d", i);
			break;
		}
	}
	if (is == 0) {
		printf("0");
	}
}