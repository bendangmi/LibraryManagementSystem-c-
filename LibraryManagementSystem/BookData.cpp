#include "BookData.h"

// 将小写字母转换为大写字母
string BookData:: strUpper(string s1) {
	string upper = "";
	for (int i = 0; i < s1.size(); i++) {
		upper += toupper(s1[i]);
	}
	return upper;
}

// 返回书库的种类总数量
int BookData::sumTypeBook() {
	return int(books.size());
}

// 返回书库中书的剩余总数量
int BookData::sumBook() {
	int num = 0;
	for (auto book : books) {
		num += book.getQtyOnHand();
	}
	return num;
}


// 输出所有图书
void BookData::showInfoLibrary() {
	cout << "图书代码编号" << " " << "书名" << " " << "作者" << " " << "出版社" << " " << "进书日期" << "库存量" << " " << "批发价" << " " << "零售价" << endl << endl;

	for (auto book : books) {
		cout << book.getIsbn() << " " <<book.getBookTitle() << " " << book.getAuthor()
			<< " " << book.getPublisher() << " " <<book.getDataAdded() << " " << book.getQtyOnHand()
			<< " " << book.getWholesale() << " " <<book.getRetail()  << endl;

		cout << endl;
	}
}