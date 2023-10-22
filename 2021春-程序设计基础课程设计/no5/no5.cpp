#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int readerlen = 0, booklen = 0; //��������������鼮������


typedef struct BOOK { //�鼮��Ϣ
	char booknum[200];//���
	char bookname[200];//����
	int bookamount;//����
};

typedef struct READER { //������Ϣ
	char readernum[200];//���
	char readername[200];//�û���
	int borrownum;//�����鼮���������˴�Ĭ��һ����ͬһ����ֻ�ܽ���һ��
	BOOK books[100];//���ĵ��鼮
};


BOOK book[200];
READER reader[200];//����ȫ�ֱ���

FILE *readerlist;
FILE *booklist;
FILE *borrowlist;


void login();//��¼����
void adminmenu();//����Ա�˵�
void readermenu();//���߲˵�
void addreader();//����û�
void addbook();//����鼮
void changebook();//�޸��鼮��Ϣ
void deletebook();//ɾ���鼮��Ϣ
void inquire();//��ѯ�鼮��Ϣ
void traverse();//���������鼮
void borrow();//����ͼ��
void returnbook();//�黹ͼ��
void readbooklist();//����ͼ���б�
void readborrowlist();//���������Ϣ
void readreaderlist();//��������б�
void updatebooklist();//����ͼ���б�
void updatereaderlist();//���¶����б�
void updateborrowlist();//���½�����Ϣ


void readbooklist() { //����ͼ���б�
	booklist = fopen("booklist.txt", "r"); //��ֻ���ļ�
	while (fscanf(booklist, "%s%s%d\n", book[booklen].booknum, book[booklen].bookname, &book[booklen].bookamount) != EOF) {
		booklen++;//���ļ��е���Ϣ�����鼮�ṹ��
	}
	fclose(booklist);//�ر��ļ�
}


void readreaderlist() { //��������б�
	//�����ͼ���б�����
	readerlist = fopen("readerlist.txt", "r");
	while (fscanf(readerlist, "%s%s%d", reader[readerlen].readernum, reader[readerlen].readername,
	              &reader[readerlen].borrownum) != EOF) {
		readerlen++;
	}
	fclose(readerlist);
}


void readborrowlist() { //���������Ϣ
	for (int i = 0; i < readerlen; i++) {
		reader[i].borrownum = 0;
		for (int j = 0; j < 100; j++) {
			memset(&reader[i].books[j].booknum, 0, sizeof(reader[i].books[j].booknum));
			memset(&reader[i].books[j].bookname, 0, sizeof(reader[i].books[j].bookname));
			reader[i].books[j].bookamount = 0;
		}
	}//�Ƚ����߽����鼮����Ϣ��ʼ��
	borrowlist = fopen("borrowlist.txt", "r");
	char bookname[200];
	char readername[200];
	while (fscanf(borrowlist, "%s%s\n", bookname, readername) != EOF) {
		//�����ļ���Ϣ��˼·��������Ķ��������Ϣ
		for (int i = 0; i < readerlen; i++) {
			if (strcmp(reader[i].readername, readername) == 0) {
				strcpy(reader[i].books[reader[i].borrownum].bookname, bookname);
				reader[i].borrownum++;
			}
		}
	}
	fclose(borrowlist);
}


