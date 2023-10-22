#include "stdio.h"

int GCD(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else{
		int i;
		if (a > b) 
			i = a;
		else
			i = b;
		for (; i > 0; i--) {
			if (a % i == 0 && b % i == 0) {
				return i;
			}
		}
	}
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", GCD(a, b));
	return 0;
}