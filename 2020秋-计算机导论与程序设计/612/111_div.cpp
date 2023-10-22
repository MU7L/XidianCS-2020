#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	if (x % 5 == 0 && x % 7 == 0)
		printf("yes");
	else
		printf("no");
	return 0;
}