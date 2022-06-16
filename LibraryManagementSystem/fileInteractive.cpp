#include "fileInteractive.h"

// 数字转字符串
string fileInteractive::numberToString(int num) {
	string s1 = to_string(num);
	return s1;
}

// 持久化内存（栈中数据写入文件）
 void fileInteractive::writeTxt(vector <TitleInfo> books) {
	
	ofstream f;
	f.open("BookData.txt", ios::out);
	for (auto book : books) {
		string tmpWrite = "";
		tmpWrite += book.getIsbn() + " " + book.getBookTitle() + " " + book.getAuthor() + " " + book.getPublisher() + " "
			+ book.getDataAdded() + " " + numberToString(book.getQtyOnHand()) + " " + numberToString(book.getWholesale()) + " " + numberToString(book.getRetail());
		f << tmpWrite << endl;
	}
	f.close();
}

// 图书初始化（从文件中读取数据）
 vector <TitleInfo> fileInteractive::readTxt() {
	vector <TitleInfo> books;
	ifstream infile;
	infile.open("BookData.txt", ios::in);
	while (infile >> isbn >> bookTitle >> author >> publisher >> dataAdded >> qtyOnHand >> wholesale >> retail) {
		TitleInfo tmpBook;
		tmpBook.setIsbn(isbn);
		tmpBook.setBookTitle(bookTitle);
		tmpBook.setAuthor(author);
		tmpBook.setPublisher(publisher);
		tmpBook.setDataAdded(dataAdded);
		tmpBook.setQtyOnHand(qtyOnHand);
		tmpBook.setWholesale(wholesale);
		tmpBook.setRetail(retail);
		books.push_back(tmpBook);
	}
	infile.close();
	return books;
}
