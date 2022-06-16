#include "TitleInfo.h"

TitleInfo::TitleInfo(){}

void TitleInfo::setIsbn(string _isbn) {
	isbn = _isbn;
}
string TitleInfo::getIsbn() {
	return isbn;
}

void TitleInfo::setBookTitle(string _bookTitle) {
	bookTitle = _bookTitle;
}
string TitleInfo::getBookTitle() {
	return bookTitle;
}

void TitleInfo::setAuthor(string _author) {
	author = _author;
}
string TitleInfo::getAuthor() {
	return author;
}

void TitleInfo::setPublisher(string _publisher) {
	publisher = _publisher;
}
string TitleInfo::getPublisher() {
	return publisher;
}
void TitleInfo::setDataAdded(string _dataAdded) {
	dataAdded = _dataAdded;
}
string TitleInfo::getDataAdded() {
	return dataAdded;
}

void TitleInfo::setQtyOnHand(int _qtyOnHand) {
	qtyOnHand = _qtyOnHand;
}
int TitleInfo::getQtyOnHand() {
	return qtyOnHand;
}

void TitleInfo::setWholesale(int _wholesale) {
	wholesale = _wholesale;
}
int TitleInfo::getWholesale() {
	return wholesale;
}

void TitleInfo::setRetail(int _retail) {
	retail = _retail;
}
int TitleInfo::getRetail() {
	return retail;
}

void TitleInfo::toString() {
	cout << " 书代码编号：" << isbn << " 书名：" << bookTitle << " 作者：" << author
		<< " 出版社名称：" << publisher << " 进书日期：" << dataAdded << " 库存量：" << qtyOnHand
		<< " 批发价：" << wholesale << " 零售价：" << retail << endl;
}