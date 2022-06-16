#include "Report.h"
#include "BookData.h"
#include "fileInteractive.h"
#include<algorithm>

void Report::menu() {
	int isFlag = -1;
	while (true) {
		cout << "\t\t\t\t\t1、书库列表" << endl;
		cout << "\t\t\t\t\t2、批发价列表" << endl;
		cout << "\t\t\t\t\t3、零售价列表" << endl;
		cout << "\t\t\t\t\t4、按书的数量列表" << endl;
		cout << "\t\t\t\t\t5、按书的价值额列表" << endl;
		cout << "\t\t\t\t\t6、按进书的日期列表" << endl;
		cout << "\t\t\t\t\t0、返回到主菜单" << endl;
		cout << "\t\t\t\t\t  请输入（0 ~ 7）:" << endl;
		cin >> isFlag;
		switch (isFlag)
		{
		case 1: {
			system("cls");
			libraryList();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			wholesalePriceList();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			retailPriceList();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			quantityList();
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			valuesList();
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			dataList();
			system("pause");
			system("cls");
			break;
		}
		case 0: {
			system("cls");
			return;
		}
		default:
			cout << "输入错误请重新输入" << endl;
			break;
		}
	}

}

// 书库列表
void Report::libraryList() {
	cout << "书库列表：" << endl << endl;
	BookData bookData;
	bookData.books = fileInteractive().readTxt();
	bookData.showInfoLibrary();
}

// 批发价列表
void Report::wholesalePriceList() {
	cout << "批发价列表：" << endl;
	cout << "书名" << " " << "批发价" << " " << "库存量" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getWholesale() << " " << book.getQtyOnHand() << endl << endl;

	}

}

// 零售价列表
void Report::retailPriceList() {
	cout << "零售价列表" << endl;
	cout << "书名" << " " << "零售价" << " " << "库存量" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getRetail() << " " << book.getQtyOnHand() << endl << endl;

	}
}

bool dataCmd(TitleInfo a, TitleInfo b) {
	if (a.getDataAdded() > b.getDataAdded()) {
		return true;
	}
	return false;
}

bool quantityCmd(TitleInfo a, TitleInfo b) {
	if (a.getQtyOnHand() > b.getQtyOnHand()) {
		return true;
	}
	return false;
}

bool valuesCmd(TitleInfo a, TitleInfo b) {
	if (a.getRetail() > b.getRetail()) {
		return true;
	}
	return false;
}
// 数量列表
void Report::quantityList() {
	sort(books.begin(), books.end(), quantityCmd);
	cout << "数量列表" << endl ;
	// 先对图书按库存量从多到少排序
	cout << "书名" << " " << "库存量" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getQtyOnHand() << endl << endl;
	}
}

// 价值列表
void Report::valuesList() {
	sort(books.begin(), books.end(), valuesCmd);
	cout << "价值列表" << endl << endl;
	// 系统先对图书按每本书的批发价总额从大到小进行排序
	cout << "书名" << " " << "零售价" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getRetail() << endl << endl;
	}

	

}

// 日期列表
void Report::dataList() {
	sort(books.begin(), books.end(), dataCmd);
	cout << "日期列表" << endl << endl;
	// 先对图书按入库日期进行排序
	cout << "书名" << " " << "日期" << endl << endl;
	for (auto book : books) {
		cout << book.getBookTitle() << " " << book.getDataAdded() << endl << endl;
	}
}