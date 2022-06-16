#pragma once
/**
* 进行销售管理
*/
#include "BookData.h"
#include "TitleInfo.h"
#include "Manage.h"
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
class Sale 
{
private:
	int totalSales = 0; // 销售合计
	int tetailTax = 0; // 零售税
	int amountPayable = 0; // 应付金额
	vector<TitleInfo>shopping;
	

public:
	// 存放书库中所有书的信息
	vector <TitleInfo> books;
	// 购买图书
	void shoppingBooks(string _isbn, int qty);

	void showInfo();

	void menu();

	
};

