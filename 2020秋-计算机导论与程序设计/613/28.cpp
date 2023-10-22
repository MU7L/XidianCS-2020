#include "stdio.h"

int main() {
	int a, b, day;
	scanf("%d %d", &a, &b);

	int is;
	if (a % 400 == 0) {
		is = 1;
	} else if (a % 4 == 0 && a % 100 != 0) {
		is = 1;
	} else {
		is = 0;
	}

	switch (b) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = 31;
			break;
		default:
			day = 30;
	}
	if (is == 1 && b == 2) {
		day = 29;
	}
	if (is == 0 && b == 2) {
		day = 28;
	}
	printf("%d", day);
	return 0;
}