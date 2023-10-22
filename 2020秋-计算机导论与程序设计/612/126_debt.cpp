#include <stdio.h>
#include <math.h>

int main() {
	float d, p, r, m;
	scanf("%f %f %f", &d, &p, &r);
	m = (log(p) - log(p - d * r)) / log(1 + r);
	printf("%.2f", m);
	return 0;
}