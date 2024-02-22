/*
* 作者：彭欣阳
* 学院：软件学院
* 学号：21375049
* 模块：杂项功能模块
*/
#pragma once
#include"StudentManagerSystem.h"
using namespace std;

//判断字符串是否为数字
bool isNumber(const string& s) {
	return std::ranges::all_of(s.begin(), s.end(),[](char c) { return isdigit(c) != 0; });
}

//判断学号是否合法,以本科生为例，有需要可以具体修改
bool judgeStudentId(string id) {
	return id.length() == 8 && isNumber(id);
}

//wchar_t*转char*
char* wchar_to_char(wchar_t* wChar) {
	int bufSize = WideCharToMultiByte(CP_ACP, NULL, wChar, -1, NULL, 0, NULL, FALSE);
	char* ch = new char[bufSize];
	WideCharToMultiByte(CP_ACP, NULL, wChar, -1, ch, bufSize, NULL, FALSE);
	return ch;
}

//wchar_t*转string
string wchar_to_string(wchar_t* wChar) {
	int bufSize = WideCharToMultiByte(CP_ACP, NULL, wChar, -1, NULL, 0, NULL, FALSE);
	char* ch = new char[bufSize];
	WideCharToMultiByte(CP_ACP, NULL, wChar, -1, ch, bufSize, NULL, FALSE);
	string str = string(ch, bufSize);
	delete[] ch;
	ch = nullptr;
	return str;
}

//读取时将utf8转为unicode
wchar_t* Utf8_2_Unicode(char* row_i) {
	int len = MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), NULL, 0);
	wchar_t* wszStr = new wchar_t[len + 1];
	MultiByteToWideChar(CP_UTF8, 0, row_i, strlen(row_i), wszStr, len);
	wszStr[len] = '\0';
	return wszStr;
}