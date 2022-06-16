#pragma once
#include "TitleInfo.h"
#include<string>
#include<vector>
#include<fstream>
class fileInteractive : public TitleInfo
{
public:
	// 数字转字符串
	 string numberToString(int num);

	// 持久化内存（栈中数据写入文件）
	 void writeTxt(vector <TitleInfo> books);

	// 图书初始化（从文件中读取数据）
	 vector <TitleInfo> readTxt();
};

