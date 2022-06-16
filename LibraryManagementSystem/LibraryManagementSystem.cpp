#include<iostream>
#include "BookData.h"
#include "Manage.h"
#include "Report.h"
#include "Sale.h"
#include "fileInteractive.h"
using namespace std;

	int main() {
	int isFlag = -1;
	
	while (true) {
		cout << "\t\t\t\t\t图书管理系统" << endl;
		cout << "\t\t\t\t\t***主菜单***" << endl;
		cout << "\t\t\t\t\t1、收银模块" << endl;
		cout << "\t\t\t\t\t2、书库管理模块" << endl;
		cout << "\t\t\t\t\t3、报表模块" << endl;
		cout << "\t\t\t\t\t0、退出系统" << endl;
		cout << "\t\t\t\t\t  请选择（0 ~ 3）:" << endl;
		cin >> isFlag;
		switch (isFlag) {
		case 1: {
			system("cls");
			cout << "收银模块子菜单：" << endl;

			Sale sale;
			sale.books = fileInteractive().readTxt();
			sale.menu();
			break;
		}
		case 2: {
			system("cls");
			cout << "书库管理模块子菜单：" << endl;
			
			Manage man;
			man.books = fileInteractive().readTxt();
			man.menu();
			break;
		}
		case 3: {
			system("cls");
			cout << "报表模块子菜单：" << endl;

			Report report;
			report.books = fileInteractive().readTxt();
			report.menu();
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "输入错误请重新输入" << endl;
		}
		}
	}
	return 0;
}

