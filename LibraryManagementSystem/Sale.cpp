#include "Sale.h"
#include "fileInteractive.h"
#include <time.h>
#include<windows.h>
// 显示购买信息

void Sale::showInfo() {

	cout << "日期：";
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "年" << sys.wMonth << "月" << sys.wDay << "日" << sys.wHour << "时" << sys.wMinute << "分" << sys.wSecond << "秒" << endl;
	cout << endl;
	cout << "数量" << " " << "ISBN号" << " " << "书名" << " 单价 " << "金额" << endl;
	for (auto book : shopping) {
		cout << book.getQtyOnHand() << " " << book.getIsbn() << " "
			<< book.getBookTitle() << " " << book.getRetail() << " "
			<< book.getWholesale() << endl;
	}
	for (int i = 0; i < 80; i++) cout << "*";
	cout << endl;
	cout << "销售合计：" << "RMB " << totalSales << endl;
	cout << "零售税：" << "RMB " << tetailTax << endl;
	cout << "应付总额：" << "RMB " << amountPayable << endl;
}


// 购买图书
void Sale::shoppingBooks(string _isbn, int qty) {
	Manage manage;
	manage.books = fileInteractive().readTxt();
	int index = manage.lookUpIsbn(_isbn);
	if (index != -1) {
		if (books[index].getQtyOnHand() >= qty) {
			TitleInfo tmpbook = manage.books[index];
			tmpbook.setQtyOnHand(qty);
			manage.books[index].setQtyOnHand(manage.books[index].getQtyOnHand() - qty);
			shopping.push_back(tmpbook);
			totalSales += tmpbook.getRetail() * qty;
			tetailTax += 2 * qty;
			amountPayable = totalSales + tetailTax;
			fileInteractive fileWite;
			fileWite.writeTxt(manage.books);

			cout << "购买成功！" << endl;
			
		}
		else {
			cout << "购买失败，书库数量不足" << endl;
		}
	}
	else {
		cout << "购买失败！查无此图书编号" << endl;
	}
	
	
}

void Sale::menu() {
	int isFlag = -1;
	while (true) {
		cout << "\t\t\t\t\t1、查找图书" << endl;
		cout << "\t\t\t\t\t2、购买图书" << endl;
		cout << "\t\t\t\t\t3、已购买图书" << endl;
		cout << "\t\t\t\t\t0、退出购买" << endl;
		cout << "\t\t\t\t\t  请输入（0 ~ 2）:" << endl;
		cin >> isFlag;
		switch (isFlag) {
		case 3: {
			system("cls");
			showInfo();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			string isbn;
			int qty;
			cout << "请输入购买图书编号" << endl;
			cin >> isbn;
			cout << "请输入购买数量" << endl;
			cin >> qty;
			shoppingBooks(isbn, qty);
			system("pause");
			system("cls");
			break;
		}
		case 1: {
			  system("cls");
			  Manage bookData;
			  bookData.books = fileInteractive().readTxt();
			  bookData.lookUpBook();
			  system("pause");
			  system("cls");
			  break;
		}
		case 0: {
			
			
			system("cls");
			return;
		}
		default: {
			system("cls");
			cout << "输入错误，请重新输入" << endl;
		}
		}
	}
}