#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int readerlen = 0, booklen = 0; //定义读者数量和书籍的种类


typedef struct BOOK { //书籍信息
	char booknum[200];//编号
	char bookname[200];//书名
	int bookamount;//数量
};

typedef struct READER { //读者信息
	char readernum[200];//编号
	char readername[200];//用户名
	int borrownum;//借阅书籍的数量，此处默认一个人同一种书只能借阅一本
	BOOK books[100];//借阅的书籍
};


BOOK book[200];
READER reader[200];//声明全局变量

FILE *readerlist;
FILE *booklist;
FILE *borrowlist;


void login();//登录界面
void adminmenu();//管理员菜单
void readermenu();//读者菜单
void addreader();//添加用户
void addbook();//添加书籍
void changebook();//修改书籍信息
void deletebook();//删除书籍信息
void inquire();//查询书籍信息
void traverse();//遍历所有书籍
void borrow();//借阅图书
void returnbook();//归还图书
void readbooklist();//读入图书列表
void readborrowlist();//读入借阅信息
void readreaderlist();//读入读者列表
void updatebooklist();//更新图书列表
void updatereaderlist();//更新读者列表
void updateborrowlist();//更新借阅信息


void readbooklist() { //读入图书列表
	booklist = fopen("booklist.txt", "r"); //打开只读文件
	while (fscanf(booklist, "%s%s%d\n", book[booklen].booknum, book[booklen].bookname, &book[booklen].bookamount) != EOF) {
		booklen++;//将文件中的信息读入书籍结构体
	}
	fclose(booklist);//关闭文件
}


void readreaderlist() { //读入读者列表
	//与读入图书列表相似
	readerlist = fopen("readerlist.txt", "r");
	while (fscanf(readerlist, "%s%s%d", reader[readerlen].readernum, reader[readerlen].readername,
	              &reader[readerlen].borrownum) != EOF) {
		readerlen++;
	}
	fclose(readerlist);
}


void readborrowlist() { //读入借阅信息
	for (int i = 0; i < readerlen; i++) {
		reader[i].borrownum = 0;
		for (int j = 0; j < 100; j++) {
			memset(&reader[i].books[j].booknum, 0, sizeof(reader[i].books[j].booknum));
			memset(&reader[i].books[j].bookname, 0, sizeof(reader[i].books[j].bookname));
			reader[i].books[j].bookamount = 0;
		}
	}//先将读者借阅书籍的信息初始化
	borrowlist = fopen("borrowlist.txt", "r");
	char bookname[200];
	char readername[200];
	while (fscanf(borrowlist, "%s%s\n", bookname, readername) != EOF) {
		//读入文件信息，思路类似上面的读入读者信息
		for (int i = 0; i < readerlen; i++) {
			if (strcmp(reader[i].readername, readername) == 0) {
				strcpy(reader[i].books[reader[i].borrownum].bookname, bookname);
				reader[i].borrownum++;
			}
		}
	}
	fclose(borrowlist);
}


void updatebooklist() { //更新图书列表
	booklist = fopen("booklist.txt", "w"); //打开只写文件
	for (int i = 0; i < booklen; i++) {
		//将结构体信息写入文件
		fprintf(booklist, "%s %s %d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
	}
	fclose(booklist);//关闭文件
}


void updatereaderlist() { //更新读者列表
	//同上
	readerlist = fopen("readerlist.txt", "w");
	for (int i = 0; i < readerlen; i++) {
		fprintf(readerlist, "%s %s %d\n", reader[i].readernum, reader[i].readername, reader[i].borrownum);
	}
	fclose(readerlist);
}


void updateborrowlist() { //更新借阅信息
	//同上
	borrowlist = fopen("borrowlist.txt", "w");
	for (int i = 0; i < readerlen; i++) {
		for (int j = 0; j < reader[i].borrownum; j++) {
			fprintf(borrowlist, "%s %s\n", reader[i].books[j].bookname, reader[i].readername);
		}
	}
	fclose(borrowlist);
}


void adminmenu() { //管理员菜单
	int a = 1;
	while (a) {
		//定义非零常量a，使其在未选择返回的情况下一直处于菜单页面
		int choice;
		printf("1.录入用户信息\n");
		printf("2.录入图书信息\n");
		printf("3.修改图书信息\n");
		printf("4.删除图书信息\n");
		printf("5.信息查询\n");
		printf("6.返回\n");
		printf("请选择你的操作：\n");
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
				break;//将非零常量a改为0，从而达到退出while循环的目的
		}
	}
}


