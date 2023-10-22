#include <iostream>
using namespace std;

/*
模拟堆栈程序
*/

class Stack{
public:
	int element[1024] = {0};         //栈元素
	int top = -1;                    //栈顶

	void push() {                    //入栈
		cout << "请输入入栈元素：";
		int elmt;
		cin >> elmt;
		element[++top] = elmt;
	}
	void pop() {                     //出栈
		cout << element[top] << " 已出栈" << endl;
		element[top--] = 0;
	}
	int return_top() {               //返回栈顶元素
		return element[top];
	}
	void show_elmt() {               //展示所有元素
		cout << "[ ";
		for (int i = 0; i <= top; i++) {
			cout << element[i] << ",";
		}
		cout << "\b ]" << endl;
	}
};

/*菜单*/
int menu() {
	cout << "\n=====请选择栈操作=====" << endl
	     << "1.入栈" << endl
	     << "2.出栈" << endl
	     << "3.返回栈顶元素" << endl
	     << "0.退出" << endl
	     << "======================" << endl;
	int op;
	cin >> op;
	return op;
}

/*解天旭*/
int main(void) {
	cout << "模拟堆栈程序" << endl << endl;
	Stack s;
	int active = 1;                  //循环结束标志
	while (active) {
		cout << "当前栈元素个数为：" << s.top + 1 << endl;
		if (s.top != -1) {           //无元素时不打印栈
			cout << "显示如下：" << endl;
			s.show_elmt();
		}
		switch (menu()) {
			case 1:                  //入栈
				s.push();
				break;
			case 2: {                //出栈
				s.pop();
				system("pause");
				break;
			}
			case 3: {                //返回栈顶元素
				cout << "栈顶元素为：" << s.return_top() << endl;
				system("pause");
				break;
			}
			case 0:                  //退出
				active = 0;
				break;
			default:                 //其他
				cout << "输入错误，请重新输入" << endl;
				system("pause");
		}
		system("cls");
	}

	cout << "模拟堆栈程序已结束。" << endl;
	system("pause");
}