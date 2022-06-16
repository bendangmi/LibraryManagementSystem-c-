#pragma once
/**
* 显示图书详细信息
*/
#include<iostream>
#include "TitleInfo.h"
#include<vector>
using namespace std;
class Report
{
private:
	int isFlag = -1;
	
public:
	vector <TitleInfo> books;
	void menu();

	// 书库列表
	void libraryList();

	// 批发价列表
	void wholesalePriceList();

	// 零售价列表
	void retailPriceList();

	// 数量列表
	void quantityList();

	// 价值列表
	void valuesList();

	// 日期列表
	void dataList();




};