void readermenu() { //用户菜单
	//思路基本和管理员菜单一致
	int a = 1;
	while (a) {
		int choice;
		printf("1.查询图书\n");
		printf("2.借阅图书\n");
		printf("3.归还图书\n");
		printf("4.返回\n");
		printf("请选择你的操作：\n");
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


void addreader() { //添加用户信息
	char str[10];
	int a = readerlen, i;
	system("cls");
	printf("请输入你要添加的用户编号\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if (strcmp(str, reader[i].readernum) == 0) {
			printf("该编号已被使用！\n");
			return;
		}
	}//添加用户信息的时候要注意是否重复
	if (a < 200) {
		//如果不重复，且不超过定义的最多用户数量，则可以进行添加
		strcpy(reader[a].readernum, str);
		printf("请输入该用户的用户名\n");
		scanf("%s", reader[a].readername);
		reader[a].borrownum = 0;
		for (int j = 0; j < reader[a].borrownum; j++) {
			memset(&reader[a].books[j].booknum, 0, sizeof(reader[a].books[j].booknum));
			memset(&reader[a].books[j].bookname, 0, sizeof(reader[a].books[j].bookname));
			reader[a].books[j].bookamount = 0;
		}
		printf("添加成功！\n");
		readerlen++;//读者数量要相应地进行更新
	}
	return;
}


void addbook() { //添加图书信息
	//思路同添加用户函数
	char str[10];
	int a = booklen, i;
	system("cls");
	printf("请输入你要添加的图书编号\n");
	scanf("%s", str);
	for (i = 0; i < booklen; i++) {
		if (strcmp(str, book[i].booknum) == 0) {
			printf("该编号已被使用！\n");
			return;
		}
	}
	if (a < 100) {
		strcpy(book[a].booknum, str);
		printf("请输入该书籍的书名\n");
		scanf("%s", book[a].bookname);
		printf("请输入该书籍的数量\n");
		scanf("%d", &book[a].bookamount);
		printf("添加成功！\n");
		booklen++;
	}
	return;
}


void changebook() { //修改图书信息
	//通过重新输入要修改的变量进行修改
	int i, choice, a = booklen;
	char num[10];
	system("cls");
	printf("请输入您要修改的图书编号\n");
	scanf("%s", num);
	for (i = 0; i < a; i++) {
		if (strcmp(book[i].booknum, num) == 0) {
			printf("编号：%s，书名：%s，数量：%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
			//打印对应编号书籍的信息，然后根据提示进行修改
			printf("请选择您要修改的内容\n");
			printf("1.编号\n");
			printf("2.书名\n");
			printf("3.数量\n");
			scanf("%d", &choice);
			switch (choice) {
				case 1: {
					printf("请输入新的编号\n");
					scanf("%s", book[i].booknum);
					break;
				}
				case 2: {
					printf("请输入新的书名\n");
					scanf("%s", book[i].bookname);
					break;
				}
				case 3: {
					printf("请输入新的数量\n");
					scanf("%d", &book[i].bookamount);
					break;
				}
			}
		}
	}
	return;
}


void deletebook() { //删除已有图书
	/*删除函数的思路就是通过寻找要删除的书籍，然后将其后面的书籍前移
	同时注意原来的最后一本书的信息要进行清空*/
	int i, j, a = booklen;
	char str[10];
	system("cls");
	printf("请输入您想要删除的图书编号\n");
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
	printf("删除成功！\n");
	booklen--;//图书种类进行更新
}


void inquire() { //查询图书信息
	char str[10];
	int i, j, a = booklen, b = readerlen;
	system("cls");
	printf("请输入您要查询的图书编号或书名\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		//对现有图书一一进行匹配，匹配成功后输出该书籍信息
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			printf("该图书编号：%s，书名：%s，数量：%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
			for (j = 0; j < b; j++) {
				if (strcmp(reader[j].books[reader[j].borrownum].bookname, book[i].bookname) == 0) {
					//输出借阅该书籍的读者的用户名
					printf("%s借阅了该书籍\n", reader[j].readername);
				}
			}
			return;
		}
	}
	printf("未找到该书籍，即将返回！\n");
	return;
}


void traverse() { //遍历图书信息
	int i, a = booklen;
	system("cls");
	for (i = 0; i < a; i++) {
		//将所有图书信息输出，方便读者借阅
		printf("图书编号：%s,书名：%s,数量：%d\n", book[i].booknum, book[i].bookname, book[i].bookamount);
	}
}


void borrow() { //借阅图书
	char str[10], s[10];
	int a = booklen, i, j, b = readerlen;
	system("cls");
	printf("请输入您的用户编号或用户名\n");
	scanf("%s", s);
	for (j = 0; j < b; j++) {
		if ((strcmp(reader[j].readernum, s) == 0) || (strcmp(reader[j].readername, s) == 0)) {
			break;
		}
	}
	printf("请输入你要借阅图书的编号或书名\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			if (book[i].bookamount > 0) {
				book[i].bookamount--;//借阅成功后注意将该书的数量进行相应更新
				reader[j].books[reader[j].borrownum] = book[i]; //将该书信息传入读者借阅书籍部分
				reader[j].books[reader[j].borrownum].bookamount++;
				reader[j].borrownum++;
				printf("借阅成功！\n");
			} else {
				printf("该书籍库存量不足，请以后再尝试\n");//注意借阅前提是库存量大于0
			}
			return;
		}
	}
	printf("未找到该书籍，即将返回！\n");
	return;
}


