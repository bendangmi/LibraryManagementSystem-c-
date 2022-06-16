#include "Manage.h"
#include "fileInteractive.h"


Manage::Manage(){}

// 查找ISBN号
int Manage::lookUpIsbn(string _isbn) {
	int cc = 0;
	for (auto book : books) {
		
		if (book.getIsbn() == _isbn) {
			
			return cc;
		}
		cc++;
	}
	return -1;

}

// 查找图书(支持模糊查找)
void Manage::lookUpBook() {
	cout << "请输入待查询书的名字(支持模糊查询)" << endl;
	string bookName;
	cin >> bookName;
	int isEmpty = -1;
	string::size_type pos = 0;
	for (auto book : books) {
		if (book.getBookTitle().find(bookName, pos) != string::npos) {
			isEmpty = 1;
			book.toString();
			cout << endl;
		}
	}
	if (isEmpty == -1) {
		cout << "没有相关图书" << endl;
	}
}



// 增加图书
void Manage::createBook() {
	cout << "请输入图书ISBN号:" << endl;
	cin >> isbn;
	int cc = lookUpIsbn(isbn);
	if (cc != -1) {
		int someNum;
		cout << "ISBN编号已经存在, 请输入图书待存量" << endl;
		cin >> someNum;
		books[cc].setQtyOnHand(books[cc].getQtyOnHand() + someNum);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		return;
	}
		
	cout << "请输入书名：" << endl;
	cin >> bookTitle;

	cout << "请输入作者名：" << endl;
	cin >> author;

	cout << "请输入出版社名称：" << endl;
	cin >> publisher;

	cout << "请输入进书日期：" << endl;
	cin >> dataAdded;

	cout << "请输入库存量：" << endl;
	cin >> qtyOnHand;

	cout << "请输入该书批发价：" << endl;
	cin >> wholesale;

	cout << "请输入该书零售价：" << endl;
	cin >> retail;
	TitleInfo tmpBook(isbn, bookTitle, author, publisher, dataAdded, qtyOnHand, wholesale, retail);
	books.push_back(tmpBook);
	fileInteractive fileWite;
	fileWite.writeTxt(books);
}

// 更新图书
void Manage::updateBook() {
	string isbn;
	cout << "请输入更改书籍的ISBN号：" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		cout << "图书已找到！" << endl;

		cout << "请输入书名：" << endl;
		cin >> bookTitle;
		books[index].setBookTitle(bookTitle);

		cout << "请输入作者名：" << endl;
		cin >> author;
		books[index].setAuthor(author);

		cout << "请输入出版社名称：" << endl;
		cin >> publisher;
		books[index].setPublisher(publisher);

		cout << "请输入进书日期：" << endl;
		cin >> dataAdded;
		books[index].setDataAdded(dataAdded);

		cout << "请输入库存量：" << endl;
		cin >> qtyOnHand;
		books[index].setQtyOnHand(qtyOnHand);

		cout << "请输入该书批发价：" << endl;
		cin >> wholesale;
		books[index].setWholesale(wholesale);

		cout << "请输入该书零售价：" << endl;
		cin >> retail;
		books[index].setRetail(retail);

		cout << "图书信息已经更新" << endl;
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		books[index].toString();
		index = -1;
		return;
	}
	cout << "输入错误，ISBN号没找到！" << endl;

}

// 删除图书
void Manage::deleteBook() {
	string isbn;
	cout << "请输入删除图书的ISBN号：" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		books.erase(books.begin() + index);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		cout << "编号为：" << isbn << " 的图书已经删除！" << endl;
		index = -1;
		return;
	}

	cout << "输入错误，ISBN号没找到！" << endl;
}

// 减少图书
void Manage::deleteNumber(string _isbn) {
	string isbn;
	cout << "请输入删除图书的ISBN号：" << endl;
	cin >> isbn;
	index = lookUpIsbn(isbn);
	if (index != -1) {
		books[index].setQtyOnHand(books[index].getQtyOnHand() - 1);
		fileInteractive fileWite;
		fileWite.writeTxt(books);
		index = -1;
		return;
	}
	cout << "输入错误，ISBN号没找到！" << endl;
}

void Manage::menu() {
	int isFlag = -1;
	
	while (true) {
		cout << "\t\t\t\t\t1、查找图书信息" << endl;
		cout << "\t\t\t\t\t2、添加图书信息" << endl;
		cout << "\t\t\t\t\t3、修改图书信息" << endl;
		cout << "\t\t\t\t\t4、删除图书信息" << endl;
		cout << "\t\t\t\t\t5、输出所有图书" << endl;
		cout << "\t\t\t\t\t0、返回到主菜单" << endl;
		cout << "\t\t\t\t\t  输入选择（0 ~ 4）:" << endl;
		cin >> isFlag;
		switch (isFlag) {
		case 1: {
			system("cls");
			lookUpBook();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			createBook();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			updateBook();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			deleteBook();
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			BookData bookData;
			bookData.books = fileInteractive().readTxt();
			bookData.showInfoLibrary();
			system("pause");
			system("cls");
			break;
			
		}
		case 0: {

			system("cls");
			return;
		}
		default: {
			cout << "输入错误，请重新输入" << endl;
		}

		}
	}
}