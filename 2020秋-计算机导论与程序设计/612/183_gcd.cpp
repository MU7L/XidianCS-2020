#include <stdio.h>

int main() {
	int m, n, A, a;
	scanf("%d %d", &m, &n);
	if (m < n) {
		a = m;
	} else {
		a = n;
	}
	while (m % a != 0 || n % a != 0) {
		a--;
	}
	A = m * n / a;
	printf("%d %d", a, A);
	return 0;
}