#include "stdio.h"

int main(void) {
	float elc, fee;
	scanf("%f", &elc);
	if (elc <= 110) {
		fee = 0.5 * elc;
	} else if (elc <= 210) {
		fee = 0.5 * 110 + 0.55 * (elc - 110);
	} else {
		fee = 0.5 * 110 + 0.55 * 100 + 0.7 * (elc - 210);
	}
	printf("%.2f", fee);
}