void updatebooklist() { //����ͼ���б�
	booklist = fopen("booklist.txt", "w"); //��ֻд�ļ�
	for (int i = 0; i < booklen; i++) {
		//���ṹ����Ϣд���ļ�
		fprintf(booklist, "%s %s %d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
	}
	fclose(booklist);//�ر��ļ�
}


void updatereaderlist() { //���¶����б�
	//ͬ��
	readerlist = fopen("readerlist.txt", "w");
	for (int i = 0; i < readerlen; i++) {
		fprintf(readerlist, "%s %s %d\n", reader[i].readernum, reader[i].readername, reader[i].borrownum);
	}
	fclose(readerlist);
}


void updateborrowlist() { //���½�����Ϣ
	//ͬ��
	borrowlist = fopen("borrowlist.txt", "w");
	for (int i = 0; i < readerlen; i++) {
		for (int j = 0; j < reader[i].borrownum; j++) {
			fprintf(borrowlist, "%s %s\n", reader[i].books[j].bookname, reader[i].readername);
		}
	}
	fclose(borrowlist);
}


void adminmenu() { //����Ա�˵�
	int a = 1;
	while (a) {
		//������㳣��a��ʹ����δѡ�񷵻ص������һֱ���ڲ˵�ҳ��
		int choice;
		printf("1.¼���û���Ϣ\n");
		printf("2.¼��ͼ����Ϣ\n");
		printf("3.�޸�ͼ����Ϣ\n");
		printf("4.ɾ��ͼ����Ϣ\n");
		printf("5.��Ϣ��ѯ\n");
		printf("6.����\n");
		printf("��ѡ����Ĳ�����\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				addreader();
				break;
			case 2:
				addbook();
				break;
			case 3:
				changebook();
				break;
			case 4:
				deletebook();
				break;
			case 5:
				inquire();
				break;
			case 6:
				a = 0;
				break;//�����㳣��a��Ϊ0���Ӷ��ﵽ�˳�whileѭ����Ŀ��
		}
	}
}


void readermenu() { //�û��˵�
	//˼·�����͹���Ա�˵�һ��
	int a = 1;
	while (a) {
		int choice;
		printf("1.��ѯͼ��\n");
		printf("2.����ͼ��\n");
		printf("3.�黹ͼ��\n");
		printf("4.����\n");
		printf("��ѡ����Ĳ�����\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				traverse();
				break;
			case 2:
				borrow();
				break;
			case 3:
				returnbook();
				break;
			case 4:
				a = 0;
				break;
		}
	}
}


void addreader() { //����û���Ϣ
	char str[10];
	int a = readerlen, i;
	system("cls");
	printf("��������Ҫ��ӵ��û����\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if (strcmp(str, reader[i].readernum) == 0) {
			printf("�ñ���ѱ�ʹ�ã�\n");
			return;
		}
	}//����û���Ϣ��ʱ��Ҫע���Ƿ��ظ�
	if (a < 200) {
		//������ظ����Ҳ��������������û�����������Խ������
		strcpy(reader[a].readernum, str);
		printf("��������û����û���\n");
		scanf("%s", reader[a].readername);
		reader[a].borrownum = 0;
		for (int j = 0; j < reader[a].borrownum; j++) {
			memset(&reader[a].books[j].booknum, 0, sizeof(reader[a].books[j].booknum));
			memset(&reader[a].books[j].bookname, 0, sizeof(reader[a].books[j].bookname));
			reader[a].books[j].bookamount = 0;
		}
		printf("��ӳɹ���\n");
		readerlen++;//��������Ҫ��Ӧ�ؽ��и���
	}
	return;
}


void addbook() { //���ͼ����Ϣ
	//˼·ͬ����û�����
	char str[10];
	int a = booklen, i;
	system("cls");
	printf("��������Ҫ��ӵ�ͼ����\n");
	scanf("%s", str);
	for (i = 0; i < booklen; i++) {
		if (strcmp(str, book[i].booknum) == 0) {
			printf("�ñ���ѱ�ʹ�ã�\n");
			return;
		}
	}
	if (a < 100) {
		strcpy(book[a].booknum, str);
		printf("��������鼮������\n");
		scanf("%s", book[a].bookname);
		printf("��������鼮������\n");
		scanf("%d", &book[a].bookamount);
		printf("��ӳɹ���\n");
		booklen++;
	}
	return;
}


void changebook() { //�޸�ͼ����Ϣ
	//ͨ����������Ҫ�޸ĵı��������޸�
	int i, choice, a = booklen;
	char num[10];
	system("cls");
	printf("��������Ҫ�޸ĵ�ͼ����\n");
	scanf("%s", num);
	for (i = 0; i < a; i++) {
		if (strcmp(book[i].booknum, num) == 0) {
			printf("��ţ�%s��������%s��������%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
			//��ӡ��Ӧ����鼮����Ϣ��Ȼ�������ʾ�����޸�
			printf("��ѡ����Ҫ�޸ĵ�����\n");
			printf("1.���\n");
			printf("2.����\n");
			printf("3.����\n");
			scanf("%d", &choice);
			switch (choice) {
				case 1: {
					printf("�������µı��\n");
					scanf("%s", book[i].booknum);
					break;
				}
				case 2: {
					printf("�������µ�����\n");
					scanf("%s", book[i].bookname);
					break;
				}
				case 3: {
					printf("�������µ�����\n");
					scanf("%d", &book[i].bookamount);
					break;
				}
			}
		}
	}
	return;
}


void deletebook() { //ɾ������ͼ��
	/*ɾ��������˼·����ͨ��Ѱ��Ҫɾ�����鼮��Ȼ���������鼮ǰ��
	ͬʱע��ԭ�������һ�������ϢҪ�������*/
	int i, j, a = booklen;
	char str[10];
	system("cls");
	printf("����������Ҫɾ����ͼ����\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if (strcmp(book[i].booknum, str) == 0) {
			for (j = i; j < a; j++) {
				book[j] = book[j + 1];
			}
		}
	}
	memset(book[a].bookname, 0, sizeof(book[a].bookname));
	memset(book[a].booknum, 0, sizeof(book[a].booknum));
	book[a].bookamount = 0;
	printf("ɾ���ɹ���\n");
	booklen--;//ͼ��������и���
}


