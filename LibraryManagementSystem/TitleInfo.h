#pragma once
/**
* 用于保存图书的基本信息，
* 主要包含书名、出版社、ISBN号、作者等，
* 以及针对这些数据成员的一些函数成员。
*/
#include<string>
#include<iostream>
using namespace std;
class TitleInfo
{
protected:
	string isbn; // 书的标准代码
	string bookTitle; // 书名
	string author; // 作者
	string publisher; // 出版社名称
	string dataAdded; // 进书日期
	int qtyOnHand; // 库存量
	int wholesale; // 批发价
	int retail; // 零售价

public:
	TitleInfo();
	
	TitleInfo(string _isbn, string _bookTitle, string _author, string _publisher, string _dataAdded, int _qtyOnhand, int _wholesale, int _retail) :
		isbn(_isbn), bookTitle(_bookTitle), author(_author), publisher(_publisher), dataAdded(_dataAdded), qtyOnHand(_qtyOnhand), wholesale(_wholesale), retail(_retail){}
	void setIsbn(string _isbn);

	string getIsbn() ;

	void setBookTitle(string _bookTitle);
	string getBookTitle();

	void setAuthor(string _author);
	string getAuthor();

	void setPublisher(string _publisher);
	string getPublisher();

	void setDataAdded(string _dataAdded);
	string getDataAdded();

	void setQtyOnHand(int _qtyOnHand);
	int getQtyOnHand();

	void setWholesale(int _wholesale);
	int getWholesale();

	void setRetail(int _retail);
	int getRetail();

	void toString();

};