void returnbook() { //归还图书
	//思路和借书的情况差不多
	char s[10], str[10];
	int a = booklen, b = readerlen, i, j, k, m;
	system("cls");
	printf("请输入您的用户编号或用户名\n");
	scanf("%s", s);
	for (j = 0; j < b; j++) {
		if ((strcmp(reader[j].readernum, s) == 0) || (strcmp(reader[j].readername, s) == 0)) {
			break;
		}
	}
	printf("请输入你要归还图书的编号或书名\n");
	scanf("%s", str);
	for (i = 0; i < a; i++) {
		if ((strcmp(book[i].booknum, str) == 0) || (strcmp(book[i].bookname, str) == 0)) {
			book[i].bookamount++;//书籍库存量更新
			for (k = 0; k < reader[j].borrownum; k++) {
				if ((strcmp(reader[j].books[k].booknum, str) == 0) || (strcmp(reader[j].books[k].bookname, str) == 0)) {
					break;
				}
			}
			printf("归还成功！\n");
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
	printf("未找到该书籍，即将返回！\n");
	return;
}


int main(int argc, char *argv[]) {
	readbooklist();
	readreaderlist();
	readborrowlist(); //读入三个已建立的文件信息
	if ((strcmp(argv[1], "-a") == 0) && (strcmp(argv[2], "123456") == 0)) {
		adminmenu();
		updatebooklist();
		updatereaderlist();
		updateborrowlist();//更新文件信息
	} else if ((strcmp(argv[1], "-u") == 0) && (strcmp(argv[2], "666") == 0)) {

		readermenu();
		updatebooklist();
		updatereaderlist();
		updateborrowlist();//更新文件信息
	}
	return 0;
}