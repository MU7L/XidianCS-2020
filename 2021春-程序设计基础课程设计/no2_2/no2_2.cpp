#include <iostream>
using namespace std;

/*
ģ���ջ����
*/

class Stack{
public:
	int element[1024] = {0};         //ջԪ��
	int top = -1;                    //ջ��

	void push() {                    //��ջ
		cout << "��������ջԪ�أ�";
		int elmt;
		cin >> elmt;
		element[++top] = elmt;
	}
	void pop() {                     //��ջ
		cout << element[top] << " �ѳ�ջ" << endl;
		element[top--] = 0;
	}
	int return_top() {               //����ջ��Ԫ��
		return element[top];
	}
	void show_elmt() {               //չʾ����Ԫ��
		cout << "[ ";
		for (int i = 0; i <= top; i++) {
			cout << element[i] << ",";
		}
		cout << "\b ]" << endl;
	}
};

/*�˵�*/
int menu() {
	cout << "\n=====��ѡ��ջ����=====" << endl
	     << "1.��ջ" << endl
	     << "2.��ջ" << endl
	     << "3.����ջ��Ԫ��" << endl
	     << "0.�˳�" << endl
	     << "======================" << endl;
	int op;
	cin >> op;
	return op;
}

/*������*/
int main(void) {
	cout << "ģ���ջ����" << endl << endl;
	Stack s;
	int active = 1;                  //ѭ��������־
	while (active) {
		cout << "��ǰջԪ�ظ���Ϊ��" << s.top + 1 << endl;
		if (s.top != -1) {           //��Ԫ��ʱ����ӡջ
			cout << "��ʾ���£�" << endl;
			s.show_elmt();
		}
		switch (menu()) {
			case 1:                  //��ջ
				s.push();
				break;
			case 2: {                //��ջ
				s.pop();
				system("pause");
				break;
			}
			case 3: {                //����ջ��Ԫ��
				cout << "ջ��Ԫ��Ϊ��" << s.return_top() << endl;
				system("pause");
				break;
			}
			case 0:                  //�˳�
				active = 0;
				break;
			default:                 //����
				cout << "�����������������" << endl;
				system("pause");
		}
		system("cls");
	}

	cout << "ģ���ջ�����ѽ�����" << endl;
	system("pause");
}