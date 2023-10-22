#include "stdio.h"

int main(void) {
	int n;
	scanf("%d", &n);
	int a[100];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int b[100];
	int j = 0;
	for (i = 0; i < n; i += 2) {
		b[j++] = a[i];
	}
	for (i = 1; i < n; i += 2) {
		b[j++] = a[i];
	}
	for (j = 0; j < n; j++) {
		printf("%d ", b[j]);
	}
}