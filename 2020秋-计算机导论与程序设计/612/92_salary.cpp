#include <stdio.h>

int main() {
	int sal, q, w, e, r, t, y;
	scanf("%d", &sal);
	q = sal / 100;
	sal = sal - q * 100;
	w = sal / 50;
	sal = sal - w * 50;
	e = sal / 20;
	sal = sal - e * 20;
	r = sal / 10;
	sal = sal - r * 10;
	t = sal / 5;
	y = sal - t * 5;
	printf("%d %d %d %d %d %d", q, w, e, r, t, y);
	return 0;
}