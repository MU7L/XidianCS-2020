#include "stdio.h"

int main() {
	int week, index, car, tail, res;
	scanf("%d %d %d", &week, &index, &car);
	//求尾号
	tail = car % 10;
	//判断星期
	if (week >= 6) { //未限制week范围？
		res = 0;
	}
	else {
		if (index < 200) { //低于200
			res = 0;
		}
		else if (index < 400) { //200-400
			if (week == 1) { //周一
				if (tail == 1 || tail == 6) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
			if (week == 2) { //周二
				if (tail == 2 || tail == 7) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
			if (week == 3) { //周三
				if (tail == 3 || tail == 8) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
			if (week == 4) { //周四
				if (tail == 4 || tail == 9) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
			if (week == 5) { //周五
				if (tail == 5 || tail == 0) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
		} else { //高于400
			if (week % 2 == 1) {
				if (tail % 2 == 1) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
			else {
				if (tail % 2 == 0) {
					res = 1;
				}
				else {
					res = 0;
				}
			}
		}
	}
	//输出
	printf("%d ", tail);
	switch (res) {
		case 1:
			printf("yes");
			break;
		case 0:
			printf("no");
			break;
	}
	return 0;
}