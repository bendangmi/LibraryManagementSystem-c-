#pragma once
#include "TitleInfo.h"
#include "Sale.h"
#include<string>
#include<vector>
#include<fstream>
using namespace std;



class BookData :public TitleInfo
{
public:
	// 存放书库中所有书的信息
	vector <TitleInfo> books;

	// 将小写字母转换为大写字母
	static string strUpper(string s1);

	// 返回书库的种类总数量
	int sumTypeBook();

	// 返回书库中书的剩余总数量
	int sumBook();

	

	// 输出所有图书
	void showInfoLibrary();

};