void inquire() { //��ѯͼ����Ϣ
	char str[10];
	int i, j, a = booklen, b = readerlen;
	system("cls");
	printf("��������Ҫ��ѯ��ͼ���Ż�����\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		//������ͼ��һһ����ƥ�䣬ƥ��ɹ���������鼮��Ϣ
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			printf("��ͼ���ţ�%s��������%s��������%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
			for (j = 0; j < b; j++) {
				if (strcmp(reader[j].books[reader[j].borrownum].bookname, book[i].bookname) == 0) {
					//������ĸ��鼮�Ķ��ߵ��û���
					printf("%s�����˸��鼮\n", reader[j].readername);
				}
			}
			return;
		}
	}
	printf("δ�ҵ����鼮���������أ�\n");
	return;
}


void traverse() { //����ͼ����Ϣ
	int i, a = booklen;
	system("cls");
	for (i = 0; i < a; i++) {
		//������ͼ����Ϣ�����������߽���
		printf("ͼ���ţ�%s,������%s,������%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
	}
}


void borrow() { //����ͼ��
	char str[10], s[10];
	int a = booklen, i, j, b = readerlen;
	system("cls");
	printf("�����������û���Ż��û���\n");
	scanf("%s", s);
	for (j = 0; j < b; j++) {
		if ((strcmp(reader[j].readernum, s) == 0) || (strcmp(reader[j].readername, s) == 0)) {
			break;
		}
	}
	printf("��������Ҫ����ͼ��ı�Ż�����\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			if (book[i].bookamount > 0) {
				book[i].bookamount--;//���ĳɹ���ע�⽫���������������Ӧ����
				reader[j].books[reader[j].borrownum] = book[i]; //��������Ϣ������߽����鼮����
				reader[j].books[reader[j].borrownum].bookamount++;
				reader[j].borrownum++;
				printf("���ĳɹ���\n");
			} else {
				printf("���鼮��������㣬���Ժ��ٳ���\n");//ע�����ǰ���ǿ��������0
			}
			return;
		}
	}
	printf("δ�ҵ����鼮���������أ�\n");
	return;
}


void returnbook() { //�黹ͼ��
	//˼·�ͽ����������
	char s[10], str[10];
	int a = booklen, b = readerlen, i, j, k, m;
	system("cls");
	printf("�����������û���Ż��û���\n");
	scanf("%s", s);
	for (j = 0; j < b; j++) {
		if ((strcmp(reader[j].readernum, s) == 0) || (strcmp(reader[j].readername, s) == 0)) {
			break;
		}
	}
	printf("��������Ҫ�黹ͼ��ı�Ż�����\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			book[i].bookamount++;//�鼮���������
			for (k = 0; k < reader[j].borrownum; k++) {
				if ((strcmp(reader[j].books[k].booknum, str) == 0) || (strcmp(reader[j].books[k].bookname, str) == 0)) {
					break;
				}
			}
			printf("�黹�ɹ���\n");
			for (m = k; m < reader[j].borrownum - 1; m++) {
				strcpy(reader[j].books[m].booknum, reader[j].books[m + 1].booknum);
				strcpy(reader[j].books[m].bookname, reader[j].books[m + 1].bookname);
				reader[j].books[m].bookamount = reader[j].books[m + 1].bookamount;
			}
			strcpy(reader[j].books[reader[j].borrownum].booknum, "\0");
			strcpy(reader[j].books[reader[j].borrownum].bookname, "\0");
			reader[j].books[reader[j].borrownum].bookamount--;
			reader[j].borrownum--;
			return;
		}
	}
	printf("δ�ҵ����鼮���������أ�\n");
	return;
}


int main(int argc, char *argv[]) {
	readbooklist();
	readreaderlist();
	readborrowlist(); //���������ѽ������ļ���Ϣ
	if ((strcmp(argv[1], "-a") == 0) && (strcmp(argv[2], "123456") == 0)) {
		adminmenu();
		updatebooklist();
		updatereaderlist();
		updateborrowlist();//�����ļ���Ϣ
	} else if ((strcmp(argv[1], "-u") == 0) && (strcmp(argv[2], "666") == 0)) {

		readermenu();
		updatebooklist();
		updatereaderlist();
		updateborrowlist();//�����ļ���Ϣ
	}
	return 0;
}