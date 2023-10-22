#include <stdio.h>

int main() {
	int q, w, e, num, sum;
	scanf("%d", &num);
	q = (num / 100) % 10;
	w = (num / 10) % 10;
	e = num % 10;
	sum = q + w + e;
	printf("%d", sum);
	return 0;
}