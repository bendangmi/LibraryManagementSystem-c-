#pragma once
/**
* 对图书进行CRUD操作
*/
#include<iostream>
#include<string>
#include "TitleInfo.h"
#include "BookData.h" 
#include<vector>

using namespace std;

class Manage: public TitleInfo
{
private:
	int index;

public:
	vector <TitleInfo> books;
	// 查找ISBN号
	int lookUpIsbn(string _isbn);

	// 查找图书(支持模糊查找)
	void lookUpBook();

	// 增加图书
	void createBook();

	// 更新图书
	void updateBook();
		
	// 删除图书
	void deleteBook();

	// 减少图书
	void deleteNumber(string _isbn);



	void menu();

	Manage();


};

